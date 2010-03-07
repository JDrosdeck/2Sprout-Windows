import random

f= open('links.txt', 'r')
g = open('randomLinks.txt', 'w')
y =  f.readlines()

items = []

for line in y:
    items.append(line)

while len(items) != 0:
    index = random.randint(0,len(items)-1)
    print index
    print len(items)
    g.writelines(items[index])
    items.remove(items[index])

g.close()
f.close()


