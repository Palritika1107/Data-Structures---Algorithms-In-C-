//https://www.spoj.com/problems/AGGRCOW/

//[0 3 4 7 9 10] : stall positions
//nos of cows : 4
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int dis,vector<int>&pos,int c){

    int count  = 1; //first cow at first place
    int prevPos = 0;
    for(int i=1;i<pos.size();i++){
        if(pos[i]-pos[prevPos] >= dis){
            count++;
            prevPos = i;
        }
    }
    return count>=c;

}
int aggressiveCows(vector<int>&pos,int c){
    sort(pos.begin(),pos.end());
    int n = pos.size();
    int l = 1;
    int h = pos[n - 1] - pos[0];

    while(h-l > 1){

        int mid = (l + h)/2;

        if(isPossible(mid,pos,c))
            l = mid;
        else
            h = mid - 1;


    }
    if(isPossible(h,pos,c))
        return h;
    return l;
}
int main(){

    vector<int>pos{3,7,4,9,0,10};

    //0 3 4 7 9 10

    int c = 4;

    cout<<"max dist b/w cows: "<<aggressiveCows(pos,c);

    return 0;
}