#include<bits/stdc++.h>
using namespace std;

int placeElement(vector<int>&arr,int lo,int hi){

//     int pivot = arr[lo]; //taking first element of range as pivot
//     int i = lo,j = hi;
//     int k = lo + 1;
//     while(i<j){
//         if(arr[k] < pivot)
//             arr[i++] = arr[k++];
//         else
//             arr[j--] = arr[k++]; // iit will override in j posiiton , logic is incorrect

//     }

// arr[i] = pivot;

// return i;
int pivot = arr[lo]; // Taking the first element as pivot
    int i = lo + 1;      // Start just after the pivot
    int j = hi;

    while (i <= j) { // Ensure i doesn't cross j
        // Find elements on the wrong side
        while (i <= hi && arr[i] <= pivot) i++;
        while (j >= lo && arr[j] > pivot) j--;

        // Swap elements if i and j haven't crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in its correct position
    swap(arr[lo], arr[j]);

    return j; // Return the final pivot position

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