import re

words = set()

while(True):
  try:
    line = input()

    if(line == ''):
      continue

    for word in re.split(r'[^a-zA-Z]', line):
      words.add(''.join(filter(str.isalpha, word)).lower())
  
  except Exception as e:
    break

for word in sorted(list(words)):
  if(word != ''):
    print(word)