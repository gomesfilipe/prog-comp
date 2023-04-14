def create_contestant(contestant):
  return {
    'contestant': contestant,
    'questions': 0,
    'time': 0,
    'trys': [0 for x in range(9)]
  }

def submission(contestant, problem, time, l, contestants):
  if contestant in contestants: # se ja submeteu alguma vez
    if not (l == 'C' or l == 'I'):
      return

    elif l == 'C' and contestants[contestant]['trys'][problem - 1] >= 0: # garante que esta acertando pela primeira vez
      contestants[contestant]['questions'] += 1
      contestants[contestant]['time'] += time + (contestants[contestant]['trys'][problem - 1]) * 20
      contestants[contestant]['trys'][problem - 1] = -1

    elif l == 'I' and contestants[contestant]['trys'][problem - 1] >= 0:
      contestants[contestant]['trys'][problem - 1] += 1

  else: # primeira submissão
    contestants[contestant] = create_contestant(contestant)
    if not (l == 'C' or l == 'I'):
      return
    
    elif l == 'C':
      contestants[contestant]['questions'] += 1
      contestants[contestant]['time'] += time
      contestants[contestant]['trys'][problem - 1] = -1
      
    elif l == 'I':
      contestants[contestant]['trys'][problem - 1] += 1

contestants = {}
n = int(input())
line = input() # \n

for i in range(n):
  while(True):
    try:
      line = input()
      if line == '':
        break
      
      contestant, problem, time, l = line.split()  
      contestant = int(contestant)
      problem    = int(problem)
      time       = int(time)

      submission(contestant, problem, time, l, contestants)
    except:
      break
  
  x = list(contestants.values())
  x = sorted(x, key = lambda d: (-d['questions'], d['time'], d['contestant']))

  for people in x:
    print('{} {} {}'.format(people['contestant'], people['questions'], people['time']))
  
  contestants = {}
  if i != n - 1: # evitando presentation error
    print()
