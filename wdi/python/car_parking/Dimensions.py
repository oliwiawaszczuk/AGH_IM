from PyQt5.QtCore import QSize, QRect
from PyQt5.QtWidgets import QDesktopWidget

import const


def calc_screens_position():
    window_sizes = {}
    position_screens = {}

    screen_size = QDesktopWidget().screenGeometry()

    # window_sizes['main'] = QSize(int(screen_size.width()/5*3), int(screen_size.height()/5*3))
    window_sizes['main'] = QSize(int(const.HOW_MANY_EMPY_FIELD/2 * const.ONE_FIELD_WIDTH), int(const.ONE_FIELD_HEIGHT * 3))
    main_screen_x = int((screen_size.width() / 2) - (window_sizes['main'].width() / 2))
    main_screen_y = int((screen_size.height() / 2) - (window_sizes['main'].height() / 2))
    position_screens['main'] = QRect(main_screen_x, main_screen_y, window_sizes['main'].width(), window_sizes['main'].height())

    close_screen_width = int((screen_size.width() - window_sizes['main'].width()) / 2)
    close_screen_height = int((screen_size.height() - window_sizes['main'].height()) / 2)
    window_sizes['close'] = QSize(close_screen_width, close_screen_height)
    position_screens['close'] = QRect(screen_size.width()-close_screen_width, 0, close_screen_width, close_screen_height)

    window_sizes['queue'] = QSize(600, const.ONE_FIELD_HEIGHT)  # szerokosc powinna byc zalezna od ilosci autek (aby nie było pustego miejsca)
    queue_screen_x = position_screens['main'].right()
    queue_screen_y = main_screen_y
    position_screens['queue'] = QRect(queue_screen_x, queue_screen_y, window_sizes['queue'].width(), window_sizes['queue'].height())
    return position_screens, window_sizes

