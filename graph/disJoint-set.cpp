#include<bits/stdc++.h>
using namespace std;

class Disjoint{
vector<int>rank,parent,nodeSize;

public : 
Disjoint(int n){
    rank.resize(n + 1);
    parent.resize(n + 1);
    nodeSize.resize(n + 1);

    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
}
    int getParent(int node){
        if(parent[node] == node)
            return node;

        return parent[node] =  getParent(parent[node]);

    }

    void getUnionByRank(int u,int v){
        int ulp_u = getParent(u);
        int ulp_v = getParent(v);

        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u] > rank[ulp_v]){

            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }

    }

    void getUnionBySize(int u,int v){
        int ulp_u = getParent(u);
        int ulp_v = getParent(v);
        
        if(ulp_u == ulp_v)
            return;

        if(nodeSize[ulp_u] > nodeSize[ulp_v]){

            parent[ulp_v] = ulp_u;
            nodeSize[ulp_u] += nodeSize[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            nodeSize[ulp_v] += nodeSize[ulp_u];
        }


    
}


};


int main(){
    Disjoint ds(7);
    
    ds.getUnionByRank(1, 2);
    ds.getUnionByRank(2, 3);
    ds.getUnionByRank(4, 5);
    ds.getUnionByRank(6, 7);
    ds.getUnionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.getParent(3) == ds.getParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.getUnionByRank(3, 7);

    if (ds.getParent(3) == ds.getParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}