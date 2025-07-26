#include<bits/stdc++.h>
using namespace std;

//https://takeuforward.org/plus/dsa/problems/next-smaller-element

int main(){
        // Your code goes here
        
        //vector<int>arr = {4,8,5,2,25};
        vector<int>arr = {10,9,8,7};

        int n = arr.size();
        unordered_map<int,int>mp;
        stack<int>st;

        for(int i=0;i<n;i++)
            mp[i] = -1;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                mp[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){

            arr[i] = mp[i];
        }
        
        for(int a : arr)
            cout<<a<<" ";
        

       return 0;

    
};
