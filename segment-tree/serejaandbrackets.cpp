#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/380/problem/C


struct Node{

    int open;
    int close;
    int full;

    Node():open(0),close(0),full(0){}

    Node(int _open,int _close,int _full):open(_open),close(_close),full(_full){}




};

Node merge(Node node1,Node node2){

    Node newNode;

    newNode.full = node1.full + node2.full + min(node1.open,node2.close);

    newNode.open = node1.open + node2.open - min(node1.open,node2.close);

    newNode.close = node1.close + node2.close - min(node1.open,node2.close);

    return newNode;


}

void build(string &s,int segIndex,int lo,int hi,Node segment[]){

    if(lo == hi){

        segment[segIndex] = {s[lo]=='(' , s[lo]==')',0};
        cout<<segment[segIndex].open<<" "<<segment[segIndex].close<<" "<<s[lo]<<" " <<lo<<"\n";
        return;
    }


    int mid = (lo + hi)/2;

    build(s,segIndex*2 + 1,lo,mid,segment);
    build(s,segIndex*2 + 2,mid + 1,hi,segment);

    segment[segIndex] = merge(segment[segIndex*2 + 1] , segment[segIndex*2 + 2]);


    
}

Node query(Node segment[],int segIndex,int lo,int hi,int l,int r){

    //no overlap
    if(hi<l || lo>r){
        return {0,0,0};

    }

    else if(lo>=l && hi<=r){  //complete overlap

        return segment[segIndex];

    }   


    //partial overlap

    int mid = (lo + hi)/2;

    Node left = query(segment,segIndex*2 + 1,lo,mid,l,r);
    Node right = query(segment,segIndex*2 + 2,mid + 1,hi,l,r);

    return merge(left,right);


}

int main(){

    string pattern = "(())((()()";
    //length = 10

    int len = pattern.length();
    cout<<len<<" "<<"\n";

    Node segment[4*len];

    build(pattern,0,0,len - 1,segment);
    
    cout<<segment[0].full<<"\n";

    Node res = query(segment,0,0,len - 1,4 , 7);

    cout<<res.full;


    




    return 0;
}

