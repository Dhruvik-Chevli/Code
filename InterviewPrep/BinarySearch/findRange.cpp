int findFirst(const vector<int>&A, int B,int n,int sta,int end)
{
    if(end>=sta)
    {
        int mid=sta+(end-sta)/2;
        if((mid==0||A[mid-1]<B)&&A[mid]==B)
        {
            return mid;
        }
        else if(A[mid]<B)
        {
            return findFirst(A,B,n,mid+1,end);
        }
        else
        {
            return findFirst(A,B,n,sta,mid-1);
        }
    }
    return -1;
}
  
int findLast(const vector<int>&A, int B, int n, int sta, int end)
{
    if(end>=sta)
    {
        int mid=sta+(end-sta)/2;
        if((mid==n-1||A[mid+1]>B)&&A[mid]==B)
        {
            return mid;
        }
        else if(A[mid]>B)
        {
            return findLast(A,B,n,sta,mid-1);
        }
        else
        {
            return findLast(A,B,n,mid+1,end);   
        }
    }
    return -1;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n=A.size();
    int a=findFirst(A,B,n,0,n-1);
    int b=findLast(A,B,n,0,n-1);
    vector<int>ans(2,0);
    ans[0]=a;
    ans[1]=b;
    return ans;
}
