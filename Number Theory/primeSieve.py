 # Time Complexity = O(NLog(Log(N)))

def primeSieve(n):
	res = [True] * (n + 1)
	for i in range(2, int(n**0.5 + 1)):
		if res[i]:
			for j in range(i*i, n + 1, i):
				res[j] = False

	primes = []
	for i in range(2, n + 1):
		if res[i]:
			primes.append(i)

	return primes

if __name__ == "__main__": 
	print(primeSieve(20))