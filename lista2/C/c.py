def sucessors(line):
  chars = sorted(list(set(line)))

  succ = {}
  length = len(chars)
  for index, c in enumerate(chars):
    if index == length - 1:
      succ[c] = None
    else:
      succ[c] = chars[index + 1]

  return succ

while True:
  line = input()
  if line == '#':
    break
  
  succ = sucessors(line)
  word = [x for x in line]
  stack = []

  noSucc = False

  while True:
    if word == []:
      break
    elif not stack or stack[-1] == max(stack):
      stack.append(word.pop())
    else:
      break
  
  x = stack[-1]

  while(True):
    if succ[x] == None:
      break
    
    try:
      index = stack.index(succ[x])
      aux = stack[index]
      stack[index] = stack[-1]
      stack[-1] = aux

      word.append(stack.pop())
      break
    except:
      x = succ[x]

  stack.sort()

  print(''.join(word + stack)) if ''.join(word + stack) != line else print('No Successor')
