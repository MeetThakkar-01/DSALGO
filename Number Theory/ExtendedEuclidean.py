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
  
  
if __name__ == "__main__": 
    print(extGcd(16, 10).x)
    print(extGcd(16, 10).y)
    print(extGcd(16, 10).gcd)