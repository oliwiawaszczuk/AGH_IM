from PyQt5.QtGui import QPainter, QPen, QPixmap, QIcon
from PyQt5.QtWidgets import QMainWindow, QPushButton
import Colors
import const
from Classes.ParkingSpace import ParkingSpace
from screens.Menu import WindowState


class MainWindow(QMainWindow):
    def __init__(self, window_size, window_position, menu, parking):
        super().__init__()
        self.setWindowTitle('Car Parking')

        self.window_size = window_size
        self.menu = menu
        self.parking = parking
        self.how_many_empty = const.HOW_MANY_EMPY_FIELD
        self.bg_color = Colors.bg_color
        self.line_color = Colors.line_color

        self.buttons = []

        self.create_buttons()
        self.setGeometry(window_position)

    def reset_button_styles(self):
        for button in self.buttons:
            button.setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none; color: white;")

    def create_buttons(self):
        self.buttons.clear()

        one_empty_width = int(self.window_size.width() / self.how_many_empty)
        one_empty_height = int(self.window_size.height() / 3)

        for i in range(int(self.how_many_empty)):
            x = (i % (self.how_many_empty // 2)) * 2 * one_empty_width
            y = 0 if i < self.how_many_empty // 2 else self.window_size.height() - one_empty_height
            button = QPushButton(str(i + 1), self)
            button.setGeometry(x, y, 2 * one_empty_width, one_empty_height)
            button.setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none; color: white;")
            button.clicked.connect(lambda _, btn_id=i + 1: self.click(btn_id))
            self.buttons.append(button)
            button.show()

        self.update_all_buttons()

    def update_all_buttons(self):
        for i, button in enumerate(self.buttons):
            parking_space = self.parking.find_space_by_id(i + 1)
            self.update_button_image(button, parking_space)

    def update_button_image(self, button, parking_space):
        if not parking_space.is_empty():
            image = QPixmap(f"images/{parking_space.car.path_to_image}").scaled(
                const.ONE_FIELD_WIDTH, const.ONE_FIELD_HEIGHT
            )
            icon = QIcon(image)
            button.setIcon(icon)
            button.setIconSize(image.size())
        else:
            button.setIcon(QIcon())

    # def find_button_by_id(self, id):
    #     for button in self.buttons:
    #         if id == button.id

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(event.rect(), self.bg_color)
        self.draw_lines(painter)

    def draw_lines(self, painter):
        pen = QPen(self.line_color, 3)
        painter.setPen(pen)

        one_empty_width = int(self.window_size.width() / self.how_many_empty)
        one_empty_height = int(self.window_size.height() / 3)

        for i in range(1, int(self.how_many_empty / 2)):
            width = i * one_empty_width * 2
            painter.drawLine(width, 0, width, one_empty_height)
            painter.drawLine(width, self.window_size.height() - one_empty_height, width, self.window_size.height())

        # BORDER LINE
        border_pen = QPen(Colors.border_line_color, 5)
        painter.setPen(border_pen)
        painter.drawLine(0, 0, self.window_size.width(), 0)
        painter.drawLine(self.window_size.width(), 0, self.window_size.width(), self.window_size.height())
        painter.drawLine(self.window_size.width(), self.window_size.height(), 0, self.window_size.height())
        painter.drawLine(0, self.window_size.height(), 0, 0)

    def click(self, id):
        self.reset_button_styles()

        clicked_button = self.buttons[id - 1]
        clicked_button.setStyleSheet(f"background-color: rgba(0, 0, 0, 0); border: 3px solid {Colors.border_field}; color: white;")

        self.menu.windowState = WindowState.FieldInfo
        pspace = self.parking.find_space_by_id(id)
        if pspace:
            self.menu.clickedField = pspace
            self.menu.displayWindowInfo()
