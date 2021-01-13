#include<bits/stdc++.h>
#define size 5
using namespace std;

class Queue{
    private:
    int front;
    int rear;
    int ar[size];
    public:
    Queue(){
        front = 0;
        rear = 0;
    }
    
    bool enq(int x){
        if(rear==size){
            cout<<"Can't insert, as your queue is full"<<endl;
            return false;
        }
        else{
            ar[rear++] = x;
            cout<<x<<" is pushed into a queue"<<endl;
            return true;
        }
    }
    
    int deq(){
        if(front==rear){
            cout<<"Can't delete as your queue is empty"<<endl;
            return 0;
        }
        else{
            int v = ar[front++];
            return v;
        }
        
    }
    
    void display(){
        cout<<"Right now this is your queue"<<endl;
        for(int i=front; i<=rear; i++){
            cout<<ar[i]<<endl;
        }
    }
   
};

int main(){
   class Queue q;
   q.enq(10);
   q.enq(20);
   q.enq(30);
   q.enq(50);
   int d = q.deq();
   cout<<d<<" is deleted from queue"<<endl;
   q.display();
   
    return 0;
}
