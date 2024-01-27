n = int(input())

for i in range(n):
  word = input()
  mid = len(word) // 2
  
  for j in range(mid - 1, -1, -1):
    print(word[j], end='')
  
  for j in range(len(word) - 1, mid - 1, -1):
    print(word[j], end='')
  print()