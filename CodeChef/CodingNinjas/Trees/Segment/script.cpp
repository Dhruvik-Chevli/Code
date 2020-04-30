from random import seed
from random import randint

 
nf  = 6

def generate():
	for i in range(1,nf+1):
		f = open("input0{}.txt".format(i),"w+")
		TC = randint(1, 10)
		f.write(str(TC))
		for j in range(TC):
			#Writing the generated data in the file 
			f.write("\n")
			N = randint(1,10000)
			f.write(str(N))
			f.write("\n")
			for k in range(N):
				f.write(str(randint(1,100000)))
				f.write(" ")
			f.write("\n")
	f.close()

# this is kinda like int main() in c++
if __name__ == "__main__": 
	generate()


#You can customize the code according to the question , even generate random strings.
