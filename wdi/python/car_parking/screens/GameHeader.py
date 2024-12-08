from PyQt5.QtGui import QPainter
from PyQt5.QtWidgets import QMainWindow, QLabel

import Colors
import time


class GameHeader(QMainWindow):
    def __init__(self, window_position):
        super().__init__()
        self.setWindowTitle('Game Header')
        self.setGeometry(window_position)
        self.window_position = window_position

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(event.rect(), Colors.bg_color)

        label = QLabel(self)
        label.setText("")
        label.setStyleSheet("color: white;")
        label.show()

