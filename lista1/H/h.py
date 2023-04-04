n = int(input())

for i in range(n):
  word = input()
  length = len(word)
  if length > 10:
    print('{}{}{}'.format(word[0], length - 2, word[length - 1]))
  else:
    print(word)
