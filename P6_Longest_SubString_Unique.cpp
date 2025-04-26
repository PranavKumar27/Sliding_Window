#include <iostream>
#include <string>
#include <map>

using namespace std;

bool IsUnique(string Str,int l,int r)
{
    map<char,int> Mp;
    for(int i=l;i<=r;i++)
    {
        cout << Str[i] << endl;
        if(Mp.find(Str[i])!=Mp.end())
        {
            cout << "Return from " << __FUNCTION__ << endl;
            return false;
        }
        else
        {
            cout << "i=" << i << endl;
            Mp[Str[i]]++;
        }

    }
    cout << "..." << endl;
    return true;
}

// TC -> O(N*N)
// SC -> O(N)
int MaxUniqueSubString_Sol2(string Str)
{
    int n = Str.size();

    int l=0,r=0;
    int len=0;
    int max_len=-1e9;
    while(l<=r && r<n)
    {
        bool res = IsUnique(Str,l,r);
        cout << "res=" << res << endl;
        if(res)
        {
            len=r-l+1;
            r++;
        }
        else
        {
            l++;
            cout << "l increased =" << l << endl;
        }
        max_len = max(len,max_len);

    }

    cout << "l=" << l << " r=" << r << endl;
    return max_len;
}

// TC -> O(N*N)
// SC -> O(N)
int MaxUniqueSubString_Sol1(string Str)
{
    int n = Str.size();
    int max_len=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        map<int,int> Hash;
        for(int j=i;j<n;j++)
        {
            if(Hash[Str[j]]==1) break;

            len = j-i+1;
            cout << "len=" << len << endl;
            max_len = max(max_len,len);
            Hash[Str[j]]++;
        }
    }
    return max_len;
}

// TC -> O(N)
// SC -> O(N)
int MaxUniqueSubString_Sol3(string Str)
{
    int n = Str.size();
    int l=0,r=0;
    int len=0;
    int max_len=0;
    map<char,int> Hash;
    while(r<n)
    {
        if(Hash.find(Str[r]) != Hash.end())
        {
            int idx = Hash[Str[r]];
            if(l<=idx)
            {               // Update L only if idx is in the window of l..idx...r Withing Range of l to r
                l=idx+1;    // Don't update if ....idx....l.....r
            }
        }

        Hash[Str[r]]=r; // Update Always
        len=r-l+1;
        r++;
        max_len = max(len,max_len);

    }

    for(auto d:Hash)
    {
        cout << "key=" << d.first << " val=" << d.second << endl;
    }

    cout << "l=" << l << " r=" << r << endl;
    return max_len;
}

int main()
{
    string str = "aabaab!bb";
    
    int ans1 = MaxUniqueSubString_Sol1(str);
    cout << "Using Sol1 MaxLen of Unique SubString=" << ans1 << endl;

    int ans2 = MaxUniqueSubString_Sol2(str);
    cout << "Using Sol2 MaxLen of Unique SubString=" << ans2 << endl;

    int ans3 = MaxUniqueSubString_Sol3(str);
    cout << "Using Sol3 MaxLen of Unique SubString=" << ans3 << endl;

    return 0;
}
