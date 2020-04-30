x=int(input())
for _ in range(x):
    z=''
    x=input()
    y=input()
    i=0
    while i<len(x):
        if x[i]=='B' and y[i]=='B':
            z=z+'W'
        elif x[i]=='W' and y[i]=='W':
            z=z+'B'
        else:
            z=z+'B'
        i+=1    
    print(z)
