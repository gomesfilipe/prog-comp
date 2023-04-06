def squareFirstNDigits(k, n):
  return int(str(k * k)[0:n:1])

def maior(a, b):
  return a if a > b else b

t = int(input())

for i in range(t):
  n, k = [int(x) for x in input().split()]

  lebre = k
  tartaruga = k
  maximo = k
  
  lebre = squareFirstNDigits(squareFirstNDigits(lebre, n), n) # Andou 2
  tartaruga = squareFirstNDigits(tartaruga, n) # Andou 1

  if maior(lebre, tartaruga) > maximo:
    maximo = maior(lebre, tartaruga)

  while lebre != tartaruga: # Primeiro encontro
    lebre = squareFirstNDigits(squareFirstNDigits(lebre, n), n) # Andou 2
    tartaruga = squareFirstNDigits(tartaruga, n) # Andou 1

    if maior(lebre, tartaruga) > maximo:
      maximo = maior(lebre, tartaruga)

  lebre = k

  while lebre != tartaruga: # Se encontrando no início do ciclo
    lebre = squareFirstNDigits(lebre, n) # Andou 1
    tartaruga = squareFirstNDigits(tartaruga, n) # Andou 1

    if maior(lebre, tartaruga) > maximo:
      maximo = maior(lebre, tartaruga)

  print(maximo)
