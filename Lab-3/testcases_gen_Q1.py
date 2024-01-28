output_file = "test_cases_Q1.txt"
file=open(output_file, "w")
file.write(str(3)+"\n")
import random

for i in range (3):
    n = random.randint(2, 30)
    m = random.randint(2, 30)
    k = random.randint(2, 30)
    file.write(str(n)+" "+str(m)+" "+str(m)+" "+str(k)+"\n\n")
    for i in range(n):
        for j in range(m):
            file.write(f"{random.randint(-100,100)} ")
        file.write("\n")
    file.write("\n")
    for i in range(m):
        for j in range(k):
            file.write(f"{random.randint(-100,100)} ") 
        file.write("\n")
    file.write("\n")
file.close()
