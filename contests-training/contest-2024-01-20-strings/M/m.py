e = input().split("@")

full = "_.1234567890abcdefghijklmnopqrstuvwxyz"

if len(e) != 2 or len(e[0]) == 0 or len(e[1]) == 0:
    print(0)
    exit()

if e[1][len(e[1])-1] == ".":
    print(0)
    exit()

for i in e[0]:
    if i not in full:
        print(0)
        exit()

for i in e[1]:
    if i not in full[1:]:
        print(0)
        exit()

print(1)