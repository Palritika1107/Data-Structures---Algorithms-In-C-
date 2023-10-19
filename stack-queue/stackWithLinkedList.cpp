#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next = NULL;

    Node(int val){
        this->val = val;
        next = NULL;
    }
    

};

class Stack{
    
    public:
    Node* top;
    Stack(){
       
         top = NULL;
    }

    void push(int data){

    Node* newNode = new Node(data);
    newNode -> next = top;
    top = newNode;
    

    }

    int pop(){

        if(top == NULL){
            cout<<"\n stack is empty";
            return -1;
        }
        else{
            Node* temp = top;
            int tempData = temp->val;
            top = top->next;
            delete temp;
            return tempData;
        }
    return 0;

    }

    int peek(){

        if(top == NULL){
            cout<<"\n stack is empty";
            return -1;
        }
        return top->val;
        

    }



    


    
};



int main(){

    Stack st;

    st.push(6);
    st.push(7);
    cout<<"\n top most element "<<st.peek();
    st.push(9);
    cout<<"\n "<<st.pop()<<" removed from stack";
    cout<<"\n "<<st.pop()<<" removed from stack";
    cout<<"\n "<<st.pop()<<" removed from stack";
    cout<<"\n "<<st.peek();


    return 0;
}