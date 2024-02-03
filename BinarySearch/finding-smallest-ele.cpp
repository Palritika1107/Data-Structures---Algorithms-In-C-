#include<bits/stdc++.h>
using namespace std;

//smallest element in rotated sorted array
int main(){

    vector<int>vec{4,5,6,1,2,3};

    int l = 0 , h = vec.size() - 1;

    //check if h = INT_MAX and l = 1 and if we do mid = (l + h)/2;

    while(l < h ){
        int mid = l + (h - l)/2;

        if(vec[mid] < vec[h])
            h = mid;
        else          //vec[mid] > vec[h]  that is mid in the left shifted half so move to right
            l = mid + 1;
    }

    cout<<vec[l] << " "<<vec[h];


    return 0;
}