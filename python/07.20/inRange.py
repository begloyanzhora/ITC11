def inRange (n):
	return abs(1000 - n) <= 100 or abs(2000 - n) <= 100

def main ():
	print('Enter the number which you want to check:', end = ' ')
	n = int(input())
	print(inRange(n))

if __name__ == "__main__":
	main()