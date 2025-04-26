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

int MaxConsecutive_1s_With_k_Os_Sol2(vector<int>Arr,int k)
{
    int n = Arr.size();
    int l=0;
    int r=0;

    int max_len=0,len=0,max_k=0;
    while(l<=r && r<n)
    {
       if(Arr[r]==1)
        r++;
       else if(Arr[r]==0 && max_k<k)
       {
           r++;
           max_k++;
           cout << "** l=" << l << " r=" << r << endl;
           if(max_k==k)
           {
               len = r-l;
               max_len = max(max_len,len);
               max_k=0;
               l=r;
           }
       }
       else
       {
           cout << "l=" << l << " r=" << r << endl;
           len = r-l;
           max_len = max(max_len,len);
           max_k=0;
           l=r;
       }
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

    return 0;
}
