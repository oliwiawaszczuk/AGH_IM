from PyQt5.QtCore import Qt, QPoint
from PyQt5.QtGui import QPainter, QPen, QColor
from PyQt5.QtWidgets import QMainWindow, QDesktopWidget, QPushButton

import Colors


class Close(QMainWindow):
    def __init__(self, window_size, screen_position, app):
        super().__init__()
        self.setWindowTitle('Close')
        self.setGeometry(screen_position)
        self.app = app

        button = QPushButton('', self)
        button.setGeometry(0, 0, window_size.width(), window_size.height())
        button.setStyleSheet("background: transparent; border: none;")
        button.clicked.connect(self.close)

    def close(self):
        self.app.quit()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)

        pen = QPen(Qt.red, 5, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin)
        painter.setPen(pen)

        rect = self.rect()
        margin = 20

        painter.fillRect(rect, QColor(Colors.bg_color))

        painter.drawLine(rect.topLeft() + QPoint(margin, margin), rect.bottomRight() - QPoint(margin, margin))
        painter.drawLine(rect.topRight() - QPoint(margin, -margin), rect.bottomLeft() + QPoint(margin, -margin))
