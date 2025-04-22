#include <iostream>
#include <vector>

/*

    Arr = {-1,2,3,4,1,-4,-2,6,2,5}  , K=4 Window Size , Find Max Sum WIndow ?
                                    sum
    Elements are : -1,2,3,4         8
                    2,3,4,1         10
                    3,4,1,-4        4
                    4,1,-4,-2       -1
                    1,-4,-2,6        1
                    -4,-2,6,2        2
                    -2,6,2,5        11
*/
using namespace std;

int findMaxSum_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int max_sum = -1e9;
    for(int i=0;i<=n-k;i++)
    {
        int sum = 0;
        for(int j=i;j<i+k;j++)
        {
            sum+=Arr[j];
        }
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}
int Sum_Arr_elements(vector<int>& Arr,int start,int ends)
{
    int sum=0;
    for(int i=start;i<=ends;i++)
    {
        sum+=Arr[i];
    }
    return sum;
}
int findMaxSum_Sol2(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int l = 0;
    int r = k-1;
    int max_sum = -1e9;
    int sum = Sum_Arr_elements(Arr,l,r);
    while(r<n)
    {
        cout << "sum =" << sum << endl;
        max_sum = max(max_sum,sum);
        sum=sum-Arr[l]; // Remove sum from left so that window width is maintained
        l++;
        r++;
        sum=sum+Arr[r];
    }
    return max_sum;
}
int main()
{
    cout << "Max Sum in Siding Window" << endl;

    vector<int> Arr ={-1,2,3,4,1,-4,-2,6,2,5};
    int k = 4;

    int ans_1 = findMaxSum_Sol1(Arr,k);
    cout << "Max Sum Using Sol1 =" << ans_1 << endl;


    int ans_2 = findMaxSum_Sol2(Arr,k);
    cout << "Max Sum Using Sol2 =" << ans_2 << endl;

    return 0;
}
