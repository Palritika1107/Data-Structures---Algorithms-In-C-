// Initial Question: You are given an n×m grid and start from the bottom-left corner with the goal of reaching the bottom-right corner. The allowed moves are only to the right, diagonally up-right, and diagonally down-right. The task is to determine the total number of unique paths that can lead you from the starting point to the destination while adhering to these movement rules.


// Follow-Up 1: A list of specific checkpoints within the grid is now introduced. In this variation, you are required to count only those paths that pass through each of these checkpoints once before reaching the bottom-right corner.


// Follow-Up 2: The order of visiting these checkpoints is now specified. For example, if the checkpoints are labeled 1, 2, and 3, any valid path must encounter checkpoint 1 first, then checkpoint 2, and finally checkpoint 3, in that exact sequence, on its way to the destination.
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>dir{{0,-1},{1, -1},{ -1,-1}};

int countWays(int n,int m,vector<vector<int>>&checkpoints){
    vector<vector<int>>checkList(m);

    checkList[0].push_back(n - 1);
    checkList[m - 1].push_back(n - 1);

    //first follow up

    for(auto point : checkpoints){

        if(checkList[point[1]].size() > 0)
            return 0;
        
        checkList[point[1]].push_back(point[0]);



    }

    // for(int i=0;i<m;i++){
    //     cout<<"col :"<<i;
    //     for(int row : checkList[i]){
    //         cout<<row<<" ";
    //     }

    //     cout<<"\n";
    // }

//second follow up

int prev = -1;

for(auto point : checkpoints){

    if(point[1]<= prev)
        return 0;
    

    prev = point[1];


}


// cout<<"prev :"<<prev<<"\n";





    // int starti = n - 1;
    // int startj = 0;

    // int desti = n - 1;
    // int destj = m - 1;

    vector<vector<int>>grid(n,vector<int>(m));

    grid[n - 1][0]  = 1;

    for(int j = 1;j<m;j++){
        
        // cout<<checkList[j][0]<<"\n";

        if(checkList[j].size() > 0){

                int i = checkList[j][0];

                for(int k = 0;k<dir.size();k++){

                int newi = i + dir[k][0];
                int newj = j + dir[k][1];

                if(newi>=0 && newi<n && newj>=0 && newj<m){

                    grid[i][j] += grid[newi][newj];
                }
                
                // cout<<grid[i][j]<<" ";
            }



        }
        else{
        for(int i=0;i<n;i++){


            for(int k = 0;k<dir.size();k++){

                int newi = i + dir[k][0];
                int newj = j + dir[k][1];

                if(newi>=0 && newi<n && newj>=0 && newj<m){

                    grid[i][j] += grid[newi][newj];
                }
            }

        }
        }
        
        cout<<"\n";

    }

    return grid[n - 1][m - 1];

}


int main(){

    // vector<vector<int>>checkpoints = {{2,1},{2,2}};
    vector<vector<int>>checkpoints = {{3,1},{2,2}};
    //col1 -> 3, col2->2,col3 -> 3

   cout<<"nos of ways : " <<countWays(4,4,checkpoints)<<"\n";

 //0  //0 0 0 0
 //1  //0 0 0 0
 //2  //0 0 1 0
 //3 // 1 1 0 1


    return 0;
}