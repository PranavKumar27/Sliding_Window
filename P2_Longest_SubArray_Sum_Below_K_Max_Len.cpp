#include <iostream>
#include <vector>

using namespace std;

/*
    Longest SubArray with condition

    Find Longest SubArray {2,3,5,1,2,6,-2} K=12 sum<=

    {2,3,5,1}  sum = 11   Ans = 4
    {3,5,1,2}  sum = 11   Ans = 4
  {5,1,2,6,-2} sum = 12   Ans = 5

*/

// TC --> O(N*N*N)
int findLongestSubArrLength_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();

    int max_sum = -1e9;
    int max_len=-1e9;
    for(int i=0;i<n;i++)
    {

        for(int j=i;j<n;j++)
        {
            int sum = 0;
            int len = 0;
            for(int l=i;l<=j;l++)
            {
                sum+=Arr[l];
                len = j-i+1;
            }
            if(sum<=k)
            {
                max_sum = max(sum,max_sum);
                max_len = max(len,max_len);
            }
        }
    }
    cout << "Using Sol1 Max Sum=" << max_sum << " max_len=" << max_len << endl;
    return max_len;
}

// TC --> O(N*N)
int findLongestSubArrLength_Sol2(vector<int>& Arr,int k)
{
    int n = Arr.size();

    int max_sum = -1e9;
    int max_len=-1e9;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        int len = 0;
        for(int j=i;j<n;j++)
        {
            sum+=Arr[j];
            len = j-i+1;

            if(sum<=k && max_sum<=sum && max_len<len)
            {
                max_sum = max(sum,max_sum);
                max_len = max(len,max_len);
            }

        }
    }
    cout << "Max Sum=" << max_sum << " max_len=" << max_len << endl;
    return max_len;
}
int main()
{
    cout << "Longest Sub Array Sum less than K=12" << endl;

    vector<int> Arr = {2,3,5,1,2,6,-2};
    int k=12;
    int ans1 = findLongestSubArrLength_Sol1(Arr,k);
    cout << "ans1=" << ans1 << endl;
    int ans2 = findLongestSubArrLength_Sol2(Arr,k);

    cout << "ans2=" << ans2 << endl;
    return 0;
}
