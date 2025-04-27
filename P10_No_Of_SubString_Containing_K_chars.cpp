#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

// TC --> O(N*N)
// SC -> O(3)
int findAllSubStringsContaining_k_chars_Sol1(string str,int k)
{
    int n = str.size();
    int cnt= 0;
    for(int i=0;i<n;i++)
    {
        set<char> S;
        for(int j=i;j<n;j++)
        {
            S.insert(str[j]);

            if(S.size()==k)
            {
                //cnt++;
                cnt+= n-j;
                break;
            }
        }
    }
    return cnt;
}
// TC --> O(N)
// SC --> O(3)
int findAllSubStringsContaining_k_chars_Sol2(string str,int k)
{
    int n = str.size();
    int l=0,r=0;
    int cnt = 0;
    unordered_map<char,int> Mp;
    while(r<n)
    {
        if(Mp.size()<k)
            Mp[str[r]]++;

        if(Mp.size()==k)
        {
            int len_more = n-r;
            cnt=cnt+len_more;
            //cout << "len more=" << len_more <<  "  cnt=" << cnt << endl;
            Mp[str[l]]--;
            if(Mp[str[l]]==0)
            {
                Mp.erase(str[l]);
                l++;
            }
            else
            {
                l++;
                continue;
            }
        }
        r++;

    }
    return cnt;
}

int findMin(unordered_map<char,int> Mp)
{
    int min_val=1e9;
    for(auto d:Mp)
    {
       int val = d.second;
       min_val = min(min_val,val);
    }
    return min_val;
}

/*

    str = b b a c b a

          * b a c      is valid  it means all substring before b are also valid  so no of substring =  1 + 1
          * * a c b    is valid  it means all substring before b are also valid  so no of substring =  1 + 2
          * * * c b a  is valid  it means all substring before b are also valid  so no of substring =  1 + 3
                        Here 1 is current and other part is First occurence of a or b or c

                        We maintain the occurence of a , b and c in LastSeen[]

        So cnt = 1 + min(LastSeen(a,b,c))

        b b a c b a                Lastseen[a] = -1  Lastseen[b] = -1  LastSeen[c] = -1
        0 1 2 3 4 5

        b b a c b a                Lastseen[a] = -1   Lastseen[b] = 0    LastSeen[c] = -1
        * b a c b a                Lastseen[a] = -1   Lastseen[b] = 1    LastSeen[c] = -1
        * * a c b a                Lastseen[a] =  2   Lastseen[b] = 1    LastSeen[c] = -1
        * * * c b a                Lastseen[a] =  2   Lastseen[b] = 1    LastSeen[c] =  3
                                    min = 1 , cnt = 1 + 1 = 2
        * * * * b a                Lastseen[a] =  2   Lastseen[b] = 4    LastSeen[c] = 3
                                    min = 2 , cnt = 1 + 2 = 3
        * * * * * a                Lastseen[a] =  5   Lastseen[b] = 4    LastSeen[c] = 3
                                    min = 3 , cnt = 1 + 3 = 4

*/

// TC --> O(N)
// SC -> O(3)
int findAllSubStringsContaining_k_chars_Sol3(string str,int k)
{
    int n = str.size();

    unordered_map<char,int> LastSeen(3);
    LastSeen['a']=-1;
    LastSeen['b']=-1;
    LastSeen['c']=-1;
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        LastSeen[str[i]]=i;
        if(LastSeen['a']!=-1 && LastSeen['b']!=-1 && LastSeen['c']!=-1)
        {
            cnt = cnt + (1 + findMin(LastSeen));
        }
    }
    return cnt;
}


int main()
{
    string str = "bbacba";
    int k=3;
    int ans1 = findAllSubStringsContaining_k_chars_Sol1(str,k);
    cout << "Using Sol1 find All SubStrings Containing k chars= " << ans1 << endl;

    int ans2 = findAllSubStringsContaining_k_chars_Sol2(str,k);
    cout << "Using Sol2 find All SubStrings Containing k chars= " << ans2 << endl;

    int ans3 = findAllSubStringsContaining_k_chars_Sol3(str,k);
    cout << "Using Sol3 find All SubStrings Containing k chars= " << ans3 << endl;

    return 0;
}
