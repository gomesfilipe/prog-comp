word = input()

current = word[0]

result = current

for i in range(1, len(word)):
  if word[i] != current:
    current = word[i]
    result += current

print(result)
