words = {}

while True:
  try:
    value, key = input().split()
    words[key] = value
  except:
    break

while True:
  try:
    word = input()
    if word in words:
      print(words[word])
    else:
      print('eh')
  except:
    break
  