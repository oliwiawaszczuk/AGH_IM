import os
import pathlib
from PIL import Image, ImageDraw

from PyQt5.QtCore import QRect, QSize, Qt, QPoint
from PyQt5.QtGui import QPainter, QPixmap, QIcon, QColor, QPen
from PyQt5.QtWidgets import QMainWindow, QPushButton, QLabel, QLineEdit, QWidget, QVBoxLayout, QScrollArea, \
    QGridLayout, QHBoxLayout

import const
from Classes.Car import Car


class AddNewCarToQueueScreen(QMainWindow):
    def __init__(self, window_position, window_size: QRect, add_window_size: QRect, queue_list):
        super().__init__()
        self.setWindowTitle('Add new car to queue')
        self.setGeometry(window_size)
        self.window_size = window_size
        self.add_window_size = add_window_size
        self.new_car_window = None
        self.queue_list = queue_list

    def set_queue_screen(self, queue):
        self.queue_window = queue

    def paintEvent(self, event):
        # painter = QPainter(self)
        button = QPushButton("Stworz nowy samochod do kolejki", self)
        button.setGeometry(0, 0, self.window_size.width(), self.window_size.height())
        button.clicked.connect(self.add_new)
        button.show()
        # painter.fillRect(event.rect(), Colors.bg_color)

    def add_new(self):
        if self.new_car_window is None:
            self.new_car_window = NewCarWindow(self.add_window_size, self.queue_list, self.queue_window, self)
            self.new_car_window.show()


class NewCarWindow(QMainWindow):
    def __init__(self, add_window_size: QRect, queue_list, queue_window, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Nowy samochód")
        self.setGeometry(add_window_size)
        self.add_window_size = add_window_size
        self.queue_window = queue_window

        self.queue_list = queue_list

        label = QLabel("Numer rejestracyjny:", self)
        label.setGeometry(10, 10, 200, 30)
        label.show()

        self.tablica_rejestracyjna_text_input = QLineEdit(self)
        self.tablica_rejestracyjna_text_input.setGeometry(10, 50, add_window_size.width() - 20, 30)
        self.tablica_rejestracyjna_text_input.show()

        button_width = add_window_size.width() // 2 - 20
        button_height = 40
        button_y = add_window_size.height() - button_height - 20

        photo_button = QPushButton("Wybierz zdjęcie", self)
        photo_button.setGeometry(10, 100, 150, 30)
        photo_button.clicked.connect(self.pick_photo)
        photo_button.show()

        self.photo_path = QLabel("Nie wybrano zdjęcia", self)
        self.photo_path.setGeometry(170, 100, 300, 30)
        self.photo_path.show()

        cancel_button = QPushButton("Anuluj", self)
        cancel_button.setGeometry(10, button_y, button_width, button_height)
        cancel_button.clicked.connect(self.close_window)

        add_button = QPushButton("Dodaj", self)
        add_button.setGeometry(button_width + 30, button_y, button_width, button_height)
        add_button.clicked.connect(self.add_car)

        cancel_button.show()
        add_button.show()

    def pick_photo(self):
        picker = ImagePickerWindow(const.PATH_TO_IMAGES, self.add_window_size, self)
        picker.show()

    def set_photo_path(self, path):
        self.photo_path.setText(path)

    def close_window(self):
        self.close()
        self.parent().new_car_window = None

    def add_car(self):
        if self.tablica_rejestracyjna_text_input.text().strip() != "" and self.photo_path.text() != "Nie wybrano zdjęcia":
            path_to_image = self.photo_path.text()
            self.queue_list.add_car_to_queue(Car(0, self.tablica_rejestracyjna_text_input.text(), path_to_image))
            self.parent().new_car_window = None
            self.queue_window.refresh_view()
            self.close()


class ImagePickerWindow(QMainWindow):
    def __init__(self, folder_path, window_size, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Wybierz obraz")
        self.setGeometry(window_size)
        self.path = parent

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        self.scroll_area = QScrollArea()
        self.scroll_area_widget = QWidget()
        self.scroll_layout = QGridLayout(self.scroll_area_widget)
        self.scroll_area.setWidgetResizable(True)
        self.scroll_area.setWidget(self.scroll_area_widget)

        self.layout.addWidget(self.scroll_area)

        self.selected_image = None
        self.folder_path = folder_path
        self.load_images(self.folder_path)
        self.custom_car_paint_window = None

        create_button = QPushButton("Stworz wlasny samochod", self)
        create_button.clicked.connect(self.create_button_open)
        self.layout.addWidget(create_button)

    def load_images(self, folder_path):
        images = [f for f in os.listdir(folder_path) if f.lower().endswith(('.png', '.jpg', '.jpeg'))]
        for idx, image in enumerate(images):
            image_path = os.path.join(folder_path, image)
            pixmap = QPixmap(image_path).scaled(100, 100, aspectRatioMode=1)
            button = QPushButton()
            button.setIcon(QIcon(pixmap))
            button.setIconSize(QSize(100, 100))
            button.setFixedSize(110, 110)
            button.clicked.connect(lambda _, img=image_path: self.select_image(img))
            self.scroll_layout.addWidget(button, idx // 4, idx % 4)

    def select_image(self, image_path):
        self.parent().set_photo_path(os.path.basename(image_path))
        if self.custom_car_paint_window:
            self.custom_car_paint_window.close()
        self.close()

    def create_button_open(self):
        self.custom_car_paint_window = CustomCarPaintWindow(self)
        self.custom_car_paint_window.show()


class CustomCarPaintWindow(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.parent = parent
        self.setWindowTitle("Stworz własny samochód")

        self.toolbar_height = const.TOOLBAR_HEIGHT_PAINTING_CARS

        self.zoom_out_scale = const.ZOOM_OUT_SCALE_PAINTING_CARS
        self.paint_window_width = int(const.ONE_FIELD_WIDTH * self.zoom_out_scale)
        self.paint_window_height = int(const.ONE_FIELD_HEIGHT * self.zoom_out_scale)

        self.toolbar_width = self.paint_window_width

        self.setFixedSize(self.paint_window_width, self.paint_window_height + self.toolbar_height)

        screen_geometry = self.screen().geometry()

        x = (screen_geometry.width() - self.paint_window_width) // 2
        y = (screen_geometry.height() - self.paint_window_height - self.toolbar_height) // 2

        self.setGeometry(QRect(x, y, self.paint_window_width, self.paint_window_height + self.toolbar_height))

        main_widget = QWidget(self)
        self.setCentralWidget(main_widget)

        layout = QVBoxLayout(main_widget)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(0)

        self.paint_area = QWidget(self)
        self.paint_area.setFixedSize(self.paint_window_width, self.paint_window_height)
        layout.addWidget(self.paint_area)

        self.toolbar = QWidget(self)
        self.toolbar.setFixedSize(self.paint_window_width, self.toolbar_height)
        toolbar_layout = QHBoxLayout(self.toolbar)
        toolbar_layout.setContentsMargins(0, 0, 0, 0)

        for color in const.colors:
            color_button = QPushButton(color.capitalize(), self.toolbar)
            color_button.clicked.connect(lambda _, col=color: self.change_pen_color(col))
            toolbar_layout.addWidget(color_button)

        cleaning_button = QPushButton("Wyczysc", self.toolbar)
        cleaning_button.clicked.connect(self.wyczysc)
        toolbar_layout.addWidget(cleaning_button)

        cancel_button = QPushButton("Anuluj", self.toolbar)
        cancel_button.clicked.connect(self.close)
        toolbar_layout.addWidget(cancel_button)

        save_button = QPushButton("Zapisz", self.toolbar)
        save_button.clicked.connect(self.save_image)
        toolbar_layout.addWidget(save_button)

        layout.addWidget(self.toolbar)

        self.setAttribute(Qt.WA_StaticContents)
        self.drawing = False
        self.last_point = QPoint()
        self.pen_color = const.colors[0]
        self.pen_width = 3

        self.lines = {}
        for color in const.colors:
            self.lines[color] = []

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton and self.paint_area.rect().contains(event.pos()):
            self.drawing = True
            self.last_point = event.pos()

    def mouseMoveEvent(self, event):
        if self.drawing and self.paint_area.rect().contains(event.pos()):
            self.lines[self.pen_color].append((self.last_point, event.pos()))
            self.last_point = event.pos()
            self.update()

    def mouseReleaseEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.drawing = False

    def paintEvent(self, event):
        canvas_painter = QPainter(self)

        for color, lines in self.lines.items():
            canvas_painter.setPen(QPen(QColor(color), self.pen_width, Qt.SolidLine))

            for start_point, end_point in lines:
                canvas_painter.drawLine(start_point, end_point)

    def change_pen_color(self, color):
        self.pen_color = color

    def wyczysc(self):
        self.lines = {}
        for color in const.colors:
            self.lines[color] = []
        self.update()

    def save_image(self):
        img = Image.new('RGBA', (const.ONE_FIELD_WIDTH, const.ONE_FIELD_HEIGHT), color=(0, 0, 0, 0))

        draw = ImageDraw.Draw(img)

        for color, lines in self.lines.items():
            for start_point, end_point in lines:
                draw.line([start_point.x()/const.ZOOM_OUT_SCALE_PAINTING_CARS, start_point.y()/const.ZOOM_OUT_SCALE_PAINTING_CARS, end_point.x()/const.ZOOM_OUT_SCALE_PAINTING_CARS, end_point.y()/const.ZOOM_OUT_SCALE_PAINTING_CARS], fill=color, width=1)

        img.save(const.PATH_TO_IMAGES + '\\$' + const.get_random_name() + '.png')
        self.parent.load_images(self.parent.folder_path)
        self.close()
