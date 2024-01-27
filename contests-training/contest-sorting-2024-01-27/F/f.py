n = int(input())

all_peoples = []

for i in range(n):
    line = input().split(',')
    all_peoples.append(line)

def custom_sort(x):
    return -int(x[1]), x[0]

sorted_peoples = sorted(all_peoples, key=custom_sort)

for i in sorted_peoples:
    print(i[0])
