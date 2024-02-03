n = int(input())

for i in range(n):
  a, x1, x2 = [float(x) for x in input().split()]
  print(a > x1 and a < x2)
