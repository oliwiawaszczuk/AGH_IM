from PyQt5.QtWidgets import QMainWindow, QDesktopWidget, QPushButton


class Close(QMainWindow):
    def __init__(self, window_size, screen_position, app):
        super().__init__()
        self.setWindowTitle('Close')
        self.setGeometry(screen_position)
        self.app = app

        button = QPushButton('close', self)
        button.setGeometry(0, 0, window_size.width(), window_size.height())
        button.clicked.connect(self.close)

    def close(self):
        self.app.quit()
