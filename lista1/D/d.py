def nextSoldier(current, a, b, n):
  return (a * current * current + b) % n

while True:
  try:
    n, a, b = input().split()
    n = int(n)
    a = int(a)
    b = int(b)
    lebre = 0
    tartaruga = 0

    lebre = nextSoldier(nextSoldier(lebre, a, b, n), a, b, n)
    tartaruga = nextSoldier(tartaruga, a, b, n)

    while(lebre != tartaruga):
      lebre = nextSoldier(nextSoldier(lebre, a, b, n), a, b, n)
      tartaruga = nextSoldier(tartaruga, a, b, n)

    lebre = 0

    while(lebre != tartaruga):
      lebre = nextSoldier(lebre, a, b, n)
      tartaruga = nextSoldier(tartaruga, a, b, n)

    cicleSize = 1
    cicleStart = lebre
    lebre = nextSoldier(lebre, a, b, n)
    
    while(lebre != cicleStart):
      lebre = nextSoldier(lebre, a, b, n)
      cicleSize += 1

    print(n - cicleSize)
    
  except Exception as e:
    break
  