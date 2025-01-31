#include<bits/stdc++.h>
using namespace std;

class SGtree{

    vector<int>segment;

    public:

    SGtree(int n){

        segment.resize(4*n);
    }

    void buildTree(int index,int i , int j,vector<int>&arr){
    if(i == j){

        segment[index] = arr[i];
        return;

    }

    int mid = i + (j - i)/2;

    //build left half
    buildTree(2*index + 1,i,mid,arr);
    //build right half
    buildTree(2*index + 2,mid + 1,j,arr);

    segment[index] = min(segment[2*index + 1],segment[2*index + 2]);
    
    

    


}

int getMinInRange(int index,int lo,int hi,int l,int r){
    
    
    if(hi<l || lo>r){ //no overlapping
        
        return INT_MAX;
        
        
        
    }
    else if(lo>=l && hi<=r){ //complete overlap
        
        
        return segment[index];
    }
    
    
    //else partial overlap
    
    int mid = (lo + hi)/2;
    
    int leftMin = getMinInRange(2*index + 1,lo,mid,l,r);
    int rightMin = getMinInRange(2*index + 2,mid + 1,hi,l,r);
    return min(leftMin,rightMin);
    
    
    
    
}

void update(int index,int lo,int hi,int idx,int val){
    if(lo == hi){
        
        segment[index] = val;
        
        return;
        
    }
    
    
    int mid = (lo + hi)/2;
    
    if(idx <= mid)
        update(2*index + 1,lo,mid,idx,val);
    
    else
        update(2*index + 2,mid + 1,hi,idx,val);
    
    
    segment[index] = min(segment[2*index + 1],segment[2*index + 2]);
    
    
}





};






int main(){
    //1)create the tree
    //2)query min in a range (query type 1)
    //3)update (query type  2)

    vector<int>arr = {1,2,29,0,3,10,71,4,9,2,1};
    //               0  1 2 3  4 5  6  7 8 9 10

    int n = arr.size();

    SGtree sgtreeObj(n);

    // vector<int>segment(4*n,-1);

    //step 1
    sgtreeObj.buildTree(0,0,n - 1,arr);

    //step 2
    // cout<<segment[0]<<" "<<segment[1]<<" "<<segment[2];
    cout<<sgtreeObj.getMinInRange(0,0,n - 1,4,6)<<"\n";
    
    //step 3
    sgtreeObj.update(0,0,n - 1,5,2); //5-idx 2-value to update
    cout<<sgtreeObj.getMinInRange(0,0,n - 1,4,6)<<"\n";
    
    

    return 0;
}