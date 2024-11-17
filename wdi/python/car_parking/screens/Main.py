import sys
from PyQt5.QtGui import QPainter, QPen
from PyQt5.QtWidgets import QMainWindow, QDesktopWidget, QPushButton
import Colors


class MainWindow(QMainWindow):
    def __init__(self, window_size, window_position, how_many_empty):
        super().__init__()
        self.setWindowTitle('Car Parking')

        self.window_size = window_size
        self.how_many_empty = how_many_empty
        self.bg_color = Colors.bg_color
        self.line_color = Colors.line_color

        self.create_buttons()
        self.setGeometry(window_position)

    def create_button(self, x, y, width, height, id):
        button = QPushButton('', self)
        button.setGeometry(x, y, width, height)
        button.setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none; color: white;")
        button.clicked.connect(lambda _, i=id: self.click(i))
        return button

    def create_buttons(self):
        one_empty_width = int(self.window_size.width() / self.how_many_empty)
        one_empty_height = int(self.window_size.height() / 3)

        for i in range(int(self.how_many_empty / 2)):
            x = i * 2 * one_empty_width
            self.create_button(x, 0, 2 * one_empty_width, one_empty_height, i + 1)

        for i in range(int(self.how_many_empty / 2), int(self.how_many_empty)):
            x = (i - int(self.how_many_empty / 2)) * 2 * one_empty_width
            y = self.window_size.height() - one_empty_height
            self.create_button(x, y, 2 * one_empty_width, one_empty_height, i + 1)

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
        print("clicked:", id)
