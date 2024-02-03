from math import sqrt

def distance(a1, a2, b1, b2):
  return sqrt((a1 - b1) ** 2 + (a2 - b2) ** 2)

a1 = float(input())
a2 = float(input())
b1 = float(input())
b2 = float(input())

print(f'{distance(a1, a2, b1, b2):.3f}')
