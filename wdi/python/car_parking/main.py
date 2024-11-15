import sys
from PyQt5.QtWidgets import QApplication
from screens.Main import MainWindow


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow({'x': 1000, 'y': 600}, 10)
    window.show()
    app.exec_()
