x=int(input())
for _ in range(x):
    z=int(input())
    if z>2001:
        days=0
        while z>2001:
            if z%4!=0:
                z=z-1
                days=days+365
            elif z%4==0:
                if z%100==0:
                    if z%400!=0:
                        z=z-1
                        days=days+365
                    elif z%400==0:
                        z=z-1
                        days=days+366
                else:
                    z=z-1
                    days=days+366
        days=days+364
        if days%7==0:
            print('monday')
        elif days%7==1:
            print('tuesday')
        elif days%7==2:
            print('wednesday')
        elif days%7==3:
            print('thursday')
        elif days%7==4:
            print('friday')
        elif days%7==5:
            print('saturday')
        elif days%7==6:
            print('sunday')
        continue
    if z<2001:
        days=0
        while z<2001:
            if z%4!=0:
                z=z+1
                days=days+365
            elif z%4==0:
                if z%100==0:
                    if z%400!=0:
                        z=z+1
                        days=days+365
                    elif z%400==0:
                        z=z+1
                        days=days+366
                else:
                    if z<2000:
                        z=z+1
                    days=days+366
        l=days%7
        if l==0:
            print('monday')
        elif 7-l==1:
            print('tuesday')
        elif 7-l==2:
            print('wednesday')
        elif 7-l==3:
            print('thursday')
        elif 7-l==4:
            print('friday')
        elif 7-l==5:
            print('saturday')
        elif 7-l==6:
            print('sunday')
    else:
        print('monday')
