def fibonacci(n):
  return int((((1 + 5 ** 0.5) / 2) ** n - ((1 - 5 ** 0.5) / 2) ** n) / (5 ** 0.5))

n = int(input())
print(fibonacci(n))
