s = input()
key = int(input())

for i in range(len(s)):
    if ord(s[i]) >= ord('A') and ord(s[i]) <= ord('Z'):
        print(chr(((ord(s[i]) - ord('A') + key) % 26) + ord('A')), end='')
    elif ord(s[i]) >= ord('a') and ord(s[i]) <= ord('z'):
        print(chr(((ord(s[i]) - ord('a') + key) % 26) + ord('a')), end='')
    else:
        print(s[i], end='')
print()