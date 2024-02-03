#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int l,int h,int ele){

         if(l > h)
            return -1;

        int mid  = l + (h - l)/2;

        if(arr[mid] == ele)
            return mid;
        else if(ele > arr[mid])
            return binarySearch(arr,mid + 1,h,ele);
        else
            return binarySearch(arr,l,mid - 1,ele);

}
int main(){

    int arr[5] = {4 , 6 , 9 , 11, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    int val = binarySearch(arr,0,n - 1,20);

    if(val != -1)
        cout<<"6 present at : " << val ;
    else
        cout<<"element not found";

    return 0;
}