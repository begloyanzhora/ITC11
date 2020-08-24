def canBeDevided (a, b):
	return a % b == 0

def isPerfect (n):
	sum = 0
	for i in range(1, int(n / 2) + 1):
		if canBeDevided(n, i):
			sum += i

	return sum == n

def main ():
	print('Enter the number which you want to check:', end  = ' ')
	n = int(input())
	print (isPerfect(n))

if __name__ == "__main__":
	main()