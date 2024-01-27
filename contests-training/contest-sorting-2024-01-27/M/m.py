n = int(input())

all_peoples = []

for _ in range(n):
    all_peoples.append(input())

all_peoples.sort()

for a in all_peoples:
    print(a)