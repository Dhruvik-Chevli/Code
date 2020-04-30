x=int(input())
for _ in range(x):
    co=0
    cb=0
    t=input()
    l=input()
    i=0
    if t[0]=='b' or l[0]=='b':
        if t[1]=='b' or l[1]=='b':
            if t[2]=='o' or l[2]=='o':
                print('yes')
            else:
                print('no')
        elif  t[1]=='o' or l[1]=='o':
            if t[2]=='b' or l[2]=='b':
                print('yes')
            else:
                print('no')
        else:
            print('no')
    elif t[0]=='o' or l[0]=='o':
        if t[1]=='b'or l[1]=='b':
            if t[2]=='b' or l[2]=='b':
                print('yes')
            else:
                print('no')
        else:
            print('no')
    else:
        print('no')                                    
