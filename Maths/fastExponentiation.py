# Complexity : O(Log n)

def power(k, n):
	if n == 0:
		return 1
	# Check if N is Odd
	ans1 = power(k, n//2)
	if n&1 == 1:
		return k * ans1 * ans1

	return ans1 * ans1


print(power(4, 5))


