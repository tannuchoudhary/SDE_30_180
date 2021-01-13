#include<bits/stdc++.h>
#define size 1000
using namespace std;

class Stack{
    private:
    int top;
    int ar[size];
    
    public:
    Stack(){
        top = -1;
    }
    
    bool push(int x){
        if(top>=size-1){
            cout<<"STACK OVERFLOW"<<endl;
            return false;
        }
        ar[++top] = x;
        cout<<x<<" is pushed in your stack"<<endl;
        return true;
    }
    
    int pop(){
        if(top<0){
            cout<<"STACK UNDERFLOW"<<endl;
            return 0;
        }
        int v = ar[top--];
        return v;
    }
    
    void display(){
        cout<<"RIGHT NOW THIS IS YOUR STACK"<<endl;
        for(int i=0; i<=top; i++)
        cout<<ar[i]<<endl;
    }
};

int main(){
    class Stack s;
    s.push(1);
    s.push(5);
    int m=s.pop();
    cout<<m<<" is popped from stack"<<endl;
    s.push(10);
    s.push(29);
    s.display();
    return 0;
}
