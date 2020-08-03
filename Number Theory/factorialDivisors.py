def get_primes(n):
  m = n+1
  #numbers = [True for i in range(m)]
  numbers = [True] * m #EDIT: faster
  for i in range(2, int(n**0.5 + 1)):
    if numbers[i]:
      for j in range(i*i, m, i):
        numbers[j] = False
  primes = []
  for i in range(2, m):
    if numbers[i]:
      primes.append(i)
  return primes

def divisors(n, primes):

  result = 1
  mod = 10**9 + 7

  for i in range(0, n + 1):
    if primes[i] <= n:
      k = primes[i]
      count = 0

      while (int(n/k) != 0):
        count += (int(n/k)) % mod
        k = k * primes[i]
      result = (result * (count + 1)) % mod

  return result

if __name__ == "__main__": 
    for _ in range(int(input())):
      primes = get_primes(500000)
      n = int(input())
      print(divisors(n, primes))