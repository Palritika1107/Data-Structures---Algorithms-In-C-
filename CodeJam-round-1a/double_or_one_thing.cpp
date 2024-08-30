#include<bits/stdc++.h>
using namespace std;

//https://github.com/google/coding-competitions-archive/blob/main/codejam/2022/round_1a/double_or_one_thing/statement.pdf
//think about if the question only wanted the number of possibilities then w e could have optimised it suing DP

//in this variation all the possible strings are wanted hence we can;t optimise only use backtracking to get the possible strings


void formStrings(string &s1,string tmp,int idx,vector<string>res){
    if(idx >= s1.length()){
        res.push_back(tmp);

        return;
    }

    //highlight
    
    formStrings(s1,tmp + s1[idx] + s1[idx] ,idx + 1,res);

    //don't highlight

    formStrings(s1,tmp + s1[idx] ,idx + 1,res);



}
string getShortestString(string &s1){

    vector<string>res;

    string tmp = "";

    formStrings(s1,tmp,0,res);

    sort(res.begin(),res.end());

    return res[0];



}


int main(){

    string s1 = "PEEL";

    string s2 = "CODEJAMDAY";

    cout<<getShortestString(s2);

    return 0;

}