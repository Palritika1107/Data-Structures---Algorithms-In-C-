//Q) get the lowest Common ancestor of nodes a and b
//brute force : 
//1)calculate height (height(b) > height{a})
//2)move be up till the same height as a
//3)if a== b return a
//3)if a!=b that means they are in different subtree , move a and b one step up(a = parent(a) b=parent(b))
//until they reach there ancestor
//do precomputation for binary listing to optimise the above steps (logic will be same)

//binary lifting 
//sc : o(nlogn)
//tc : o(nlogn)

//precomputation
//n : total number of nodes

#include<iostream.h>
using namespace std;

int maxJumps = floor(log2(n));
vector<vector<int>>parent(n + 1,vector<int>(maxJumps + 1,-1));

void dfs(vector<vector<int>>&parent,int i,int par){
    parent[i] = par;

    for(auto child : adj[i]){
        if(child != par){
            dfs(parent,child,i);
        }
    }
}

void precomputeParents(){

//intialise immediate parents
dfs(parents,0,-1);

for(int j=1;j<=maxJumps;j++){
    for(int i=0;i<=n;i++){
        int par = parent[i][j - 1];
        parent[i][j] = parent[par][j - 1];
    }
}

}

//get LCA

int getLCA(){

    if(height[a]>height[b])
        swap(a,b);
    
    int d= height[b] - height[a];

    while(d){
        int i = floor(log2(d));
        b = parent[b][i];
        d -=(1<<i);
    }

    if(a==b)
        return a;
    
    int i;
    for(i=maxJumps;i>=0;i--){
        if(parent[b][i]!=-1 && (parent[b][i] != parent[a][i]))
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[b][i];

}