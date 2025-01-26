#include<bits/stdc++.h>
using namespace std;


int placeElement(vector<int>&arr,int index,int lo,int hi){
  int i = lo+ 1;
  int j = hi;

  int val = arr[index];

  swap(arr[index],arr[lo]);
  

  while(i<=j){ //if we do i<j and don't consider i==j condition it will fail in condition where=>  i+1=j  and both arr[i] and arr[j]are more than val it will stop at i==j but arr[i]=arr[j]>val so in that step also we need to swap and decrement j so that it points to last element in left boundary(group of elements smaller than val)

    if(arr[i] <= val)
        i++;
    else{
      swap(arr[i],arr[j]);
      j--;
    }

    
  }
  swap(arr[j],arr[lo]);
  return j;
  
}


void quickSort(vector<int>&arr,int lo,int hi){

  if(lo < hi){

    int mid = lo + (hi - lo)/2;

    int correctIdx = placeElement(arr,mid,lo,hi);
    quickSort(arr,lo,correctIdx - 1);
    quickSort(arr,correctIdx + 1,hi);
    
  }
  
}



int main(){

  vector<int>arr = {1,7,3,2,10,1,3};
  quickSort(arr,0,6);

  for(int a : arr)
      cout<<a<<" ";


  return 0;
}