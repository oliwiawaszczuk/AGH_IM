import sys

from PyQt5.QtWidgets import QApplication

from Dimensions import get_position_screens
from screens.Close import Close
from screens.Main import MainWindow
from screens.Menu import Menu


if __name__ == "__main__":
    app = QApplication(sys.argv)

    position_screens, window_sizes = get_position_screens()

    main_window = MainWindow(window_sizes['main'], position_screens['main'], 10)
    main_window.show()

    # menu = Menu()
    # menu.show()

    close = Close(window_sizes['close'], position_screens['close'], app)
    close.show()

    app.exec_()
