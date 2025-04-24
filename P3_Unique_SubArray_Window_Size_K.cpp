
// Source LeetCode LINK : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/ 
class Solution {
public:
    long long Sum_Arr_elements(vector<int>& Arr,int start,int ends)
    {
        long long sum=0;
        for(int i=start;i<=ends;i++)
        {
            sum+=Arr[i];
        }
        return sum;
    }
    bool IsSubArrayUnique(vector<int>& Arr,int start,int ends)
    {
        set<long long> S;
        int len = ends-start+1;
        for(int i=start;i<=ends;i++)
        {
            S.insert(Arr[i]);
        }
        if(S.size()==len)
            return true;
        else
            return false;
    }
    long long maximumSubarraySum(vector<int>& Arr, int k) {

    int n = Arr.size();
    int l = 0;
    int r = k-1;
    long long max_sum = 0;
    long long sum = Sum_Arr_elements(Arr,l,r);
    while(r<n)
    {
        //cout << "sum =" << sum << endl;
        bool IsUnique = IsSubArrayUnique(Arr,l,r);
        if(IsUnique)
        {
            max_sum = max(max_sum,sum);
            
        }
        sum=sum-Arr[l]; // Remove sum from left so that window width is maintained
            l++;
            r++;
            if(r<n)
                sum=sum+Arr[r];
        
    }
    return max_sum;
    }
};
