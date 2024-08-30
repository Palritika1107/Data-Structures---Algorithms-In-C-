#include<bits/stdc++.h>
using namespace std;


   vector<vector<int>>dir{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    long long mod = 1e9 + 7;
    int getCount(int i,int j,int n,int nosRows,int nosCols){
        cout<<i<<" "<<j<<"\n";
        if(n == 0){
            return 1;
        }


        int tmpCount = 0;
        for(int k=0;k<dir.size();k++){
            int nexti = i + dir[k][0];
            int nextj = j + dir[k][1];

            if(nexti>=0 && nexti<nosRows && nextj>=0 && nextj<nosCols){
                tmpCount += getCount(nexti,nextj,n - 1,nosRows,nosCols);
            }
        }

        return tmpCount;


    }
    
    int knightDialer(int n) {

        // vector<vector<char>>board{{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

        int count = 0;
        int nosRows =  4;                  //board.size();
        int nosCols =  3;                  //board[0].size();

        for(int row=0;row<nosRows;row++){
            for(int col=0;col<nosCols;col++){
                if(row==(nosRows - 1) && col!=1)
                    continue;
                
                // cout<<row<<" "<<col<<"\n";
                count = (count  + getCount(row,col,n - 1,nosRows,nosCols))%mod;
                cout<<count<<"\n";
            }
        }
        
     return count;   
    }

    int main(){


        cout<<knightDialer(1);
        return 0;
    }