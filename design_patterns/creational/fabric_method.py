class Car:
    def __init__(self, color, max_speed):
        self.color = None
        self.max_speed = None
    def get_car_name(self):
        pass

class Mercedes(Car):
    def __init__(self, color, max_speed):
        super().__init__(color, max_speed)

    def get_brand_name(self):
        print('Mercedes')


class Toyota(Car):
    def __init__(self, color, max_speed):
        super().__init__(color, max_speed)

    def get_brand_name(self):
        print('Toyota')

merc = Mercedes('black', 320)
toyota = Toyota('white', 288)

merc.get_brand_name()
toyota.get_brand_name()