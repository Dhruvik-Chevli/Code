f=open("input1.txt","w")
for i in range(0,6):
    for j in range(0,6):
        for k in range(0,6):
            f.write(str(3)+"\n")
            f.write(str(i)+" "+str(j)+" "+str(k)+"\n")
f.close()