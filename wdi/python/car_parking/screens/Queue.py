from PyQt5.QtGui import QPainter, QPixmap, QTransform, QIcon
from PyQt5.QtWidgets import QMainWindow, QPushButton

import Colors
import const
from Classes.Car import Car
from screens.Menu import WindowState


class Queue(QMainWindow):
    def __init__(self, window_size, window_position, menu):
        super().__init__()
        self.setWindowTitle('Queue')
        self.setGeometry(window_position.x(), window_position.y()+const.ONE_FIELD_HEIGHT, window_size.width(), window_size.height())

        self.menu = menu
        self.bg_color = Colors.bg_color

    def set_queue_list(self, queue_list):
        self.queue_list = queue_list

    def set_main_screen(self, main):
        self.main = main

    def clearWindow(self):
        for child in self.children():
            if isinstance(child, QPushButton):
                child.deleteLater()
        self.update()

    def refresh_view(self):
        self.clearWindow()

        x_offset = 0
        y_offset = int(const.ONE_FIELD_HEIGHT / 4)

        for car in self.queue_list:
            image = QPixmap(f"images/{car.path_to_image}").scaled(const.ONE_FIELD_WIDTH, const.ONE_FIELD_HEIGHT)
            image = image.transformed(QTransform().rotate(-90))

            button = QPushButton("", self)
            button.setGeometry(x_offset, y_offset, const.ONE_FIELD_HEIGHT, const.ONE_FIELD_WIDTH)
            button.setStyleSheet("background-color: rgb(0, 0, 0, 0);")
            icon = QIcon(image)
            button.setIcon(icon)
            button.setIconSize(image.size())

            button.clicked.connect(lambda _, c=car: self.on_car_clicked(c))
            button.show()

            x_offset += const.ONE_FIELD_HEIGHT + 10

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(event.rect(), self.bg_color)

    def on_car_clicked(self, car):
        self.menu.windowState = WindowState.CarInfo
        self.menu.clickedCar = car
        self.menu.displayWindowInfo()
        self.main.reset_button_styles()
