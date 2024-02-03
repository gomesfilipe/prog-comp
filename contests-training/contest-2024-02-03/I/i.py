v = float(input())
i = int(input())

if i <= 5:
  x = 0.5 * v
elif i > 5 and i < 18:
  x = 0.95 * v
elif i >= 18 and i < 60:
  x = 1.1 * v
else:
  x = 0.85 * v

print(str(x))

print(f'{x:.2f}')
print(f'{x}')
 