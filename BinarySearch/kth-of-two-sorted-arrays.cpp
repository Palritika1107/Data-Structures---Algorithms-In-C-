#include<bits/stdc++.h>
using namespace std;

int getKthElement(vector<int>&arr1,vector<int>&arr2,int k){

    int n = arr1.size();
    int m = arr2.size();

    if(n > m)
        return getKthElement(arr2,arr1,k);

    int lo = max(0,k-m);
    int hi = min(n,k);

    int l1 = INT_MIN,l2 = INT_MIN,r1=INT_MAX,r2=INT_MAX;
    while(lo <= hi){

        int mid1 = (lo + hi)/2;
        int mid2 = k - mid1;

       int l1 = mid1 == 0 ? INT_MIN : arr1[mid1 - 1]; 
        int l2 = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];
        int r1 = mid1 == n ? INT_MAX : arr1[mid1]; 
        int r2 = mid2 == m ? INT_MAX : arr2[mid2]; 

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1 > r2)
            hi = mid1 - 1;
        else  //l2 >  r1
            lo = mid1 + 1;

    }

    return 0;

}
int main(){
    vector<int>arr1{2,3,6};
    vector<int>arr2{1,4,9,12,13,20};

    int k = 4;

    cout<<"k-th  element is"<<getKthElement(arr1,arr2,k);

    return 0;
}