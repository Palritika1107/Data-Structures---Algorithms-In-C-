// https://projecteuler.net/problem=114
//https://www.youtube.com/watch?v=gQszF5qdZ-0&list=PLDV1Zeh2NRsAsbafOroUBnNV8fhZa7P4u&index=2

//nos of ways to fill a n length rod with red blocks of length 1 and blue blocks of length 2

//similar to fibonacci


#include<bits/stdc++.h>
using namespace std;


int fn(int i,vector<int>&dp){
if(i == 0)
    return 1;

if(i < 0)
    return 0;

if(dp[i] != -1)
    return dp[i];

int red ,blue;

red = fn(i - 1,dp);

blue = fn(i - 2,dp);

return dp[i] = red + blue;

}

int main(){

int n = 5;

// vector<int>dp(n + 1,-1);
int a = 1; //n = 0
int b = 1;// n = 1;
int c = 0;
for(int i=2;i<=n;i++){
    c = a + b;
    a = b;
    b = c;
}

cout << b;

    return 0;
}