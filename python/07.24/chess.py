class Figure:
	def __init__(self, name, color,  cell):
		self.name = name
		self.color = color
		self.cell = cell

	def __str__(self):
		return self.name + 'is in' + self.cell

	def move(self, cell):
		pass

class Pawn(Figure):
	def __init__(self, color, cell):
		super().__init__('Pawn', color, cell)

	def move(self, cell):
		if cell.x == self.cell.x and (cell.y - self.cell.y == 1 or cell.y - self.cell.y == 1):
			self.cell.y = cell.y

class Knight(Figure):
	def __init__(self, color, cell):
		super().__init__('Knight', color, cell)

	def move(self, cell):
		if (abs(cell.x - self.cell.x == 2) and abs(cell.y - self.cell.y == 1)) or (abs(cell.x - self.cell.x == 1) and abs(cell.y - self.cell.y == 2)):
			self.cell.x = cell.x
			self.cell.y = cell.y

class Rook(Figure):
	def __init__(self, color, cell):
		super().__init__('Bishop', color, cell)

	def move(self, cell):
		if (cell.x == self.cell.x and cell.y != self.cell.y) or (cell.x != self.cell.x and cell.y == self.cell.y):
			self.cell.x = cell.x
			self.cell.y = cell.y

class Bishop(Figure):
	def __init__(self, color, cell):
		super().__init__('Bishop', color, cell)

	def move(self, cell):
		if abs(cell.x - self.cell.x) == abs(cell.y - self.cell.y == 1):
			self.cell.x = cell.y
			self.cell.y = cell.y

class Queen(Figure):
	def __init__(self, color, cell):
		super().__init__('Queen', color, cell)

	def move(self, cell):
		self.cell.x = cell.y
		self.cell.y = cell.y

class King(Figure):
	def __init__(self, color, cell):
		super().__init__('King', color, cell)

	def move(self, cell):
		if abs(cell.x - self.cell.x) <= 1 and abs(cell.y - self.cell.y == 1) <= 1:
			self.cell.x = cell.y
			self.cell.y = cell.y

class Cell:
	def __init__(self, x, y):
		self.x = x
		self.y = y

class Board:
	def __init__(self):
		self.cells = []
		for i in range(8):
			for j in range(8):
				self.cells.append(Cell(i, j))

class Player:
	def __init__(self, color):
		self.color = color
		self.figures = []

class Game:
	def __init__(self):
		self.player1 = Player('White')
		self.player2 = Player('Black')
		self.board = Board()

	def start_game(self):
		pass