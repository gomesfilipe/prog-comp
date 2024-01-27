def nextIndex(numbers, index, p):
  return (index + p) % len(numbers)

try:
  while(True):
    a, p = [int(x) for x in input().split()]

    people = list(range(1, a + 1))
    people[-1] = 0

    current = -1
    before = -2
    while current != people[current]:
      for _ in range(p):
        before = current
        current = people[current]
      
      people[before] = people[current]
    
    print(people[current] + 1)

except Exception as e:
  pass