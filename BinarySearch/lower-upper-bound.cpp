#include<bits/stdc++.h>
using namespace std;

int upperbound(int *arr,int l ,int h,int ele){
    
//strictly greater than ele
while (h-l > 1){
    int mid = l  + (h - l)/2;


    
     if(ele >= arr[mid])
        l = mid + 1;
    else
        h = mid;
}

if(arr[l] > ele)
    return l;
return h;
}
int lowerbound(int *arr,int l ,int h,int ele){

//less than or equals to  ele
while (h-l > 1){
    int mid = l  + (h - l)/2;


    // if(arr[mid] == ele)
    //     h = mid;
     if(ele > arr[mid])
        l = mid + 1;
    else
        h = mid;
}

if(arr[l] >= ele)
    return l;
return h;

}
int main(){

    int arr[7] = {1,2,6,6,6,9,20};
            //    0   1  2   3  4    5   6
    int n = sizeof(arr)/sizeof(arr[0]);

    // int val = binarySearch(arr,0,n - 1,20);
    // int upper_bound = upperbound(arr,0,n - 1,6); //fix upper bound
    // cout<<upper_bound<<"\n";

    // int lower_bound = lowerbound(arr,0,n - 1,6);
    // cout<<lower_bound<<"\n";

    // cout<<6<<" occurs "<<upper_bound - lower_bound <<" times"<<"\n";

    // if(val == n - 1 && arr[val]!=6)
    //         cout<<"element not found";
        
    // else
    //         cout<<"6 present at : " << val ;
        
    // cout<< val;

    auto lb = lower_bound(arr,arr + 7,6);
    
    auto ub = upper_bound(arr,arr + 7,6);

    cout<<6<<" occurs"<<ub-lb<<" times";

    return 0;
}