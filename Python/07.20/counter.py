def areDiffDigits (n):
	a = n % 10
	b = n // 10 % 10
	c = n // 100

	return a != b != c

def canBeDevidedBy3 (n):
	return n % 3 == 0

def counter (n):
	if n < 100 or n > 999:
		return "Invalid number"

	counter = 0
	for i in range(102, n + 1):
		if areDiffDigits(i) and canBeDevidedBy3(i):
			counter += 1
	return counter

def main ():
	print ('Enter a three-digit number:', end = ' ')
	n = int(input())
	print(counter(n))

if __name__ == "__main__":
	main()