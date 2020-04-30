import sys
for _ in range(int(input())):
    n=int(input())
    str1=input()
    di={'a':-1,'b':-1,'c':-1,'d':-1,'e':-1,'f':-1,'g':-1,'h':-1,'i':-1,'j':-1,'k':-1,'l':-1,'m':-1,'n':-1,'o':-1,'p':-1,'q':-1,'r':-1,'s':-1,'t':-1,'u':-1,'v':-1,'w':-1,'x':-1,'y':-1,'z':-1}
    fi=None
    f=None
    mi=sys.maxsize
    for i in range(len(str1)):
        if di[str1[i]]!=-1:
            if i-di[str1[i]]<mi:
                f=i
                fi=di[str1[i]]
                mi=i-fi
                di[str1[i]]=i   
                continue
        di[str1[i]]=i
    if f==None:
        print(0)
    else:
        #print(fi,f)
        print(n-f+fi)