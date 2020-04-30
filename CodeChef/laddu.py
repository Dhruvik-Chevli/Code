x=int(input())
for _ in range(x):
    z=input().split()
    n=int(z[0])
    o=str(z[1])
    dc={'CONTEST_WON':0,'TOP_CONTRIBUTOR':0,'BUG_FOUND':0,'CONTEST_HOSTED':0}
    for u in range(n):
        s=input().split()
        if len(s)==1:
            if s[0]=='TOP_CONTRIBUTOR':
                dc['TOP_CONTRIBUTOR']=dc['TOP_CONTRIBUTOR']+300
            elif s[0]=='CONTEST_HOSTED':
                dc['CONTEST_HOSTED']=dc['CONTEST_HOSTED']+50
        if len(s)==2:
            if s[0]=='CONTEST_WON':
                if int(s[1])<=20:
                    dc['CONTEST_WON']=dc['CONTEST_WON']+300+20-int(s[1])
                else:
                    dc['CONTEST_WON']=dc['CONTEST_WON']+300
            elif s[0]=='BUG_FOUND':
                dc['BUG_FOUND']=dc['BUG_FOUND']+int(s[1])
    lst=dc.values()
    k=sum(lst)
    if o=='INDIAN':
        k=k//200
    elif o=='NON_INDIAN':
        k=k//400
    print(k)
