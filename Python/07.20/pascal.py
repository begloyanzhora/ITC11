def getValue (r, c):
	if c == 1 or c == r:
		return 1

	return getValue(r - 1, c - 1) + getValue(r - 1, c)

def pascalTriangle (n):
	for r in range(1, n + 1):

		for c in range(n - r):
			print(' ', end = '')

		for c in range(1, r + 1):
			print(getValue(r, c), end=' ')

		print()

def main ():
	print("How many rows of Pascal's triangle do you want to print?", end = ' ')
	n = int(input())
	pascalTriangle(n)

	print('Count of locals variables of Pascal triangle function:', end = ' ')
	print(pascalTriangle.__code__.co_nlocals)

if __name__ == "__main__":
	main()