m, s = [int(x) for x in input().split()]

m += s / 60

print(f'{m / 10:.1f}')
print(f'{m * 2.1:.1f}')
