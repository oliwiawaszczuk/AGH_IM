import sys

from PyQt5.QtWidgets import QApplication

import const
from Classes.Car import Car
from Classes.ParkingSpace import ParkingSpace
from Classes.Queue import ClassQueue
from Dimensions import calc_screens_position
from Classes.Parking import Parking
from screens.Queue import Queue
from screens.Close import Close
from screens.Main import MainWindow
from screens.Menu import Menu


if __name__ == "__main__":
    app = QApplication(sys.argv)

    parking = Parking()
    queue_list = ClassQueue()
    queue_list.add_car_to_queue(Car(1, "KR 01E34", "car1.png"))
    queue_list.add_car_to_queue(Car(2, "KK 123AG", "car2.png"))
    queue_list.add_car_to_queue(Car(3, "LB 0044A", "car3.png"))
    queue_list.add_car_to_queue(Car(4, "PR 444", "car4.png"))
    queue_list.add_car_to_queue(Car(5, "WW 12FE3", "car5.png"))
    queue_list.add_car_to_queue(Car(6, "LBI 23F1", "car6.png"))

    for i in range(1, const.HOW_MANY_EMPY_FIELD+1):
        new_parking_space = ParkingSpace(i)
        parking.add_space(new_parking_space)

    position_screens, window_sizes = calc_screens_position()

    menu = Menu(queue_list)
    menu.show()

    main_window = MainWindow(window_sizes['main'], position_screens['main'], menu, parking)
    main_window.show()

    menu.set_main_screen(main_window)

    queue_window = Queue(window_sizes['queue'], position_screens['queue'], menu)
    queue_window.set_queue_list(queue_list)
    queue_window.set_main_screen(main_window)
    queue_window.refresh_view()
    queue_window.show()

    menu.set_queue_screen(queue_window)

    close = Close(window_sizes['close'], position_screens['close'], app)
    close.show()

    app.exec_()
