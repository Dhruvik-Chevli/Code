li=[1,2,3,4]
di={}
for i in li:
    di[i]=di.get(i,0)+1

for i in di.keys():
    print(str(i)+" "+str(di[i]))

op = open("input00.txt",w)