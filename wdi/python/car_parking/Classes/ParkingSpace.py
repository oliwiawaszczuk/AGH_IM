class ParkingSpace:
    def __init__(self, id):
        self.id = id
        self.car = None
        self.rotated = False

    def is_empty(self):
        # print(f"sprawadzanie miejsca {self.id} a samochod to: {self.car}")
        if self.car is None:
            return True
        else:
            return False

    def add_car(self, car):
        if self.is_empty() is False:
            print("Miejsce zajete, nie mozna wjechac")
            return False
        else:
            # print(f"dodaje {car} na miejsce {self.id}")
            self.car = car
            return True

    def leave_car(self, car):
        if self.is_empty() is True:
            print("Miejsce puste, nie mozna wyjechac")
            return False
        elif self.car != car:
            print("Blad, probujesz wyjechac nie twoim autem")
            return False
        else:
            self.car = None
            return True
