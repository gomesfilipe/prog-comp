from math import sqrt, ceil

def x(t, i, a):
  d = (2 * i - a) ** 2 + 8 * a * t

  return (a - 2 * i + sqrt(d)) / (2 * a)

n = int(input())

for i in range(n):
  t, i, a = [int(x) for x in input().split()]
  print(ceil(x(t, i, a)))