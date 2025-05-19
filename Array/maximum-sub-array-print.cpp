#include<iostream>
#include<vector>
using namespace std;

vector<int> getMaxSumArray(vector<int>&vec)
{
    int currSum = 0;
    int maxSum = 0;
    int start = 0,startIdx = 0,endIdx = 0;

    for(int i=0;i<vec.size();i++){

        if(vec[i]>vec[i]+currSum){
            start = i;
            currSum = vec[i];
        }else{
            currSum += vec[i];
        }

        if(currSum > maxSum){
            maxSum = currSum;
            startIdx = start;
            endIdx = i;
        }
    }

    cout<<maxSum<<"\n";

    return vector<int>(vec.begin() + startIdx , vec.begin()+endIdx + 1);
}

int main(){

        vector<int>vec({-1,2,-1,4,1,-4,2});

        vector<int>res = getMaxSumArray(vec);

        int verifysum = 0;
        for(int i=0;i<res.size();i++){
            verifysum += res[i];
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        cout<<verifysum;

    return 0;
}