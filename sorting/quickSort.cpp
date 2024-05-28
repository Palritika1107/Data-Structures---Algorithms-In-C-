#include<bits/stdc++.h>
using namespace std;

int placeElement(vector<int>&arr,int lo,int hi){

    int pivot = arr[lo]; //taking first element of range as pivot
    int i = lo,j = hi;
    int k = lo + 1;
    while(i<j){
        if(arr[k] < pivot)
            arr[i++] = arr[k++];
        else
            arr[j--] = arr[k++];

    }

arr[i] = pivot;

return i;

}
void quickSort(vector<int>&arr,int lo,int hi){

    if(lo < hi){

       int idx = placeElement(arr,lo,hi);
        quickSort(arr,lo,idx - 1);
        quickSort(arr,idx + 1,hi);
    }


}
int main(){

    vector<int>arr{4,6,2,5,7,9,1,3};
    int lo = 0;
    int hi = arr.size() - 1;
    quickSort(arr,lo,hi);

    for(int a : arr)
        cout<<a<<" ";

    return 0;
}