import sys

from PyQt5.QtGui import QPainter, QPen
from PyQt5.QtWidgets import QMainWindow, QDesktopWidget, QPushButton

import Colors


class MainWindow(QMainWindow):
    def __init__(self, window_size, how_many_empty):
        super().__init__()
        self.setWindowTitle('Car Parking')

        self.window_size = window_size
        screen = QDesktopWidget().screenGeometry()
        screen_width = (screen.width()/2) - (self.window_size['x']/2)
        screen_height = (screen.height()/2) - (self.window_size['y']/2)
        self.setGeometry(int(screen_width), int(screen_height), self.window_size['x'], self.window_size['y'])

        self.how_many_empty = how_many_empty

        self.bg_color = Colors.bg_color
        self.line_color = Colors.line_color

        self.button = QPushButton('Start', self)

    # self.button.clicked.connect(self.click())

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(event.rect(), self.bg_color)

        pen = QPen(self.line_color, 3)
        painter.setPen(pen)

        one_empty_width = int(self.window_size['x']/self.how_many_empty)
        one_empty_height = int(self.window_size['y']/3)
        # if self.how_many_empty%2 != 0:
        #     self.how_many_empty -= 1

        for i in range(1, int(self.how_many_empty/2)):
            width = i*one_empty_width*2
            painter.drawLine(width, 0, width, one_empty_height)

        for i in range(1, int(self.how_many_empty/2)):
            width = i*one_empty_width*2
            painter.drawLine(width, self.window_size['y']-one_empty_height, width, self.window_size['y'])

        # BORDER LINE - nie działa, poprawić
        border_pen = QPen(Colors.border_line_color, 5)
        painter.setPen(border_pen)
        painter.drawLine(0, 0, self.window_size['x'], 0)
        painter.drawLine(self.window_size['x'], 0, self.window_size['x'], self.window_size['y'])
        painter.drawLine(self.window_size['x'], self.window_size['y'], 0, self.window_size['y'])
        painter.drawLine(0, self.window_size['y'], 0, 0)

    def click(self):
        print("clicked: ")
