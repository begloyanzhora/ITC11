def fib (n):
	if n <= 2:
		return 1

	return fib(n - 1) + fib(n - 2)

def main ():
	print("Enter the number which you want to get from Fibonacci sequence:", end = " ")
	n = int(input())
	print(str(n) + "th member of Fibonacci sequence is:", end = " ")
	print(fib(n))

if __name__ == "__main__":
	main()