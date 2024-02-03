a, b, c = [int(x) for x in input().split()]
d, e, f = [int(x) for x in input().split()]

if d * b == e * a:
  print('sistema indeterminado')
else:
  y = (f - d * c / a) / (e - d * b / a)
  x = (c - b * y) / a
  print(f'{x:.2f} {y:.2f}')
