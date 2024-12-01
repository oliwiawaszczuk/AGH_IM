class ClassQueue:
    def __init__(self):
        self.queue_list = []

    def add_car_to_queue(self, car):
        if not self.queue_list:
            new_id = 1
        else:
            existing_ids = sorted([car.id for car in self.queue_list])
            new_id = next((i for i in range(1, max(existing_ids) + 2) if i not in existing_ids), len(existing_ids) + 1)

        car.id = new_id
        self.queue_list.append(car)

    def wyjedz_pierwszym(self):
        if len(self.queue_list) != 0:
            car = self.queue_list.pop(0)
            return car
        else:
            print("nie ma samochodów w kolejce")

    def __iter__(self):
        self.index = 0
        return self

    def __next__(self):
        if self.index < len(self.queue_list):
            element = self.queue_list[self.index]
            self.index += 1
            return element
        else:
            raise StopIteration
