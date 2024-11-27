from PyQt5.QtWidgets import QMainWindow, QLabel, QPushButton
from enum import Enum


class WindowState(Enum):
    NoneInfo = 0,
    CarInfo = 1,
    FieldInfo = 2,


class Menu(QMainWindow):
    def __init__(self, queue_list):
        super().__init__()
        self.setWindowTitle('Menu')
        self.setGeometry(0, 0, 500, 600)
        self.windowState = WindowState.NoneInfo
        self.clickedCar = None
        self.clickedField = None

        self.queue_list = queue_list

        self.displayWindowInfo()

    def clearWindow(self):
        for child in self.children():
            if isinstance(child, QLabel) or isinstance(child, QPushButton):
                child.deleteLater()
        self.update()

    def set_main_screen(self, main):
        self.main = main

    def set_queue_screen(self, queue_screen):
        self.queue_screen = queue_screen

    def displayWindowInfo(self):
        self.clearWindow()
        if self.windowState == WindowState.NoneInfo:
            self.label = QLabel("Kliknij na pole albo na samochód, aby wyświetlić info", self)
        elif self.windowState == WindowState.CarInfo:
            self.label = QLabel(f"na tym polu jest samochód: {self.clickedCar.plate}", self)
        elif self.windowState == WindowState.FieldInfo:
            if self.clickedField.is_empty():
                self.label = QLabel(f"na tym polu nie ma samochodu", self)
                button = QPushButton("Wjedz samochdodem pierwszym z kolejki", self)
                button.setGeometry(100, 100, 200, 50)
                button.clicked.connect(self.wjedz_samochodem)
                button.show()
            else:
                self.label = QLabel(f"na tym polu jest samochod", self)
                button = QPushButton("Wyjedz samochdodem", self)
                button.setGeometry(100, 100, 200, 50)
                button.clicked.connect(self.wyjedz_samochodem)
                button.show()
        self.label.adjustSize()
        self.label.show()

    def wjedz_samochodem(self):
        car = self.queue_list.wyjedz_pierwszym()
        if car:
            was_empty = self.clickedField.add_car(car)
            if was_empty:
                self.main.reset_button_styles()
                self.main.create_buttons()
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
