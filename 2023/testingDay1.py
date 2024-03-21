import string

puzzleinput = open("puzzleInput1.dat")
total = 0
for line in puzzleinput:
    first = -1
    last = -1
    for c in line.rstrip():
        if c in string.digits:
            if first == -1:
                first = int(c)
            last = int(c)
    if first != -1:
        total += first*10 + last

print(total)