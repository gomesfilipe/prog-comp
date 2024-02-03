def gcd(a, b):
  return a if b == 0 else gcd(b, a % b)

n = int(input())

for i in range(n):
  a, b = [int(x) for x in input().split()]
  print(gcd(a, b))
