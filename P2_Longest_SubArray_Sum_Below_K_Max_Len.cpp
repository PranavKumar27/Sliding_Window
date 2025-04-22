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

int findLongestSubArrLength(vector<int>& Arr,int k)
{
    int n = Arr.size();

    int max_sum = -1e9;
    int max_len=-1e9;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=Arr[k];
            }
            if(sum<=k && sum>=max_sum && max_len<j-i+1)
            {
                max_sum = sum;
                max_len = j-i+1;
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
    int ans = findLongestSubArrLength(Arr,k);

    return 0;
}
