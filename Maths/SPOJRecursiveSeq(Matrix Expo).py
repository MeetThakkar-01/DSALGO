# Sequence (ai) of natural numbers is defined as follows:

#    ai = bi (for i <= k)
#    ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

# where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.
# Input

# On the first row there is the number C of test cases (equal to about 1000).
# Each test contains four lines:

# k - number of elements of (c) and (b) (1 <= k <= 10)
# b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
# c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
# n - natural number (1 <= n <= 109)
# Output

# Exactly C lines, one for each test case: an modulo 109  


def matrixMultiply(a, b, k):
	c = [[0 for i in range(k + 1)] for j in range(k + 1)]
	for i in range(1, k + 1):
		for j in range(1, k + 1):
			for x in range(1, k + 1):
				c[i][j] = (c[i][j] + (a[i][x] * b[x][j])) 

	return c

def power(a, b, k):
	if b == 1:
		return a
	if b%2 != 0:
		return matrixMultiply(a, power(a, b-1, k), k)
	else:
		ans = power(a, b//2, k)
		return matrixMultiply(ans, ans, k)


def compute(n, b, c, k):
	if n == 0:
		return 0
	if n <= k:
		return b[n - 1]

	# Otherwise Use matrix Exponenntioation
	F1 = [0 for i in range(k + 1)]
	for i in range(1, len(F1)):
		F1[i] = b[i - 1]

	# Transformation MAtrix
	T = [[0 for i in range(k + 1)] for j in range(k + 1)]
	for i in range(1, k + 1):
		for j in range(1, k + 1):
			if i < k:
				if j == i + 1:
					T[i][j] = 1
				else:
					T[i][j] = 0
			else:
				T[i][j] = c[k-j]

	# Power Function For Matrix T
	T = power(T, n - 1, k)

	# last Step
	res = 0
	for i in range(1, k + 1):
		res = (res + (T[1][i] * F1[i]))

	return res


for _ in range(int(input())):
	k = int(input())
	b = list(map(int, input().split()))
	c = list(map(int, input().split()))

	n = int(input())

	print(compute(n, b, c, k))
