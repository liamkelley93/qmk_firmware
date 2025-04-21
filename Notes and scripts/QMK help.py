def intToKeys(n,id):
    toprow = [str(n) for n in range(32 + 32*id,32*id,-1)]
    print(" ".join(toprow))
    num = bin2(n)
    spacing = [len(n) for n in toprow]
    bottomrow = [" " * spacing[i] + num[i]  for i in range(32)]
    bottomrowstring = "".join(bottomrow)
    print(bottomrowstring[1:])

def keysToInt(keys):
    ids = [0,0,0,0]
    for n in keys:
        ids[(n - 1) // 32] += 2 ** ((n - 1) % 32)
    print(", ".join([".id" + str(n) + " = " + str(ids[n]) for n in range(len(ids))]))

def reverseInt(keys):
    ids = [2**32 - 1,2**32 - 1,2**32 - 1,2**23 - 1]
    for n in keys:
        ids[(n - 1) // 32] -= 2 ** ((n - 1) % 32)
    print(", ".join([".id" + str(n) + " = " + str(ids[n]) for n in range(len(ids))]))
