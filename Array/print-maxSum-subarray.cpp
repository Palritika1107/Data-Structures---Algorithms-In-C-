#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//max sum subarray folow up question -> print maximum sum subarray ,there can be many subarrays with maxsSum
//print anyone.

vector<int> printMaxSumArr(vector<int>&arr){

    int n = arr.size();
    vector<int>arrIdx(n,-1) ;
    vector<int>res;
    int sum = arr[0];
    int maxSum = arr[0];
    // int maxSumIdx = 0;
    int start = 0;
    int maxStart = 0;
    int maxEnd = 0;
    // arrIdx[0] = 0;

    for(int i=1;i<n;i++){

        if(arr[i] > arr[i]+sum){
            sum = arr[i];
            start = i;
            // arrIdx[i] = i;
        }else{
            sum += arr[i];
            // arrIdx[i] = i - 1;
        }

        if(sum > maxSum){
            maxSum = sum;
            // maxSumIdx = i;
            maxStart = start;
            maxEnd = i;
        }
    }

    for(int i=maxStart ; i<=maxEnd ; i++){
        res.push_back(arr[i]);

        i++;
    }

    // res.push_back(arr[maxSumIdx]);

    return res;
}

int main(){

    vector<int>arr = {2,-4,6,-1,0,1,3};

    vector<int>res = printMaxSumArr(arr);

    reverse(res.begin(),res.end());

    for(int a : res){
        cout<<a<<" ";
    }

    return 0;
}


