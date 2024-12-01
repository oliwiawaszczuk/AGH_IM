import random
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QMainWindow, QLabel, QPushButton, QVBoxLayout, QWidget
from enum import Enum

class WindowState(Enum):
    NoneInfo = 0,
    CarInfo = 1,
    FieldInfo = 2,


class Menu(QMainWindow):
    def __init__(self, window_position, window_size, queue_list):
        super().__init__()
        self.setWindowTitle('Menu')
        self.setGeometry(window_size)
        self.windowState = WindowState.NoneInfo
        self.clickedCar = None
        self.clickedField = None

        self.queue_list = queue_list

        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)
        self.layout.setContentsMargins(20, 20, 20, 20)
        self.layout.setSpacing(15)

        self.setStyleSheet("""
            QLabel {
                color: #ffffff;
                background-color: #333;
                padding: 10px;
                border-radius: 5px;
            }
            QPushButton {
                background-color: #555;
                color: #fff;
                font-size: 14px;
                padding: 10px 20px;
                border: none;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: #777;
            }
            QPushButton:pressed {
                background-color: #999;
            }
            QWidget {
                background-color: #222;
            }
        """)

        self.displayWindowInfo()

    def set_main_screen(self, main):
        self.main = main

    def set_queue_screen(self, queue_screen):
        self.queue_screen = queue_screen

    def clearWindow(self):
        for i in reversed(range(self.layout.count())):
            widget = self.layout.itemAt(i).widget()
            if widget is not None:
                widget.deleteLater()
        self.update()

    def displayWindowInfo(self):
        self.clearWindow()

        if self.windowState == WindowState.NoneInfo:
            self.label = QLabel("Kliknij na pole albo na samochód,\naby wyświetlić informacje.")
            self.label.setFont(QFont("Arial", 16))
            self.label.setAlignment(Qt.AlignCenter)
            self.layout.addWidget(self.label)

        elif self.windowState == WindowState.CarInfo:
            self.label = QLabel(
                f'<span style="font-size:16pt;">Na tym polu jest samochód: '
                f'<span style="color:#FFD700;">{self.clickedCar.plate}</span></span>'
            )
            self.label.setAlignment(Qt.AlignCenter)
            self.layout.addWidget(self.label)

            details = [
                f"Marka: <span style='color:#FFD700;'>{self.clickedCar.brand}</span>",
                f"Model: <span style='color:#FFD700;'>{self.clickedCar.model}</span>",
                f"Rok: <span style='color:#FFD700;'>{self.clickedCar.year}</span>",
                f"Silnik: <span style='color:#FFD700;'>{self.clickedCar.engine_type}</span>",
                f"Przebieg: <span style='color:#FFD700;'>{self.clickedCar.mileage} km</span>"
            ]

            for detail in details:
                detail_label = QLabel(f'<span style="font-size:14pt;">{detail}</span>')
                detail_label.setAlignment(Qt.AlignLeft)
                self.layout.addWidget(detail_label)

        elif self.windowState == WindowState.FieldInfo:
            if self.clickedField.is_empty():
                self.label = QLabel("Na tym polu nie ma samochodu.")
                button = QPushButton("Wjedź samochodem pierwszym z kolejki")
                button.clicked.connect(self.wjedz_samochodem)
            else:
                details = [
                    f"Na tym polu jest samochód: <span style='color:#FFD700;'>{self.clickedField.car.plate}</span>",
                    f"Marka: <span style='color:#FFD700;'>{self.clickedField.car.brand}</span>",
                    f"Model: <span style='color:#FFD700;'>{self.clickedField.car.model}</span>",
                    f"Rok: <span style='color:#FFD700;'>{self.clickedField.car.year}</span>",
                    f"Silnik: <span style='color:#FFD700;'>{self.clickedField.car.engine_type}</span>",
                    f"Przebieg: <span style='color:#FFD700;'>{self.clickedField.car.mileage} km</span>"
                ]

                for detail in details:
                    detail_label = QLabel(detail)
                    detail_label.setFont(QFont("Arial", 14))
                    detail_label.setAlignment(Qt.AlignLeft)
                    self.layout.addWidget(detail_label)

                button = QPushButton("Wyjedź samochodem")
                button.clicked.connect(self.wyjedz_samochodem)

            self.label.setFont(QFont("Arial", 16))
            self.label.setAlignment(Qt.AlignCenter)
            self.layout.addWidget(self.label)
            self.layout.addWidget(button)

    def wjedz_samochodem(self):
        car = self.queue_list.wyjedz_pierwszym()
        if car:
            was_empty = self.clickedField.add_car(car)
            if was_empty:
                self.clickedField.rotated = random.choice([True, False])
                self.main.reset_button_styles()
                self.main.update_all_buttons()

                self.clickedField = None
                self.windowState = WindowState.NoneInfo
                self.displayWindowInfo()
                self.queue_screen.refresh_view()

    def wyjedz_samochodem(self):
        car = self.clickedField.car
        if car:
            can_leave = self.clickedField.leave_car(car)
            if can_leave:
                self.main.reset_button_styles()
                self.main.update_button_image(self.main.buttons[self.clickedField.id - 1], self.clickedField)
                self.windowState = WindowState.NoneInfo
                self.clickedField = None
                self.displayWindowInfo()
