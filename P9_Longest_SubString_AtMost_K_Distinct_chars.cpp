#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

// TC -> O(N*N)
// SC -> O(k)
int LongestSubstring_K_Unique_char_Sol1(string str,int k)
{
    int n = str.size();
    int len=0,max_len=0;
    for(int i=0;i<n;i++)
    {
        set<char> S;
        for(int j=i;j<n;j++)
        {
            S.insert(str[j]);
            if(S.size()>k)
            {
                break;
            }
            else
            {
                len = j-i+1;
                max_len = max(max_len,len);
            }
        }
    }
    return max_len;
}

// TC -> O(N)+O(N)
// SC -> O(k)
int LongestSubstring_K_Unique_char_Sol2(string str,int k)
{
    int n = str.size();
    int l=0,r=0;
    int len=0,max_len=0;
    unordered_map<char,int> Mp; // char and Freq
    while(r<n)
    {
        Mp[str[r]]++;
        if(Mp.size()>k)
        {
            while(Mp.size()>k)
            {
                Mp[str[l]]--;
                if(Mp[str[l]]==0)
                    Mp.erase(str[l]);
                l++;
            }
        }

        if(Mp.size()<=k)
        {
            len = r-l+1;
            max_len = max(max_len,len);
        }
        r++;
    }
    return max_len;
}

// TC -> O(N)
// SC -> O(k)
int LongestSubstring_K_Unique_char_Sol3(string str,int k)
{
    int n = str.size();
    int l=0,r=0;
    int len=0,max_len=0;
    unordered_map<char,int> Mp; // char and Freq
    while(r<n)
    {
        Mp[str[r]]++;
        if(Mp.size()>k)
        {
            Mp[str[l]]--;
            if(Mp[str[l]]==0)
                Mp.erase(str[l]);
            l++;
        }

        if(Mp.size()<=k)
        {
            len = r-l+1;
            max_len = max(max_len,len);
        }
        r++;
    }
    return max_len;
}

int main()
{
    string str = "aaabbccd";
    int k = 2;
    int ans1 = LongestSubstring_K_Unique_char_Sol1(str,k);
    cout << "Using Sol 1 Longest Substring Atmost K Unique char = " << ans1 << endl;

    int ans2 = LongestSubstring_K_Unique_char_Sol2(str,k);
    cout << "Using Sol 2 Longest Substring Atmost K Unique char = " << ans2 << endl;

    int ans3 = LongestSubstring_K_Unique_char_Sol3(str,k);
    cout << "Using Sol 3 Longest Substring Atmost K Unique char = " << ans3 << endl;

    return 0;
}
