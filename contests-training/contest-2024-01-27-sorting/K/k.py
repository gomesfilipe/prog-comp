def cmp(x):
    return x[1], x[0]

num_count = {}

n = int(input())

for i in range(n):
    num = int(input())
    if num in num_count:
        num_count[num] += 1
    else:
        num_count[num] = 1

num_items = list(num_count.items())

num_items = sorted(num_items, key=cmp, reverse=True)


print(num_items[0][0], num_items[0][1])