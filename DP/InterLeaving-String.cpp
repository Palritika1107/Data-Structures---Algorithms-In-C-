#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        int n = s3.length();
        
        if(n1+n2 != n)
            return false;
        
        vector<int>prev(n2 + 1,0);
        vector<int>curr(n2 + 1,0);
        
        prev[0] = true; //s1 = "" ,s2 = "" ,s3 = ""
        
        //first row -> s1="" , s2 = "......."
        for(int j=1;j<=n2;j++){
            if(s2[j - 1]==s3[j - 1] && prev[j - 1])
                prev[j] = true;
        }
        
        //first column -> s2 = "" , s1 = "........"
        // for(int i=1 ; i<=n1;i++){
            // if(s1[0]==s3[0])
            //     curr[0] = 1;
            
        // }
        
        
        for(int i=1;i<=n1;i++){
            
            if(s1[i - 1] == s3[i - 1] && prev[0])
                curr[0] = true;
            
            for(int j=1;j<=n2;j++){
                
                if(s1[i - 1] == s3[i + j - 1])
                    curr[j] = prev[j];
                if(s2[j - 1] == s3[i + j - 1])
                    curr[j] = curr[j] || curr[j - 1];
            }
            
            prev = curr;
        }
        
       
        return prev[n2];
    }

int main(){

    bool val = isInterleave("aabd","abdc", "aabdbadc");
    if(val)
        cout<<true;
    else
        cout<<false;

    return 0;
}