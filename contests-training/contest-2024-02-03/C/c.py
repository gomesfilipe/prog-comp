def binaryToDecimal(b):
  d = 0
  s = len(b) - 1
  for i in b:
    if i == '1':
      d += 2 ** s
    s -= 1
  
  return d


n = int(input())

for i in range(n):
  b = input()
  print(binaryToDecimal(b))
