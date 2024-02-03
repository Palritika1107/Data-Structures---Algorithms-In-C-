#include<bits/stdc++.h>
using namespace std;

double eps = 1e-3;
//find square root of an integer using binary search
int floorSqueareRoot(int n){

int l = 1,h = n;

while(h-l > 1){

    int mid = l + (h - l)/2;

    if(mid*mid < n)
        l = mid;
    else
        h = mid;
}

// cout<<l<<"\n"<<h<<"\n";
if(h*h <= n)
    return h;

return l;

}

double realSqrRoot(double n){

    //precision till two digits;
    double l = 1.0,h = n;

while(h-l > eps){

    double mid = l + (h - l)/2;

    if(mid*mid < n)
        l = mid;
    else
        h = mid;
}

cout<<l<<"\n"<<h<<"\n";
// if(h*h <= n)
//     return h;

return l;
    

}


int main(){

    int num ;
    int d ; //number of places of precision
    cout<<"enter a number \n";
    cin>>num;
    cout<<"\n";
    // cout<<"enter number of digits of precision \n";
    // cin>>d;
    // cout<<"\n";
    // cout<<floorSqueareRoot(num)<<"\n";
    cout<<realSqrRoot(num)<<"\n";
    
    // cout<<val<<"\n";

    return 0;
}