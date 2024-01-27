nums = [int(i) for i in input().split()]
mapped = {}

for i in nums:
    mapped[i] = True

nums = [int(i) for i in input().split()]
nums.sort()

for i in nums:
    try:
        if mapped[i] == True:
            print(i, " Está mapeado")

    except:
        print(i, " Não está mapeado")
