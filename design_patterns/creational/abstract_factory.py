""" Define abstarct factory """
class Furniture_factory():
    def create_chair(self):
        pass
    def create_sofa(self):
        pass
    def create_coffeetable(self):
        pass

""" Define abstarct furniture """
class Chair():
    def create(self):
        pass

class Sofa():
    def create(self):
        pass

class Coffeetable():
    def create(self):
        pass

""" Define furniture in contrette style """
""" Modern """
class Modern_chair(Chair):
    def create(self):
        print('Created Chair in MODERN style')

class Modern_sofa(Sofa):
    def create(self):
        print('Created sofa in MODERN style')

class Modern_coffeetable(Coffeetable):
    def create(self):
        print('Created Coffeetable in MODERN style')

""" Victorian """
class Viktorian_chair(Chair):
    def create(self):
        print('Created Chair in Viktorian style')

class Viktorian_sofa(Sofa):
    def create(self):
        print('Created sofa in Viktorian style')

class Viktorian_coffeetable(Coffeetable):
    def create(self):
        print('Created Coffeetable in Viktorian style')

""" Art Deko """
class ArtDeko_chair(Chair):
    def create(self):
        print('Created Chair in ArtDeko style')

class ArtDeko_sofa(Sofa):
    def create(self):
        print('Created sofa in ArtDeko style')

class ArtDeko_coffeetable(Coffeetable):
    def create(self):
        print('Created Coffeetable in ArtDeko style')


""" Factories creating in concrete style """
class Modern_factory(Furniture_factory):
    def create_chair(self):
        return Modern_chair()
    def create_sofa(self):
        return Modern_sofa()
    def create_coffeetable(self):
        return Modern_coffeetable()

class ArtDeko_factory(Furniture_factory):
    def create_chair(self):
        return ArtDeko_chair()
    def create_sofa(self):
        return ArtDeko_sofa()
    def create_coffeetable(self):
        return ArtDeko_coffeetable()

class Viktorian_factory(Furniture_factory):
    def create_chair(self):
        return Viktorian_chair()
    def create_sofa(self):
        return Viktorian_sofa()
    def create_coffeetable(self):
        return Viktorian_coffeetable()