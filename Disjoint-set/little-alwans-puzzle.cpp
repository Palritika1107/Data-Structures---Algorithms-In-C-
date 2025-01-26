#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1534/C

class Disjoint{
public:
    int n;
    vector<int>parent;
    vector<int>psize;

    Disjoint(int nosOfNodes){
        n = nosOfNodes;
        parent.resize(n);
        psize.resize(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
            psize[i] = 1;
        }

        

    }

    int getParent(int node){
        if(parent[node] == node)
            return node;

        return parent[node] = getParent(parent[node]);

    }

    void performUnion(int u,int v){

        int upu = getParent(u);
        int upv = getParent(v);

        if(upu == upv)
            return;

        if(psize[upu] > psize[upv]){
            parent[upv] = upu;
            psize[upu] += psize[upv];
        }
        else{
            parent[upu] = upv;
            psize[upv] += psize[upu];
        }

    }


    
};

int getPuzzleSol(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();

    Disjoint dj(n + 1);

    //form graph =  do union

    for(int i=1;i<=n;i++){
        if(dj.getParent(arr1[i]) != dj.getParent(arr2[i])){

            dj.performUnion(arr1[i],arr2[i]);

        }
    }


    //count nos of components
    int count = 0;

    for(int i=1;i<=n;i++){
        if(dj.getParent(i) == i)
            count++;
    }


    return pow(2,count);

}

int main(){

//     2
// 4
// 1 4 2 3
// 3 2 1 4
// 8
// 2 6 5 1 4 3 7 8
// 3 8 7 5 1 2 4 6

vector<int>arr1{1 ,4 ,2 ,3};
vector<int>arr2{3 , 2 ,1 ,4};

// vector<int>arr1{2 ,6 ,5 ,1 ,4 ,3 ,7 ,8};
// vector<int>arr2{3, 8 ,7 ,5 ,1 ,2 ,4 ,6,};

//each component has to be ways to be placed 
//and permutaions of x components forms a solved solution hence
//2ways of arranging first component , 2 ways of arrangaing second component ,.....etc
//2*2*2* ....x times , where x is number of components


cout<<"number of possible solutions"<<getPuzzleSol(arr1,arr2);

    return 0;
}