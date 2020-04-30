for _ in range( int(input())):
    di={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0}
    for n in range(int(input())):
        q,s=map(int,input().split())
        if di[q]<s:
            di[q]=s
    sc=0
    for i in range(1,9):
        sc+=di[i]
    print(sc)            