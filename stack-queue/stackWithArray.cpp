#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    // int val;
    int top;
    int size;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    };

    void push(int element)
    {

        if ((size - top) <= 1)
            cout << "stack overflow" << endl;
        else
        {

            top++;
            arr[top] = element;
        }
    }

    void pop()
    {

        if (top == -1)
            cout << "stack underflow" << endl;
        else
            top--;
    }

    int peek()
    {

        if (top == -1)
        {
            cout << "no elements";
            return -1;
        }
        else
        {
            // cout<<"topmost element :"<<arr[top];
            return arr[top];
        }
    }

    void isEmpty()
    {

        if (top == -1)
            cout << "stack is empty" << endl;
        else
            cout << "stack is not empty" << endl;
    }
};

int main()
{

    Stack st(6);

    st.push(7);
    st.push(8);
    st.push(9);
    cout << st.peek() << endl;
    st.push(10);
    st.push(5);
    st.push(4);
    st.push(3);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.peek();

    return 0;
}