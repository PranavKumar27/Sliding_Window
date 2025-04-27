#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


// TC -> O(N*N) + Log3 for Set insertion
// SC -> O(3)
int Max_fruits_in_basket_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int len=0,max_len=0;
    for(int i=0;i<n;i++)
    {
        set<int> S;
        for(int j=i;j<n;j++)
        {
            S.insert(Arr[j]);
            if(S.size()<=k)
            {
                len = j-i+1;
                max_len = max(max_len,len);
            }
            else
                break;
        }
    }
    return max_len;
}

// TC -> O(N+N)
// SC -> O(3)
int Max_fruits_in_basket_Sol2(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int l=0,r=0;
    int len=0,max_len=0;
    unordered_map<int,int> Mp;
    while(r<n)
    {
        Mp[Arr[r]]++;
        if(Mp.size()>k)
        {
            while(Mp.size()>k)
            {
                //auto itr = Mp.find(Arr[l]);
                //if(itr!=Mp.end())
                //{
                    //cout << "Arr[l]=" << Arr[l] << endl;
                    Mp[Arr[l]]--;
                    if(Mp[Arr[l]]==0)
                        Mp.erase(Arr[l]);
                //}
                    l++;
            }
        }


        if(Mp.size()<=k)
        {
            len = r-l+1;
            max_len = max(max_len,len);
        }
        r++;
    }
    return max_len;
}


// TC -> O(N)
// SC -> O(3)
int Max_fruits_in_basket_Sol3(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int l=0,r=0;
    int len=0,max_len=0;
    unordered_map<int,int> Mp;
    while(r<n)
    {
        Mp[Arr[r]]++;
        if(Mp.size()>k)
        {
            Mp[Arr[l]]--;
            if(Mp[Arr[l]]==0)
                Mp.erase(Arr[l]);
            l++;
        }
        if(Mp.size()<=k)
        {
            len = r-l+1;
            max_len = max(max_len,len);
        }
        r++;
    }
    return max_len;
}

int main()
{
    vector<int> Arr = {3,3,3,1,2,1,1,2,3,3,4};
    int k = 2; // No of Bags
    int ans1 = Max_fruits_in_basket_Sol1(Arr,k);
    cout << "Using Sol 1 Max fruits in basket=" << ans1 << endl;

    int ans2 = Max_fruits_in_basket_Sol2(Arr,k);
    cout << "Using Sol 2 Max fruits in basket=" << ans2 << endl;

    int ans3 = Max_fruits_in_basket_Sol3(Arr,k);
    cout << "Using Sol 3 Max fruits in basket=" << ans3 << endl;

    return 0;
}
