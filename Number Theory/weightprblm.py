class triplets:
  def __init__(self):
        self.gcd = None
        self.x = None
        self.y = None


def extGcd(a, b):
  if b == 0:
    ans = triplets()
    ans.gcd = a
    ans.x = 1
    ans.y = 0
    return ans

  ans = extGcd(b, a % b)
  res = triplets()
  res.gcd = ans.gcd
  res.x = ans.y
  res.y = ans.x - (a//b)*ans.y

  return res

def modInv(a, m):
  ans = extGcd(a, m).x
  return (ans % m + m ) % m
  
# Time Complexity : O(max(a, b))
if __name__ == "__main__": 
    for _ in range(int(input())):
      a, b, d = map(int, input().split())

      if d == 0:
        print(1)
        continue
      # if 

      hcf = extGcd(a, b).gcd

      a /= hcf
      b /= hcf
      d /= hcf

      y1 = ((d%a) * modInv(b, a)) % a
      firstValue = d/b

      if d < y1*b:
        print(0)
        continue
      n = (firstValue - y1) // a

      print(int(n + 1))