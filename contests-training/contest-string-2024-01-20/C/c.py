invalid = {
  "da": True,
  "de": True,
  "do": True,
  "dos": True,
  "e": True,
}

names = input().split()
flag = False
abrev = ''

if len(names) == 1 or len(names) == 2:
   print(' '.join(names))
   flag = True

if not flag:
  first = names[0]
  last = names[-1]

  for i in range(1, len(names) - 1):
    if names[i] in invalid:
      continue

    abrev += ' ' + names[i][0] + '.'

  print(first + abrev + ' ' + last)
