nums = [int(i) for i in input().split()]

carta = {
    1: "Às",
    2: "2",
    3: "3",
    4: "4",
    5: "5",
    6: "6",
    7: "7",
    8: "8",
    9: "9",
    10: "10",
    11: "Valete",
    12: "Dama",
    13: "Rei"
}

naipe = {
    0: "Paus",
    1: "Ouro",
    2: "Coração",
    3: "Espada"
}

print(f"{carta[nums[1]]} de {naipe[nums[0]]}")
