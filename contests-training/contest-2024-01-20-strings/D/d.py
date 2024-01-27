a = input()
b = input()

a_dict = {}
for i in a:
    if i in a_dict:
        a_dict[i] += 1
    else:
        a_dict[i] = 1
b_dict = {}
for i in b:
    if i in b_dict:
        b_dict[i] += 1
    else:
        b_dict[i] = 1

for i in a_dict:
    if i not in b_dict:
        print('nao')
        exit()
    elif a_dict[i] != b_dict[i]:
        print('nao')
        exit()

print('sim')