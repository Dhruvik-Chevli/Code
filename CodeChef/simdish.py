x=int(input())
for _ in range(x):
    a=input().split()
    b=input().split()
    count=0
    for i in a:
        for j in b:
            if i==j:
                count+=1
    if count>=len(a)/2:
        print('similar')
    else:
        print('dissimilar')
