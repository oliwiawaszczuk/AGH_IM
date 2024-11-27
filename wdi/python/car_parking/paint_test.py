from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout
from PyQt5.QtGui import QPainter, QPen, QColor
from PyQt5.QtCore import Qt, QPoint
import sys


class DrawingArea(QWidget):
    def __init__(self):
        super().__init__()
        self.setAttribute(Qt.WA_StaticContents)
        self.drawing = False
        self.last_point = QPoint()
        self.pen_color = QColor('black')
        self.pen_width = 3

        # Lista przechowująca linie jako pary punktów
        self.lines = []

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.drawing = True
            self.last_point = event.pos()

    def mouseMoveEvent(self, event):
        if self.drawing:
            # Dodajemy nową linię do listy jako parę punktów (start, koniec)
            self.lines.append((self.last_point, event.pos()))
            self.last_point = event.pos()
            self.update()

    def mouseReleaseEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.drawing = False

    def paintEvent(self, event):
        # Tworzymy obiekt QPainter do rysowania
        canvas_painter = QPainter(self)
        canvas_painter.setPen(QPen(self.pen_color, self.pen_width, Qt.SolidLine))

        # Rysujemy każdą linię z listy zapisanych linii
        for line in self.lines:
            start_point, end_point = line
            canvas_painter.drawLine(start_point, end_point)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Drawing Application")
        self.setGeometry(100, 100, 800, 600)

        self.drawing_area = DrawingArea()
        layout = QVBoxLayout()
        layout.addWidget(self.drawing_area)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
