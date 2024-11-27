#include<bits/stdc++.h>
using namespace std;

//how do we count the number of tilings
//when we have blocks of different lengths
//and blocks of the same size but different color
//red of size 1
//purple of size 1
//blue of size 2
//green of size 4
//f(1) = 2
//f(2) = 5
//f(7) = 452

//-------------recursive-------------------

int getTiling(int n,map<int,int>&mp){
    if(n == 0)
        return 1;
    
    if(n < 0)
        return 0;

    int ways = 0;
    
    for(auto p : mp){
        int len = p.first;
        int count = p.second;

        if(len > n)
            continue; //to prevent unneccessary recursive function call

        ways += (getTiling(n - len,mp) * count);
    }

    return ways;

}

int main(){

map<int,int>mp ; //map for keeping a count of blocks of the same size but different color

mp[1] = 2;
mp[2] = 1;
mp[4] = 1;

int n = 2;

cout<<getTiling(n,mp);
 

return 0;
}

//--------memoization-------------
// #include<bits/stdc++.h>
// using namespace std;

// int getTiling(int n,map<int,int>&mp,vector<int>&dp){
//     if(n == 0)
//         return 1;
    
//     if(n < 0)
//         return 0;
    
//     if(dp[n] != -1)
//         return dp[n];

//     int ways = 0;
    
//     for(auto p : mp){
//         int len = p.first;
//         int count = p.second;
        
//         if(len > n)
//             continue;

//         ways += (getTiling(n - len,mp,dp) * count);
//     }

//     return dp[n] = ways;

// }

// int main(){

// map<int,int>mp ; //map for keeping a count of blocks of the same size but different color

// mp[1] = 2;
// mp[2] = 1;
// mp[4] = 1;

// int n = 2;
// vector<int>dp(n + 1,-1);

// cout<<getTiling(n,mp,dp);
 

// return 0;
// }

//-------------------iterative---------------

int getTiling(int n,map<int,int>&mp,vector<int>&dp){
    //size of dp ---> n + 1
    //dp initilised with 0
    dp[0] = 1;

for(int i=1;i<=n;i++){
    
    for(auto p : mp){
        int len = p.first;
        int count = p.second;
        
        if(len > i)
            continue;

        dp[i] += (dp[i - len] * count);
    }
}

    return dp[n];

}
