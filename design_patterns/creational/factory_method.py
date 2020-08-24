class Car:
    def get_info(self):
        pass

class Mercedes(Car):
    def get_info(self):
        print('You\'ve created Mercedes')

class Toyota(Car):
    def get_info(self):
        print('You\'ve created Toyota')

class Creator:
    def create_car(self, brand_name):
        if brand_name == 'Mercedes':
            return Mercedes()
        elif brand_name == 'Toyota':
            return Toyota()
        else:
            return None

car = Creator().create_car('Mercedes')
car.get_info()