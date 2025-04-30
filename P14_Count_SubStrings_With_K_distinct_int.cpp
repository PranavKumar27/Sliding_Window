#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

void print_SubArray(vector<int>& Arr,int s,int e)
{
    for(int i=s;i<=e;i++)
        cout << Arr[i] << ",";
    cout << endl;
}

// TC -> O(N*N)
// SC -> O(N) if all numbers are unique
int Count_SubArray_K_Distinct_Integers_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        set<int> S;
        for(int j=i;j<n;j++)
        {
            S.insert(Arr[j]);
            if(S.size()==k)
            {
                print_SubArray(Arr,i,j);
                cnt++;
            }
            if(S.size()>k)
               break;
        }
    }
    return cnt;
}



int Count_SubArray_Less_Than_Equal_To(vector<int>& Arr,int k)
{
    int l=0,r=0;
    int n = Arr.size();
    int cnt = 0;
    unordered_map<int,int> Mp; // {key,Freq}
    while(r<n)
    {
        Mp[Arr[r]]++;
        while(Mp.size()>k)
        {
            Mp[Arr[l]]--;
            if(Mp[Arr[l]]==0)
               Mp.erase(Arr[l]);
            l++;
        }
        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
}

// TC --> O(2N) + O(2N_  ~~ O(4N)
// SC --> O(N) for Map
int Count_SubArray_K_Distinct_Integers_Sol2(vector<int>& Arr,int k)
{
    int res1 = Count_SubArray_Less_Than_Equal_To(Arr,k);
    int res2 = Count_SubArray_Less_Than_Equal_To(Arr,k-1);

    return (res1-res2);
}

int main()
{
    vector<int> Arr = {1,2,1,3,4};
    int k= 3;
    int ans1 = Count_SubArray_K_Distinct_Integers_Sol1(Arr,k);
    cout << "Using Sol 1 Count SubArray K Distinct Integers =" << ans1 << endl;

    int ans2 = Count_SubArray_K_Distinct_Integers_Sol2(Arr,k);
    cout << "Using Sol 2 Count SubArray K Distinct Integers =" << ans2 << endl;

    return 0;
}
