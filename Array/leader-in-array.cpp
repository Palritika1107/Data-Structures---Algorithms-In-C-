#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array, print all the elements which are leaders. 
// A Leader is an element that is greater than all of the elements on its right side in the array.

vector<int>getLeaders(vector<int>&arr){

    int maxVal = INT_MIN;
    vector<int>leaders;

    int n = arr.size();

    for(int i=n - 1;i>=0;i--){
        if(arr[i] > maxVal){
            leaders.push_back(arr[i]);
            maxVal = arr[i];
        }
    }
    return leaders;
}
int main(){

    vector<int>arr = {3 , 0  ,1 , 2, 0 ,1};

    vector<int>leaders = getLeaders(arr);

    for(int leader : leaders){
        cout<<leader<<" ";
    }

    return 0;
}