// https://www.lintcode.com/problem/848/
//  Minimise Maximum Distance between Gas Stations

//brute force : 
//TC : O(n*k),SC:O(1)

//better
//TC: O(nlogn + klogn),SC: O(n- 1)
#include<bits/stdc++.h>
using namespace std;

int getDistBrute( vector<int>&arr,int k){
        int maxVal = 0 ;
        int maxIdx = -1;

        vector<int>nosDivisions(arr.size() - 1,0);

for(int j=0;j<k;j++){

        for(int i=0;i<arr.size()-1;i++){

            int val = (arr[i + 1] - arr[i])/(nosDivisions[i]+1);
            if(maxVal < val){
                maxVal = val;
                maxIdx = i;
            }

        }

    nosDivisions[maxIdx]++;
    maxVal = 0;

}

maxVal = 0;

for(int i=0;i<arr.size()-1;i++){

    maxVal = max(maxVal , (arr[i + 1]-arr[i])/(nosDivisions[i]+1));
}

return maxVal;

}

int getDistBetter(vector<int>&arr,int k){

    int n = arr.size();

    priority_queue<pair<int,int>>pq;
    vector<int>div(n,0);

    for(int i=0;i<n - 1;i++){
        pq.push({(arr[i + 1]-arr[i]) , i});
    }

    while(k > 0){
        auto p = pq.top();
        int dis = p.first;
        int idx = p.second;
        pq.pop();

        div[idx]++;

        int newVal = (arr[idx + 1]-arr[idx]) / (div[idx] + 1) ; // cannot use dis/div[idx] + 1 ,because dis the current distance in the gap ,but i neeed the original dis i.e. arr[idx + 1] - arr[idx]

        pq.push({newVal,idx});

        k--;
    }

    return pq.top().first;
}

int main(){

    vector<int>arr{1,13,17,23};
    int k = 5;

    // cout<<"reduced distance : "<<getDistBrute(arr,5);
    cout<<"reduced distance : "<<getDistBetter(arr,5);
    
    return 0;
}