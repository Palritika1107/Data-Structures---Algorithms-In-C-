#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/339/D

//n=even =2 hence 2^2 =4

//1(XOR)
// 1   2(OR)
// 1 2 3 4

//n=odd=3 hence 2^3 = 8

//         1{or}
//     1         2{xor}
//  1     2    3   4(or)
//1  2  3  4  5 6 7 8


//mistake made : in question it's given array is 1 based index , so in query 1,2 means arr[0] = 4 , 1str element ot be updated to 4



class SGtree{
    

    public:
    vector<int>segment;

    SGtree(int n){
        segment.resize(4*n,0);
    }

   void build(vector<int>&arr,int index,int lo,int hi,bool isOr){

    if(lo == hi)
    {
        segment[index] = arr[lo];
        return;
    }


    int mid = (lo + hi)/2;

    build(arr,2*index + 1,lo,mid,!isOr);
    build(arr,2*index + 2,mid + 1,hi,!isOr);

    if(isOr)
        segment[index] = segment[2*index + 1] | segment[2*index + 2];
    else
        segment[index] = segment[2*index + 1] ^ segment[2*index + 2];

   }

   int query(){


        // //no overlap
        // if(hi<l || lo>r){
        //     return INT_MAX; //some other value in this question
        // }

        // else if(lo>=l && hi<=r){ //complete overlap in this q only this should be returned as on channging value after that we want value of entire range

            return segment[0];

        // }

        // int mid = (lo + hi)/2;

        // int left = query(arr,2*index + 1,lo,mid,l,r);
        // int right = query(arr,2*index + 2,mid + 1,hi,l,r);
        // return (left | right); //incorrect 


   }

   void update(int index,int lo,int hi,int idx,int val,bool isOr){
    if(lo == hi){
            segment[index] = val;
            return;
    }

    int mid = (lo + hi)/2;

    if(idx <= mid)
        update(2*index+1,lo,mid,idx,val,!isOr);
    else
        update(2*index+2,mid + 1,hi,idx,val,!isOr);

    if(isOr)
        segment[index] = segment[2*index + 1] | segment[2*index + 2];
    else
        segment[index] = segment[2*index + 1] ^ segment[2*index + 2];


   }


};

int main(){

    int n = 2; //2^n number of elements
    int m = 4; //nos of queries
    int el = pow(2,n);

// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2

vector<int>arr = {1,6,3,5};

SGtree sgtree(el);

if(n%2==0)
    sgtree.build(arr,0,0,el - 1,false);
else 
    sgtree.build(arr,0,0,el - 1,true);
    
cout<<sgtree.segment[0];

if(n%2==0)
    sgtree.update(0,0,el - 1,0,4,false);
else
    sgtree.update(0,0,el - 1,0,4,true);
    
cout<<sgtree.segment[0];
    
if(n%2==0)
    sgtree.update(0,0,el - 1,2,4,false);
else
    sgtree.update(0,0,el - 1,2,4,true);
    
cout<<sgtree.segment[0];

if(n%2==0)
    sgtree.update(0,0,el - 1,0,2,false);
else
    sgtree.update(0,0,el - 1,0,2,true);



cout<<sgtree.segment[0];

    return 0; 
}