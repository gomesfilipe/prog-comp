n = int(input())

final = {}
teams = set()

for i in range(n):
  team = input()
  if team in teams:
    final[team] += 1
  else:
    final[team] = 1
    teams.add(team)

if len(teams) == 1:
  print(list(teams)[0])
  exit()

team1 = list(teams)[0]
team2 = list(teams)[1]
    
if(final[team1] > final[team2]):
  print(team1)
else:
  print(team2)
