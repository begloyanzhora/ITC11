""" size; cheese; sauce; pepperoni; ham; olives; mushrooms; """
class Pizza_bulider:
    def set_size(self):
        pass
    def set_cheese(self):
        pass
    def set_pepperoni(self):
        pass
    def set_ham(self):
        pass
    def set_olives(self):
        pass
    def set_mushrooms(self):
        pass

class Pizza:
    def __init__(self):
        self.parts = []
    def add(self, part):
        self.parts.append(part)

class Concrete_pizza_builder:
    def __init__(self):
        self.pizza = Pizza()

    def set_size(self):
        self.pizza.add('size: 40')

    def set_cheese(self):
        self.pizza.add('Cheese: Yes')

    def set_ham(self):
        self.pizza.add('ham: Yes')

    def set_mushrooms(self):
        self.pizza.add('mushrooms: Yes')