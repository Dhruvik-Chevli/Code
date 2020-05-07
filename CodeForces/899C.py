from math import ceil
 
n = int(input())
 
if n%4 == 0:
	print(0)
	print(int(n/2),end=" ")
	for i in range(1,int(n/2),2):
		print(i,n+1-i,end=" ")
elif n%2 == 0:
	print(1)
	print(int(n/2),end=" ")
	for i in range(3,int(n/2)+1,2):
		print(i,n+3-i,end=" ")
	print(1)
elif (n-1)%4 == 0:
	print(1)
	print(ceil(n/2),end=" ")
	for i in range(2,int(n/2)+2,2):
		print(i,n+2-i,end=" ")
	print(1)
elif (n-1)%2 == 0:
	print(0)
	print(ceil(n/2),end=" ")
	for i in range(4,int(n/2)+3,2):
		print(i,n+4-i,end=" ")
	print(1,2)