#include<bits/stdc++.h>
using namespace std;

// Q : https://open.kattis.com/problems/magicalcows
//C : maximum C cows can be there in a farm
//N : number of farms  having atleast 1 cow 
//M : number days farm owner comes to inspect

//input : 
//1) C 
//N lines / vector having N elements , displaying number of cows in N farms
//M lines / vector having M elements , displaying days on which farm owner comes to inspect

//1<= C <=1000
//0<= N <=1000
//1<= M <=50

//Q> number of farms owner has to visit on ith day (i = values in vector of length M / M lines)

//naive solution use the initialCows array to check if initialCows[i]*2 <= C if so initialCows[i] = initialCows[i]*2 else , we need to have another farm having same number if cows so , intialCows.push_back(initialCows[i]), length of intialCows will give number farms to visit the  next day

int getCountforDay(vector<vector<int>>&dp,int day){
    
    int count = 0;

    for(int j=0;j<=dp[0].size();j++){
        count += dp[day][j];
    }

    return count;

}

void getFarmCount(vector<vector<int>>&dp,int maxDays,int C){

    for(int day = 0;day<maxDays;day++){

        for(int cow = 1 ; cow<=C ; cow++){

            if(cow*2 <= C){
                dp[day + 1][2 * cow] += dp[day][cow];
            }
            else{
                dp[day + 1][cow] += (2 * dp[day][cow]);
            }
        }
    }
}

int main(){

    int C,N,M;
    // int C = 1;
    vector<int>initialCows(N,0);
    vector<int>visitDays = {0,1,2,3,4};

    C = 1;
    N = 5;
    M = 5;
    for(int i=0;i<N;i++)
        initialCows[i] = 1;
    
    int maxDays = INT_MIN;

    for(int i=0;i<M;i++)
        maxDays = max(maxDays,visitDays[i]);

    vector<vector<int>>dp(maxDays + 1,vector<int>(C + 1)); // rows -> days , cols -> nos of cows


    //initiliase cows on zero-eth day

    for(int i=0;i<N;i++){
        dp[0][initialCows[i]]++;
    }

    getFarmCount(dp,maxDays,C);

    for(int day=0;day<M;day++){
        cout<< getCountforDay(dp,visitDays[day]) << " ";
    }


    return 0;
}