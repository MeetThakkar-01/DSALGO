# To Find Nth number in fibonacci series in log n time using MATRIX EXPONENTIAN


# Time Complexity = O(Log n)

def multiply(A, B):
	first = A[0][0] * B[0][0] + A[0][1] * B[1][0]
	second = A[1][0] * B[0][0] + A[1][1] * B[1][0]
	third = A[0][0] * B[0][1] + A[0][1] * B[1][1]
	fourth = A[1][0] * B[0][1] + A[1][1] * B[1][1]

	A[0][0] = first
	A[0][1] = second
	A[1][0] = third
	A[1][1] = fourth


def power(A, n):
	if n == 0 or n == 1:
		return
	power(A, n//2)

	multiply(A, A)

	if (n % 2 != 0):
		t = [[1, 1], [1, 0]]
		multiply(A, t)

def fib(n):
	A = [[1, 1], [1, 0]]

	if n==0:
		return 0
	power(A, n - 1)

	return A[0][0]

def sumFibo(n, m):
	return fib(m + 2) + fib(n - 1)

if __name__ == "__main__": 
	print(sumFibo(1, 2))