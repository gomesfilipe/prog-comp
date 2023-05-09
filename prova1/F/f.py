def next(a, b, N, x):
  return ((a * x * x) + b) % N

while True:
  line = input().split(" ")
  N = int(line[0])
  if N == 0:
    break

  a = int(line[1])
  b = int(line[2])

  lebre = next(a, b, N, next(a, b, N, 0))
  turtle = next(a, b, N, 0)

  while lebre != turtle:
    lebre = next(a, b, N, next(a, b, N, lebre))
    turtle = next(a, b, N, turtle)

  qtd = 1
  lebre = next(a, b, N, lebre)
  while turtle != lebre:
    qtd += 1
    lebre = next(a, b, N, lebre)

  print(N - qtd)