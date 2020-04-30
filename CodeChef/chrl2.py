x=input()
dc={}
dc['C']=0
dc['H']=0
dc['E']=0
dc['F']=0
for i in x:
    if i in dc:
        dc[i]=dc[i]+1        
z=min(dc.values())
print(z)
