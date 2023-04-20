def calculatePercentUnique(case):
  n = int(input())
  uniques = set()
  repeats = set()
  
  friends = []
  for i in range(n):
    x, *stamps = [int(k) for k in input().split()]
    friends.append(set(stamps))
    
    for j in set(stamps):
      if j in repeats:
        repeats.add(j)
      elif j in uniques:
        uniques.remove(j)
        repeats.add(j)
      else:
        uniques.add(j)

  print('Case {}:'.format(case), end=' ')
  if len(uniques) == 0:
    for index, i in enumerate(friends):
      print('{:.6f}%'.format(100 / len(friends)), end='')
      if index != len(friends) - 1:
        print(' ', end='')
    print()
    return

  for index, i in enumerate(friends):  
    print('{:.6f}%'.format(len(i.intersection(uniques)) / len(uniques) * 100), end='')
    if index != len(friends) - 1:
        print(' ', end='')
  print()
  return

t = int(input())

for i in range(t):
  calculatePercentUnique(i + 1)
