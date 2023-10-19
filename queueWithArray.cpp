#include<bits/stdc++.h>
using namespace std;

class Queue{

public:

int n;
int *arr;
int  i = -1;

Queue(int n){
    this->n = n;
     arr =  new int[n];
}

void push(int element){
if(isFull()){
    cout<<"\n queue overflowed";
    return;
}

i++;
arr[i] = element;
cout<<"\n pushed"<<" "<<arr[i];

}

void pop(){

if(isEmpty()){
    cout<<"\n queue has undeflown";
    return;
}

//1 2 3 4
//2 3 4 
int popElement  = arr[0];
for(int j=0;j<i;j++){
    arr[j] = arr[j + 1];
}
i--;
cout<<"\n popped"<<" "<<popElement;


}

int  front(){

if(isEmpty()){
    cout<<"\n queue had underflown";
    return -1;
}

return arr[0];


}

bool isFull(){

    return i==(n - 1);

}

bool isEmpty(){

    return i==(-1);
}




};



int main(){

        Queue q(4);
        q.push(4);
        q.push(3);
       cout<<"\n topmost element:"<< q.front();
        q.push(5);
       q.push(7);
       q.pop();
       cout<<"\n topmost element is :"<<q.front();
    //    q.push(9);
    //    q.pop();
    //    q.pop();
    //    q.pop();
    //    q.pop();
    //    q.pop();
    //    q.front();

    return 0;
}