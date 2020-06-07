#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int flag = 0;
        vector<int> mapA[26];
        vector<int> mapB[26];
        for (int i = 0; i < n; i++)
        {
            if((int)b[i] > (int)a[i])
            {
                flag = 1;
                break;
            }
            else
            {
                mapA[(int)a[i]-'a'].push_back(i);
                mapB[(int)b[i]-'a'].push_back(i);
            }
        }
        if(flag == 1)
        {
            cout<<-1<<"\n";
            continue;
        }
        vector<vector<int>> res(26);
        int j = 0;
        flag = 0;
        for (int i = 25; i >= 0; i--)
        {
            if(mapB[i].size() != 0)
            {
                if(mapA[i].size() == 0)
                {
                    cout<<-1<<"\n";
                    flag = 1;
                    break;
                }
                else
                {
                    int flag2 = 0;
                    for (int l = 0; l < mapB[i].size(); l++)
                    {
                        if(find(mapA[i].begin(), mapA[i].end(), mapB[i][l]) == mapA[i].end())
                        {
                            flag2 = 1;
                            break;
                        }
                    }
                    if (flag2 == 1)
                    {
                        res[j] = mapB[i];
                        std::vector<int>::iterator it;
                        it = std::find(res[j].begin(), res[j].end(), mapA[i][0]);
                        if (it == res[j].end())
                            res[j].push_back(mapA[i][0]);
                        j++;
                    }
                    
                }
                
            }
        }
        if(flag == 0)
        {
            int count = 0;
            for (int i = 0; i < j; i++)
            {
                if(res[i].size() != 1)
                {
                    count++;
                }
            }
            cout<<count<<"\n";
            for (int i = 0; i < j; i++)
            {
                if (res[i].size() != 1)
                {
                    cout << res[i].size() << " ";
                    vector<int>::iterator ip;
                    // ip = std::unique(res[i].begin(), res[i].end());
                    // res[i].resize(std::distance(res[i].begin(), ip));
                    sort(res[i].begin(), res[i].end());
                    for (ip = res[i].begin(); ip != res[i].end(); ++ip)
                    {
                        cout << *ip << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }
}