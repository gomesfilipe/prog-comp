def pi(p, q):
  return p[0] * q[0] + p[1] * q[1]

n = int(input())

for i in range(n):
  xa, ya, xb, yb, xc, yc = [int(x) for x in input().split()]

  v1 = (xa - xb, ya - yb)
  v2 = (xa - xc, ya - yc)
  v3 = (xb - xc, yb - yc)

  if pi(v1, v2) == 0 or pi(v1, v3) == 0 or pi (v2, v3) == 0:
    print('sim')
  else:
    print('nao')