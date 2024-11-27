#include <bits/stdc++.h>
using namespace std;

//https://www.interviewbit.com/problems/maximum-sum-combinations/

bool comp(int a , int b){
    return a>b;
}

vector<int> getMaxCombo(vector<int>&a,vector<int>&b,int c){

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){

                int sum = a[i] + b[j];

                pq.push(sum);

                if(pq.size() > c)
                    pq.pop();

            }
        }

        vector<int>res;

        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }

        sort(res.begin(),res.end(),comp);

}

int main(){

//  A = [3, 2]
//  B = [1, 4]
//  C = 2

//[7, 6]

vector<int>a{3,2};
vector<int>b{1,4};

int c = 2;

vector<int>res =  getMaxCombo(a,b,c);

    return 0;
}
