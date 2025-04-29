#include <iostream>
#include <vector>

using namespace std;

/*
    Given Binary Array (contains 0s and 1s Only)
    arr = [ 1, 0, 1, 0, 1 ]   k = 2


    [ 1, 0, 1, 0, 1 ]
      0  1  2  3  4

      l
    [ 1, 0, 1, 0, 1 ]     sum = 1 == K -> False  cnt =0
      r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 1 == K -> False  cnt =0
         r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 2 == K -> True  cnt =1
            r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 2 == K -> True  cnt = 1 + 1
               r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 3 == K -> False  cnt = 1 + 1  , Move l
                  r

         l
    [ 1, 0, 1, 0, 1 ]     sum = 2 == K -> True  cnt = 1 + 1  , Move r ( r is reached n end )
                  r

    So cnt = 2 , No of subArray Sum = K is 2 which is incorrect

    ********************************************************************************************************************************************************


    Try to find SubArray sum<=k

      l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt =0 + 1
      r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt =0 + 1 + 2  , Here we have two new subArray as {0} and {1,0}
         r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 2 <= K -> True  cnt =0 + 1 + 2 + 3  , Here we have three new subArray as {1} {0,1} {1,0,1}
            r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 2 <= K -> True  cnt = 0 + 1 + 2 + 3 + 4  , Here we have 4 new subArray as {0} {1,0} {0,1,0} {1,0,1,0}
               r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 3 <= K -> False  cnt = 0 + 1 + 2 + 3 + 4  , Move l
                  r

         l
    [ 1, 0, 1, 0, 1 ]     sum = 2 <= K -> True  cnt = 0 + 1 + 2 + 3 + 4 + 4 , Here we have 4 new subArray as {1} {0,1} {1,0,1} {0,1,0,1}
                  r

    So cnt =  14, No of subArray Sum <= K is 14

    ********************************************************************************************************************************************************

    Similarly Find the SubArrays count where sum<=K-1   So K-1 = 1

      l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt =0 + 1
      r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt =0 + 1 + 2  , Here we have two new subArray as {0} and {1,0}
         r

      l
    [ 1, 0, 1, 0, 1 ]     sum = 2 <= K -> False  Move l
            r

         l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt = 0 + 1 + 2 + 2  , Here we have 2 new subArray as {1} {0,1}
            r

         l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt = 0 + 1 + 2 + 2 + 3  , Here we have 2 new subArray as {0} {1,0} ,{0,1,0}
               r

         l
    [ 1, 0, 1, 0, 1 ]     sum = 2 <= K -> False  cnt = 0 + 1 + 2 + 2 + 3  , Move l
                  r


            l
    [ 1, 0, 1, 0, 1 ]     sum = 2 <= K -> False  cnt = 0 + 1 + 2 + 2 + 3  , Move l
                  r

               l
    [ 1, 0, 1, 0, 1 ]     sum = 1 <= K -> True  cnt = 0 + 1 + 2 + 2 + 3 + 2  , Move r  ( r reached End)
                  r


    So cnt =  10, No of subArray Sum <= 1 is 10

    ********************************************************************************************************************************************************

    Difference in cnt
    SubArray_cnt <=2  -  SubArray_cnt <=1 = SubArray_cnt == 2

    14 - 10  = 4

    SubArray
    101..      4 SubArrays
    1010.
    .0101
    ..101
*/
int findSum(vector<int>& Arr,int i,int j)
{
    int Sum = 0;
    for(int s=i;s<=j;s++)
    {
       Sum+=Arr[s];
    }
    return Sum;
}

// TC --> O(N*N*N)
// SC --> O(1)
int findSubArray_Sum_k_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum = findSum(Arr,i,j);
            if(sum==k)
                cnt++;
        }
    }
    return cnt;
}

// TC --> O(N) + O(N) = O(2N)
// SC --> O(1)
int findSubArray_Sum_Less_than_Equal_to_k(vector<int>& Arr,int k)
{
    int l=0,r=0;
    int n = Arr.size();
    int cnt = 0;
    int sum = 0;
    if(k<0)
        return -1;
    while(r<n)
    {
        sum = sum+Arr[r];

        while(sum>k)
        {
            sum = sum-Arr[l];
            l++;
        }
        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
}

// TC --> O(2N) + O(2N) = O(4N)
// SC --> O(1)
int findSubArray_Sum_k_Sol2(vector<int>& Arr,int k)
{
    int res1 = findSubArray_Sum_Less_than_Equal_to_k(Arr,k);
    int res2 = findSubArray_Sum_Less_than_Equal_to_k(Arr,k-1);

    cout << "res1=" << res1 << endl;
    cout << "res2=" << res2 << endl;
    return res1-res2;
}
int main()
{
    vector<int> Arr = {1,0,1,0,1};
    int k = 2;

    int ans1 = findSubArray_Sum_k_Sol1(Arr,k);
    cout << "Using Sol 1 Sub Array_Sum_k =" << ans1 << endl;

    int ans2 = findSubArray_Sum_k_Sol2(Arr,k);
    cout << "Using Sol 2 Sub Array_Sum_k =" << ans2 << endl;

    return 0;
}
