import random
import string

HOW_MANY_EMPY_FIELD = 16
ONE_FIELD_WIDTH = 100
ONE_FIELD_HEIGHT = 170
PATH_TO_IMAGES = "R:\\PROGRAMOWANIE\\AGH_IM\\wdi\\python\\car_parking\\images"
ZOOM_OUT_SCALE_PAINTING_CARS = 5
TOOLBAR_HEIGHT_PAINTING_CARS = 80


def get_random_name():
    return ''.join(random.choices(string.ascii_uppercase + string.digits, k=10))


colors = ['red', 'green', 'blue', 'yellow', 'black', 'white']