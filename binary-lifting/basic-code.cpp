//Q) get the lowest Common ancestor of nodes a and b
//brute force : 
//1)calculate height (height(b) > height{a})
//2)move be up till the same height as a
//3)if a== b return a
//3)if a!=b that means they are in different subtree , move a and b one step up(a = parent(a) b=parent(b))
//until they reach there common ancestor
//do precomputation for binary listing to optimise the above steps (logic will be same)

//binary lifting 
//sc : o(logn) for each query hence for n queries nlogn
//tc : o(nlogn)

//2^i = 2*(2^(i-1)), ex : 2^2 = 2*(2^1) , going 2^1 ,2 times in total 4 steps

//precomputation
//n : total number of nodes

#include<iostream.h>
using namespace std;

int maxJumps = floor(log2(n));
vector<vector<int>>parent(n + 1,vector<int>(maxJumps + 1,-1));

//function for forming adj list for a tree needed here


//dfs to initialise immediate parent
void dfs(vector<vector<int>>&parent,int node,int par){
    parent[node][0] = par;

    for(auto child : adj[node]){
        if(child != par){
            dfs(parent,child,node);
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

//function for calulation height/level of each node needed

//get LCA

int getLCA(){

    if(height[a]>height[b])
        swap(a,b);
    
    int d = height[b] - height[a];

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
        else if(parent[b][i] == parent[a][i])
            break;
        //else if parent[b][i] == -1 then move to next i
    }

    
    return parent[b][i]; 

}