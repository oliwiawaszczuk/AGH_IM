class Parking:
    def __init__(self):
        self.parking_spaces = []

    def add_space(self, parking_space):
        self.parking_spaces.append(parking_space)

    def find_space_by_id(self, id):
        for space in self.parking_spaces:
            if space.id == id:
                return space
        return None
