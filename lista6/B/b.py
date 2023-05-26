def solve():
  r1, r2 = [int(x) for x in input().split()]
  c1, c2 = [int(x) for x in input().split()]
  d1, d2 = [int(x) for x in input().split()]

  for i in range(1, 10):
    for j in range(1, 10):
      if j == i:
        continue
      for k in range(1, 10):
        if k == i or k == j:
          continue

        if i + j == r1 and i + k == c1 and j + k == d2:
          l = r2 - k
          if l >= 1 and l <= 9 and i + l == d1 and j + l == c2 and k + l == r2 and l != i and l != j and l != k:
            print(f'{i} {j}')
            print(f'{k} {l}')
            return

  print('-1')
  return
  
solve()
