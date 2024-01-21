from random import randint
file = open("test_cases_Q2.txt", "w")
tests = 5

file.write(f"{tests}\n")

for tt in range(tests):
    n = randint(1,5)*100000
    m = randint(1,5)*100000

    file.write(f"{n+m} {n}\n")

    a = []
    b = []

    for i in range(n):
        a.append(randint(1, n))

    for j in range(m):
        b.append(randint(1, m))

    a.sort()
    b.sort()

    astr = " ".join(str(i) for i in a)
    bstr = " ".join(str(i) for i in b)

    file.write(f"{astr}\n{bstr}\n")
