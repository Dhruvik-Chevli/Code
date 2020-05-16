#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int boy;
    cin>>boy;
    int arr_boy[boy];
    for(int i=0; i<boy; i++)
        cin>>arr_boy[i];
    sort(arr_boy,arr_boy+boy);
    int girl;
    cin>>girl;
    int arr_girl[girl];
    for(int i=0; i<girl; i++)
        cin>>arr_girl[i];
    sort(arr_girl,arr_girl+girl);
    int counter=0;
    for(int i=0; i<boy; i++)
    {
        for(int j=0; j<girl; j++)
        {
            if(abs(arr_boy[i]-arr_girl[j])<2)
            {
                counter++;
                arr_girl[j]=1000;
                break;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}