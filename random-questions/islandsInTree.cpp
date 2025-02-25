// Given a tree having nodes with value 0 and 1. write a function to return the number of islands ?


// Follow Up Questions to ask : 


// Are we giving root node as start node or it can vary ?
// Maximum number of children nodes for the node ?

//Follow up questions asked :
//1)Return the sizes of unique islands
//2)Number of distinct Isomorphic islands ? ( structure wise different ).

#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 

    int val;
    vector<Node*>children;

    Node(int nodeVal,int nos){

        val = nodeVal;
        children.resize(nos);
    }

    void addChild(Node* child){

        children.push_back(child);

    }
};



int main(){

    Node* root = new Node(0,3);
    

    return 0;
}