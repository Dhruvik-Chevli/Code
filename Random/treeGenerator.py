from random import randint
from random import random
def makeTree(arr,tree,tn):
    if(tn>=len(arr) or arr[tn]=="NULL"):
        tree.append(-1)
        return tree
    else:
        tree.append(arr[tn])
        tree=makeTree(arr,tree,2*tn)
        tree=makeTree(arr,tree,2*tn+1)
        return tree
n=20 #No of max nodes
limit=1000 #Largest element limit
#f=open("tree.txt","w")
arr=[0]
di={}
elements_guaranteed=3 #Keep this small Otherwise add a dictionary loop
for i in range(elements_guaranteed):
    a=randint(1,1000)
    arr.append(a)
    di[a]=1
i=elements_guaranteed+1
while(i<n):
    if(arr[i//2]=="NULL"):
        arr.append("NULL")
        i+=1
        continue
    a=random()
    if a>0.99:  #Decides the frequecy of Null pointers
        arr.append("NULL")
    else:
        b=randint(1,limit)
        count=0
        while(di.get(b,0)!=0 and count<limit):
            count+=1
        if(count<limit):
            arr.append(b)
        else:
            arr.append("NULL")
        di[b]=1
    i+=1
tree=[]
tree=makeTree(arr,tree,1)
f=open("input0_.txt","w") #change the input file name
for i in tree:
    f.write(str(i)+" ")
f.write("\n")
f.close()