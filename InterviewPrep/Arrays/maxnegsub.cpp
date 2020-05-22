vector<int> Solution::maxset(vector<int> &A) {
    int max=0;
    int i=0;
    int cursum=0;
    vector<vector<int> >sub;
    int n=A.size();
    while(i<n)
    {
        int j=i;
        vector<int>cur;
        while(A[j]>=0 and j<n)
        {
            cur.push_back(A[j]);
            j+=1;
        }
        sub.push_back(cur);
        i=j+1;
    }
    vector<int>ansf;
    // for(int i=0;i<sub.size();i++)
    // {
    //     for(int j=0;j<sub[i].size();j++)
    //     {
    //         cout<<sub[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<sub.size();i++)
    {
        int sum=0;
        for(int j=0;j<sub[i].size();j++)
        {
            sum+=sub[i][j];
        }
        if(sum>max)
        {
            ansf=sub[i];
        }
    }
    return ansf;
}