linha = input()
dicio = {}
while len(linha) > 1:
  splited = linha.split(" ")
  dicio[splited[1]] = splited[0]

  linha = input()

while True:
  try:
    word = input()
  except:
    break
    
  try:
    print(dicio[word])
  except:
    print("eh")
