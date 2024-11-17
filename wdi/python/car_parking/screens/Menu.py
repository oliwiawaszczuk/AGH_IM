from PyQt5.QtWidgets import QMainWindow, QDesktopWidget


class Menu(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Menu')
        self.setGeometry(300, 300, 300, 300)
