#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
    Give S = ddaaabbca  T = abc

    Find Min Length SubString which has all chars of T  . T has Mp.size=3 Try to find same in all substring
    eg: s = aaabbca                                   t= abc
        Len = 7 freqS {a-4,b-2,c-1} Mp.size=3          freqT { a- 1, b-1 , c-1}  So Possible

        s = aabbca                                    t= abc
        Len = 6 freqS {a-3,b-2,c-1} Mp.size=3          freqT { a- 1, b-1 , c-1}  So Possible

        s = abbca                                     t= abc
        Len = 5 freqS {a-2,b-2,c-1} Mp.size=3          freqT { a- 1, b-1 , c-1}  So Possible

        s = abbc                                      t= abc
        Len = 4 freqS {a-1,b-2,c-1} Mp.size=3          freqT { a- 1, b-1 , c-1}  So Possible

        s = bbca                                      t= abc
        Len = 4 freqS {a-1,b-2,c-1} Mp.size=3          freqT { a- 1, b-1 , c-1}  So Possible

        s = bca                                       t= abc
        Len = 3 freqS {a-1,b-1,c-1} Mp.size=3          freqT { a- 1, b-1 , c-1}  So Possible

        So out of all Sub string we have min len =3 where Mp.size()=3
        So return bca

        Hence Use condition as FreqS>=FreqT i.e.  FreqS.size()>=FreqT.size() & FreqS {a-2,b-2,c-1} >= FreqT{a-1,b-1,c-1}
                                len = j-i+1;
                                minLen = min(min_len,len)

*/


void print_Map(unordered_map<char,int> Mp)
{
    for(auto d:Mp)
    {
        cout << "key=" << d.first << " val=" << d.second << endl;
    }
    cout << endl;
}
// TC --> O(N*N)
// SC -> O(2N)
string findMinLenSubStringWithAllCharsofT_Sol1(string& s,string& t)
{
        cout << __FUNCTION__ << endl;
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> freqT;
        for(int i=0;i<m;i++)
        {
            freqT[t[i]]++;
        }

        //print_Map(freqT);

        int min_len=1e9;
        string ans;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> freqS;
            for(int j=i;j<n;j++)
            {
                freqS[s[j]]++;

                bool IsValid = false;
                if(freqS.size()>=freqT.size())
                {
                    //print_Map(freqS);
                    // Check all contents of freqT is present in freqS
                    for(auto d:freqT)
                    {
                        int key = d.first;
                        int val = d.second;

                        if(freqS.find(key)!=freqS.end())
                        {
                            IsValid = true;
                            if(val>freqS[key])
                            {
                                IsValid = false;
                                break;
                            }
                        }
                        else
                        {
                            IsValid = false;
                            break;
                        }

                    }
                }
                if(!IsValid)
                    continue;
                int len = j-i+1;
                if(len<min_len)
                {
                    min_len = len;
                    ans = s.substr(i,len);
                    cout << "ans=" << ans << " len=" << min_len << endl;
                }
            }
        }
        return ans;
}

// TC --> O(N*N)
// SC -> O(N)
string findMinLenSubStringWithAllCharsofT_Sol2(string& s,string& t)
{
    int n = s.size();
    unordered_map<char,int> Mp;

    int m = t.size();

    int min_len = 1e9;
    int startIdx=-1;
    for(int i=0;i<n;i++)
    {
        unordered_map<char,int> Mp;
        for(int i=0;i<m;i++)
        {
            Mp[t[i]]++;
        }
        int cnt = 0;
        for(int j=i;j<n;j++)
        {
            if(Mp.find(s[j])!=Mp.end())
            {
                Mp[s[j]]--;
                if(Mp[s[j]]==0)
                    cnt++;
            }
            else
            {
                Mp[s[j]]--;
            }

            if(cnt==m)
            {
                int len = j-i+1;

                if(min_len>len)
                {
                    min_len = len;
                    startIdx = i;
                    break;
                }

            }
        }
    }

    string sub = s.substr(startIdx,min_len);
    return sub;

}

// TC --> O(N) + O(N) + O(N) = O(3N)
// SC -> O(N)
string findMinLenSubStringWithAllCharsofT_Sol3(string& s,string& t)
{
    int n = s.size();
    int m = t.size();

    int l=0,r=0;

    unordered_map<char,int> Mp;

    for(int i=0;i<m;i++)
        Mp[t[i]]++;

    int cnt=0;
    int min_len=1e9;
    int start_idx=-1;
    bool flag=false;
    while(r<n)
    {
        if(Mp[s[r]]>0) // Pre Filled or Pre Inserted
        {
            cnt=cnt+1;
        }
        Mp[s[r]]--;

       while(cnt==m)
       {
           int len = r-l+1;
           if(min_len>len)
           {
               min_len = len;
               start_idx = l;
           }

           Mp[s[l]]++;
           if(Mp[s[l]]>0) // It was Pre Inserted from t kEEP gRREATER than zero and Not Equal to 1
           {
               cnt = cnt-1;
           }
           l++;
       }
       r++;
    }

    string sub = "";
    if(start_idx!=-1)
    {
        sub = s.substr(start_idx,min_len);
        return sub;
    }
    else
        return "";

}
int main()
{
    string s = "bbaa",t="aba";


    string ans1 = findMinLenSubStringWithAllCharsofT_Sol1(s,t);
    cout << "Using Sol 1 Min Len SubString With All CharsofT =" << ans1 << endl;

    string ans2 = findMinLenSubStringWithAllCharsofT_Sol2(s,t);
    cout << "Using Sol 2 Min Len SubString With All CharsofT =" << ans2 << endl;

    string ans3 = findMinLenSubStringWithAllCharsofT_Sol3(s,t);
    cout << "Using Sol 3 Min Len SubString With All CharsofT =" << ans3 << endl;

    return 0;
}
