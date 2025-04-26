#include <iostream>
#include <vector>

using namespace std;

// TC -> O(N*N)
// SC -> O(1)
int MaxConsecutive_1s_With_k_Os_Sol1(vector<int>Arr,int k)
{
    int n = Arr.size();

    int max_len=0;
    for(int i=0;i<n;i++)
    {
        int len=0;
        int max_k=0;
        for(int j=i;j<n;j++)
        {
            if(Arr[j]==1)
                len++;
            else if(Arr[j]==0 && max_k<k)
            {
                max_k++;
                len++;
            }
            else
            {
                max_len = max(max_len,len);
                cout << "len=" << len << " max_len=" << max_len << endl;
                break;
            }
        }
    }
    return max_len;
}
// TC -> O(N)+O(N)
// SC -> O(1)
int MaxConsecutive_1s_With_k_Os_Sol2(vector<int>Arr,int k)
{
    int n = Arr.size();
    int l=0;
    int r=0;

    int max_len=0,len=0,Zeros=0;
    while(r<n)
    {
       if(Arr[r]==0)
           Zeros++;

       while(Zeros>k)
       {
           if(Arr[l]==0)
           {
               Zeros--;
           }
           l++;
       }

        len = r-l+1;
        max_len = max(max_len,len);
        r=r+1;
    }
    return max_len;

}

// TC -> O(N)
// SC -> O(1)
int MaxConsecutive_1s_With_k_Os_Sol3(vector<int>Arr,int k)
{
    int n = Arr.size();
    int l=0;
    int r=0;

    int max_len=0,len=0,Zeros=0;
    while(r<n)
    {
       if(Arr[r]==0)
           Zeros++;

       if(Zeros>k)
       {
           if(Arr[l]==0)
           {
               Zeros--;
           }
           l++;
       }

       if(Zeros<=k)
       {
            len = r-l+1;
            max_len = max(max_len,len);
       }
       r=r+1;
    }
    return max_len;

}

int main()
{
    vector<int> Arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    int ans1 = MaxConsecutive_1s_With_k_Os_Sol1(Arr,k);
    cout << "Using Sol1 MaxConsecutive 1s With k O's =" << ans1 << endl;

    int ans2 = MaxConsecutive_1s_With_k_Os_Sol2(Arr,k);
    cout << "Using Sol2 MaxConsecutive 1s With k O's =" << ans2 << endl;

    int ans3 = MaxConsecutive_1s_With_k_Os_Sol3(Arr,k);
    cout << "Using Sol3 MaxConsecutive 1s With k O's =" << ans3 << endl;

    return 0;
}
