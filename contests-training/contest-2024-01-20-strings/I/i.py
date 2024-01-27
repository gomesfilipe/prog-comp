n = int(input())

brincos = {}
pairs = 0

for i in range(n):
  m, l = input().split() 

  if m in brincos:
    brincos[m][l] += 1
  else:
    brincos[m] = {}
    brincos[m]['D'] = 0
    brincos[m]['E'] = 0
    brincos[m][l] += 1

for x in brincos:
  pairs += min([brincos[x]['D'], brincos[x]['E']])

print(pairs)
