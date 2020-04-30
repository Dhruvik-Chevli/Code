x=input()
x=x.split()
n=int(x[0])
k=int(x[1])
i=0
count=0
while i<n:
    x=int(input())
    if x%k==0:
        count+=1
    i+=1
print(count)
