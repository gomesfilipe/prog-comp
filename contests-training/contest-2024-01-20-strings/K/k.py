words = input().split()

count = 0

for word in words:
  count += len(word)

print(len(words))
print(count)