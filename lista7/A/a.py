word = input()

hello = 'hello'
i = 0

for c in word:
  if c == hello[i]:
    i += 1
    if i == 5:
      print('YES')
      break

if i != 5:
  print('NO')
