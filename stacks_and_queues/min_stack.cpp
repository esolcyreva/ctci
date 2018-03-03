#include <iostream>
#include <stack>
using namespace std;

stack<int> orig_stack;
stack<int> min_stack;

void push(int data) {
    if (min_stack.empty() || (min_stack.top() > data)) {
        min_stack.push(data);
    }
    orig_stack.push(data);
}

void pop() {
    if (orig_stack.empty()) {
        return;
    }
    if (orig_stack.top() == min_stack.top()) {
        orig_stack.pop();
        min_stack.pop();
    } else {
        orig_stack.pop();
    }
}

int min() {
    if (!min_stack.empty()) {
        return min_stack.top();
    }
}

int main()
{
    int global_min = 9999;
    push(21);
    cout<<"Min of stack = "<<min()<<endl;
    push(33);
    cout<<"Min of stack = "<<min()<<endl;
    push(7);
    cout<<"Min of stack = "<<min()<<endl;
    push(14);
    cout<<"Min of stack = "<<min()<<endl;
    push(6);
    cout<<"Min of stack = "<<min()<<endl;
    push(15);
    cout<<"Min of stack = "<<min()<<endl;
    push(1);
    cout<<"Min of stack = "<<min()<<endl;
    push(12);
    cout<<"Min of stack = "<<min()<<endl;
    pop();
    cout<<"Min of stack = "<<min()<<endl;
    pop();
    cout<<"Min of stack = "<<min()<<endl;
}
