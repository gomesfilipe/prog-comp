while(True):
  n = int(input())
  if n == 0:
    break

  countNonZeros = 0
  for i in range(n):
    x = int(input())
    
    if x == 0:
      continue
    
    countNonZeros += 1

    if countNonZeros > 1:
      print(' ', end='')

    print(x, end='')
  
  if countNonZeros == 0:
    print('0', end='')
  
  print()
