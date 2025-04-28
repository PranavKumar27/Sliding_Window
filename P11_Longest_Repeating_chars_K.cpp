#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findLongest_Repeating_CharSubstring_Replace_k_Char_Sol1(string str,int k)
{
    unordered_map<char,int> Mp;

    int n = str.size();
    int len,max_len=0;
    int max_freq=0;

    for(int i=0;i<n;i++)
    {
        unordered_map<char,int> Mp;
        for(int j=i;j<n;j++)
        {
            Mp[str[j]]++;
            //cout << "str[j]=" << str[j] << " Mp[str[j]] =" << Mp[str[j]] << endl;

            max_freq = max(max_freq,Mp[str[j]]);

            len = j-i+1;
            int changes = len-max_freq;

            if(changes<=k)
            {
                len = j-i+1;
                max_len = max(max_len,len);
            }
            else
            {
                break;
            }
        }
    }
    return max_len;
}

// TC --> O(N+N) * O(26)
// SC -> O(26)
int findLongest_Repeating_CharSubstring_Replace_k_Char_Sol2(string str,int k)
{
    int n = str.size();
    int l=0,r=0;
    int len,max_len=0;
    unordered_map<char,int> Mp;
    int max_freq=0;
    while(r<n)
    {
        Mp[str[r]]++;
        max_freq = max(max_freq,Mp[str[r]]);



        while( (r-l+1) - max_freq >k)
        {
            Mp[str[l]]--;
            // Update the max_freq
            max_freq=0;
            for(auto d:Mp)
            {
                max_freq = max(max_freq,d.second);
            }
            l++;
        }
        len = r-l+1;
        int changes = len-max_freq;
        if(changes<=k)
        {
            len = r-l+1;
            max_len = max(max_len,len);
        }
        r++;
    }
    return max_len;
}

// TC --> O(N) * O(26)
// SC -> O(26)
int findLongest_Repeating_CharSubstring_Replace_k_Char_Sol3(string str,int k)
{
    int n = str.size();
    int l=0,r=0;
    int len,max_len=0;
    unordered_map<char,int> Mp;
    int max_freq=0;
    while(r<n)
    {
        Mp[str[r]]++;
        max_freq = max(max_freq,Mp[str[r]]);

        len = r-l+1;
        int changes = len-max_freq;

        if(changes>k)
        {
            Mp[str[l]]--;
            // Update the max_freq
            max_freq=0;
            for(auto d:Mp)
            {
                max_freq = max(max_freq,d.second);
            }
            l++;
        }
        else
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
    string str = "AABABBA";
    int k=2;
    int ans1 = findLongest_Repeating_CharSubstring_Replace_k_Char_Sol1(str,k);
    cout << "Using Sol 1 Longest_Repeating_CharSubstring_Replace_k_Char =" << ans1 << endl;

    int ans2 = findLongest_Repeating_CharSubstring_Replace_k_Char_Sol2(str,k);
    cout << "Using Sol 2 Longest_Repeating_CharSubstring_Replace_k_Char =" << ans2 << endl;

    int ans3 = findLongest_Repeating_CharSubstring_Replace_k_Char_Sol3(str,k);
    cout << "Using Sol 3 Longest_Repeating_CharSubstring_Replace_k_Char =" << ans3 << endl;

    return 0;
}
