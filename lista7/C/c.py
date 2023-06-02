def minn(x, y):
  return x if x < y else y

n = int(input())

sa = 0
sg = 0

for i in range(n):
  a, g = [int(x) for x in input().split()]
  diff = abs(sa - sg)

  if(diff < 500):
    if minn(a, g) == a:
      sa += a
      print('A', end='')
    else:
      sg += g
      print('G', end='')
  elif minn(sa, sg) == sa:
    sa += a
    print('A', end='')
  else:
    sg += g
    print('G', end='')

print()
