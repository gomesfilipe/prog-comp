n = int(input())

words = [input() for _ in range(n)]

words.sort(key = lambda x: (len(x), x))

print('\n'.join(words))
