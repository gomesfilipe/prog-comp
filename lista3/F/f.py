def countMoves():
  n = int(input())
  numbers = set()

  for i in input().split():
    numbers.add(int(i))

  min = 0

  while numbers:
    maxNum = max(numbers)
    numbers.remove(maxNum)
    if maxNum % 2 == 0:
      numbers.add(maxNum // 2)
      min += 1
  
  print(min)

t = int(input())

for i in range(t):
  countMoves()
