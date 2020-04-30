## Read input as specified in the question.
## Print output as specified in the q
import sys
class Graph:
    def __init__(self,nVertices):
        self.nVertices=nVertices
        self.adjMat=[[0 for i in range(nVertices)] for j in range(nVertices)]
    def addEdge(self,v1,v2,wt):
        self.adjMat[v1][v2]=wt
        self.adjMat[v2][v1]=wt
    def __getminVertex(self,visited,weight):
        min_vertex=-1
        for i in range(self.nVertices):
            if (visited[i] is False and (min_vertex==-1 or weight[min_vertex]>weight[i])):
                min_vertex=i
        return min_vertex

    def prims(self):
        visited=[False for i in range(self.nVertices)]
        parent=[-1 for i in range(self.nVertices)]
        weight=[sys.maxsize for i in range(self.nVertices)]
        weight[0]=0
        ans=0
        for i in range(self.nVertices-1):
            min_vertex=self.__getminVertex(visited,weight)
            visited[min_vertex]=True
            for j in range(self.nVertices):
                if self.adjMat[min_vertex][j]>0 and visited[j] is False:
                    if weight[j]>self.adjMat[min_vertex][j]:
                        weight[j]=self.adjMat[min_vertex][j]
                        parent[j]=min_vertex
        for i in range(1,self.nVertices):
            if i<parent[i]:
                print(str(i)+" "+str(parent[i])+" "+str(weight[i]))
            else:
                print(str(parent[i])+" "+str(i)+" "+str(weight[i]))
            ans+=weight[i]
        return ans

v,e=map(int,input().split())
g=Graph(v)
for _ in range(e):
    a,b,n=map(int,input().split())
    g.addEdge(a,b,n)
g.prims()

