#include <iostream>
#include <vector>
using namespace std;

int findSum(vector<int>& Arr,int start,int ends)
{
    int sum = 0;
    for(int i=start;i<=ends;i++)
        sum+=Arr[i];
    return sum;
}
int findMaxWindow_Sum_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();

    int max_sum = -1e9;
    for(int i=-1;i<k;i++)
    {
        int left_sum=0,right_sum=0;
        if(i>=0)
            left_sum = findSum(Arr,0,i);

        cout << "left_sum=" << left_sum << endl;

        if(n-k+1+i<n)
            right_sum = findSum(Arr,n-k+1+i,n-1);

        cout << "right_sum=" << right_sum << endl;

        int total_sum = left_sum+right_sum;
        cout << "sum=" << total_sum << endl;
        max_sum = max(max_sum,total_sum);
    }
    return max_sum;
}


int findMaxWindow_Sum_Sol2(vector<int>& Arr,int k)
{
   int n = Arr.size();

   long long left_sum=0;
   long long right_sum = 0;
   long long max_sum = -1e9;
   for(int i=0;i<k;i++)
   {
      left_sum+=Arr[i];
   }
   cout << "leftSum =" << left_sum << endl;
   max_sum = left_sum;

   int right_idx=n-1;
   for(int i=k-1;i>=0;i--)
   {
       left_sum = left_sum - Arr[i];
       right_sum =  right_sum + Arr[right_idx];
       cout << "leftSum =" << left_sum << endl;
       cout << "right_sum =" << right_sum << endl;
       right_idx = right_idx-1;

       long long total_sum = left_sum+right_sum;
       cout << "total_sum=" << total_sum << endl;
       max_sum = max(max_sum,total_sum);
   }
   return max_sum;
}


int findMaxWindow_Sum_Sol3(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int l = n-k;
    int r = n-1;

    int sum = findSum(Arr,l,r);
    int max_sum = sum;
    r=(r+1)%n;
    while(r<k && n!=k)
    {
        sum = sum-Arr[l];
        l=(l+1)%n;
        sum = sum+Arr[r];
        r=(r+1)%n;
        cout << "sum=" << sum << endl;
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}
int main()
{
    vector<int> Arr = {9,7,7,9,7,7,9};
    int K = 7;

    //int ans1 = findMaxWindow_Sum_Sol1(Arr,K);
    //cout << "Using Sol 1 Max Window Sum =" << ans1 << endl;

    //int ans2 = findMaxWindow_Sum_Sol2(Arr,K);
    //cout << "Using Sol 2 Max Window Sum =" << ans2 << endl;

    int ans3 = findMaxWindow_Sum_Sol3(Arr,K);
    cout << "Using Sol 3 Max Window Sum =" << ans3 << endl;
    return 0;
}
