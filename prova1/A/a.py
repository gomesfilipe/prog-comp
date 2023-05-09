n = int(input())
vetor = []

for i in range(0, n):
  try:
    num = input().split(' ')
    for numero in num:
        vetor.append(int(numero))
  except:
    break
  
  vetor.sort()
  print('Case ' + str(i + 1) + ': ' + str(vetor[1]))
  vetor.clear()
