#include<bits/stdc++.h>
using namespace std;
//had solved using merge sort 
//O(nlogn)
//using segment tree 
//TC: o(nlogn)
class SGtree{
    vector<int>segment;

    public:

    SGtree(int n){
        segment.resize(4*n);
    }

    void build(int arr[],int lo,int hi,int segIdx){

        if(lo == hi){

            segment[segIdx] = arr[lo];
            return;

        }


        int mid = (lo + hi)/2;
        build(arr,lo,mid,segIdx*2 + 1);
        build(arr,mid + 1,hi,segIdx*2 + 2);

        segment[segIdx] = segment[segIdx*2 + 1] + segment[segIdx*2 + 2];



    }

    void update(int lo,int hi,int segIdx,int i,int val){
        if(lo == hi){
            segment[segIdx] +=val;
        }



        int mid = (lo + hi)/2;
        if(i <= mid)
            update(lo,mid,segIdx*2 + 1,i,val);
        else
            update(mid + 1,hi,segIdx*2 + 2,i,val);


        segment[segIdx] = segment[segIdx*2 + 1]  + segment[segIdx*2 + 2];



    }

    int query(int lo,int hi,int l ,int r,int segIdx){

        //no overlap
        if(hi<l|| lo>r){

            return 0;


        }

        else if(lo>=l && hi<=r) {//complete overlap

            return segment[segIdx];

        }


        //partial overlap

        int mid = (lo + hi)/2;
        int left = query(lo,mid,l,r,segIdx*2 + 1);
        int right = query(mid + 1,hi,l,r,segIdx*2 + 2);

        return (left + right);


    }





};


int main(){

        int arr[7] = {5 , 1, 7,2, 2 ,3,10};
        //ans : 7
        int n = 7;

        int maxEle = -1;

        for(int a : arr){

            maxEle = max(maxEle , a);

        }

            maxEle++;

        int freq[maxEle] = {};

        for(int a : arr){
            freq[a]++;
        }

        SGtree sgtree(maxEle);
        sgtree.build(freq , 0, maxEle - 1,0);

        int count = 0;

        for(int i=0;i<n;i++){

            freq[arr[i]]--;
            sgtree.update(0,maxEle - 1,0,arr[i],-1);

            count +=sgtree.query(0,maxEle - 1,1,arr[i] - 1,0);

        }

        cout<<count;




    return 0;
}
