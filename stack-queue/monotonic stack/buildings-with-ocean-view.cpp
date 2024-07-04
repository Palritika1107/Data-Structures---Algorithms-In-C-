#include<bits/stdc++.h>
using namespace std;


// https://leetcodethehardway.com/solutions/1700-1799/buildings-with-an-ocean-view-medium

// There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

// The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

// Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
//[5,1,2,3,1,2]

//SOLUTION : 

//monotonic stack pattern -> previous greater (strict)


vector<int> getBuildingList(vector<int> &list){

int n = list.size();

    vector<int>res;

    stack<int>st;

    for(int i=0;i<n;i++){

        while(!st.empty() && list[i]>=list[st.top()])
            st.pop();

        
        st.push(i);
        

        
    }

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(),res.end());

    return res;

}

int main(){

    vector<int>list = {4 , 2 , 3 , 1};

    vector<int> res = getBuildingList(list);
    
    for(int a : res)
        cout<<a<<" ";


    return 0;
}