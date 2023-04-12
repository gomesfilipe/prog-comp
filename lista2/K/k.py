pares = {
  "{": "}",
  "[": "]",
  "(": ")"
}

n = int(input())
for i in range(n):
  string = input()
  pilha = []
  enter = False

  for c in string:
    if c in pares: # abertura
      pilha.append(c)
      continue
    else: # fechamento
      if pilha:
        if pares[pilha[-1]] == c:
          pilha.pop()
        else:
          break
      else:
        enter = True
        break
        
      

  if(not pilha and not enter): 
    print('YES')
  else:
    print('NO')
