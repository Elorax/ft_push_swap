import random
list = []

for i in range(100):
    x = random.randint(0,500)
    while x in (list):
        x= random.randint(0,500)
    list.append(x)
print(list)
