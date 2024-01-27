n = int(input())

indexes = {}

listSort = []

for _ in range(n):
  word = input()

  if word in indexes:
    listSort[indexes[word]][1] += 1 
  else:
    listSort.append([word, 1])
    indexes[word] = len(listSort) - 1

listSort.sort(key= lambda x: x[1], reverse=True)

print('\n'.join([x[0] for x in listSort]))
