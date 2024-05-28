//LeetCode 340 Longest Substring with At Most K Distinct Characters
//Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.
//I/P : "a b a c c a b" , k = 2, ans = 4
#include<bits/stdc++.h>
using namespace std;

int getLongestString(string &s,int k){

    map<char,int>mp;

    int i = 0;
    int maxLen = 0;

    for(int j=0;j<s.length();j++){
        // if(mp.find(s[j]) == mp.end())
        //     mp[s[j]] = 1;
        // else
            mp[s[j]]++;

        if(mp.size() > k){
            while(mp.size() > k){
                mp[s[i]] --;
                
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);

                i++;
            }
        }
        
        maxLen = max(maxLen , j - i + 1);
        // cout<<maxLen<<"\n";
    }

    return maxLen;
}

int main(){

    string s = "abaccab";
    int k = 2;
    
    cout<<"length is " << getLongestString(s,k);

    return 0;
}