from PyQt5.QtCore import QSize, QRect
from PyQt5.QtWidgets import QDesktopWidget

window_sizes = {
    'main': QSize(1000, 600),
}


def get_position_screens():
    screen_size = QDesktopWidget().screenGeometry()

    main_screen_x = int((screen_size.width() / 2) - (window_sizes['main'].width() / 2))
    main_screen_y = int((screen_size.height() / 2) - (window_sizes['main'].height() / 2))

    close_screen_width = int((screen_size.width() - window_sizes['main'].width()) / 2)
    close_screen_height = int((screen_size.height() - window_sizes['main'].height()) / 2)
    window_sizes['close'] = QSize(close_screen_width, close_screen_height)

    position_screens = {
        'main': QRect(main_screen_x, main_screen_y, window_sizes['main'].width(), window_sizes['main'].height()),
        'close': QRect(screen_size.width()-close_screen_width, 0, close_screen_width, close_screen_height),
    }
    return position_screens, window_sizes

