x=int(input())
lst=[]
for _ in range(x):
    z=int(input())
    if z<10:
        lst.append('What an obedient servant you are!')
    else:
        lst.append('-1')
for i in lst:
    print(i)            
