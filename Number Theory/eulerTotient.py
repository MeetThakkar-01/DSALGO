# Time Complexity = O(NLog(Log(N)))

# Similar To Prime Sieve

def eulerTotient(n):
	res = [i for i in range(n + 1)]
	for i in range(2, n + 1):
		if res[i] == i:
			res[i] = res[i] - 1
			for j in range(2*i, n + 1, i):
				res[j] *= (i - 1) / i
				res[j] = int(res[j])
	return res

if __name__ == "__main__": 
	print(eulerTotient(10))