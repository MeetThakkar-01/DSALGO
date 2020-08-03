# Finding a raise to b with modulo c i.e pow(a, b) % c

# Recursive Solution
# Time Complexity : O(Logb)

def moduloPower(a, b, c):
	if b == 0:
		return 1
	if b == 1:
		return a
	if b%2 == 0:
		return moduloPower((a*a) % c, b/2, c)
	else:
		return (a%c * moduloPower((a*a)%c, (b - 1)/2, c)%c) % c

# Iterative Solution
# Time Complexity : O(Logb)

def moduloPower(a, b, c):
	ans = 1
	while b!= 0:
		if (b & 1 == 1):
			ans *= a % c
		b = b >> 1
		a *= a % c
	return ans

if __name__ == "__main__": 
	print(moduloPower(2, 5, 5))