#include <iostream>
#include <vector>
using namespace std;

// Extension of Problem P2 
/*
  *********NOTE: This Technique works only for Positive Integers  **********

 Using Sliding Window Approach Find the Longest SubArray where sum<=k

     Find Longest SubArray {2,3,5,1,2,6,-2} K=12 sum<=

    {2,3,5,1}  sum = 11   Ans = 4
    {3,5,1,2}  sum = 11   Ans = 4


  Use Two Pointer l and r with window size of 1

        {2, 3, 5, 1, 2, 6, -2}
         0  1  2  3  4  5   6    <------ Indexes
                                                            sum = Arr[l...r]
         r
        {2, 3, 5, 1, 2, 6, 2}   Sum = 2 , len = 1 (r-l+1)  sum = Arr[0...0] if(sum<k) move r expand Window
         l

            r
        {2, 3, 5, 1, 2, 6, 2}   Sum = 5 , len = 2 (r-l+1)  sum = Arr[0...1] if(sum<k) move r expand Window
         l

               r
        {2, 3, 5, 1, 2, 6, 2}   Sum =10  , len = 3 (r-l+1)  sum = Arr[0...2] if(sum<k) move r expand Window
         l

                  r
        {2, 3, 5, 1, 2, 6, 2}   Sum =11  , len = 4 (r-l+1)  sum = Arr[0...3] if(sum<k) move r expand Window
         l

                     r
        {2, 3, 5, 1, 2, 6, 2}   Sum =13  , len = 5 (r-l+1)  sum = Arr[0...4] if(sum>k) move l shrink Window
         l

                     r
        {2, 3, 5, 1, 2, 6, 2}   Sum =13-2 = 11 , len = 5 (r-l+1)  sum = Arr[1...4] if(sum<k) move r expand Window
            l

                        r
        {2, 3, 5, 1, 2, 6, 2}   Sum =11+6 = 17 , len = 5 (r-l+1)  sum = Arr[1...5] if(sum>k) move l shrink Window
            l

                        r
        {2, 3, 5, 1, 2, 6, 2}   Sum =17-3 = 14 , len = 4 (r-l+1)  sum = Arr[2...5] if(sum>k) move l shrink Window
               l

                        r
        {2, 3, 5, 1, 2, 6, 2}   Sum =14-5 = 9 , len = 3 (r-l+1)  sum = Arr[3...5] if(sum<k) move r expand Window
                  l

                           r
        {2, 3, 5, 1, 2, 6, 2}   Sum =9+2 = 11 , len = 4 (r-l+1)  sum = Arr[3...6] if(sum<k) move r expand Window Can't move r
                  l

        Hence Max Len Sub Array where Sum <=k is 4.
        NOTE: This Technique works only for Positive Integers
*/

// TC --> O(N+N) = O( N)
int FindMaxLenInSubArray_SumK_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();
    // {2, 3, 5, 1, 2, 6, 2}
    int l = 0,r=0;
    int sum = Arr[0];
    int max_len = -1e9;
    while(l<=r && r<n ) 
    {
        while(sum<=k)
        {
            max_len = max(max_len,r-l+1);
            sum = sum+Arr[r];
            r++;
        }
        else
        {
            sum = sum-Arr[l];
            l++;
        }
    }
    return max_len;

}
// TC --> O(N) = O( N)
int FindMaxLenInSubArray_SumK_Sol2(vector<int>& Arr,int k)  // Optimized
{
    int n = Arr.size();
    // {2, 3, 5, 1, 2, 6, 2}
    int l = 0,r=0;
    int sum = Arr[0];
    int max_len = -1e9;
    while(l<=r && r<n ) 
    {
        if(sum<=k)  // Optimization
        {
            max_len = max(max_len,r-l+1);
            sum = sum+Arr[r];
            r++;
        }
        else
        {
            sum = sum-Arr[l];
            l++;
        }
    }
    return max_len;

}

int main()
{
    int k = 3;
    cout << "Max Len Sub Array whose sum =" << k << endl;
    vector<int> Arr = {1,2,1,2,1};

    int ans  = FindMaxLenInSubArray_SumK(Arr,k);

    cout << "Len of Sub Array = "<< ans << endl;

    return 0;
}
