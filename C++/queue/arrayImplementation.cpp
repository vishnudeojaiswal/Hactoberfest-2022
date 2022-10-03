//Simple implementation
#include <iostream>
using namespace std;
struct Queue{
int size,cap;
int *arr;
Queue(int c){
    cap=c;
    size=0;
    arr=new int[cap];
}
bool isFull(){return (size==cap);}
bool isEmpty(){return (size==0);}
void enqueue(int x){
    if(isFull()){return;}
    arr[size]=x;
    size++;
}
void dequeue(){
    if(isEmpty()){return;}
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
int getFront(){
    if(isEmpty()){return -1;}
    else{return 0;}
}
int getRear(){
    if(isEmpty()){return -1;}
    else{ return size-1;}
}
};
//efficient implementation using circular array
#include <iostream>
using namespace std;
struct Queue{
int size,cap,front;
int *arr;
Queue(int c){
    cap=c;
    size=0;
    arr=new int[cap];
    front=0;
}
bool isFull(){return (size==cap);}
bool isEmpty(){return (size==0);}
int getRear(){
    if(isEmpty()){return -1;}
    else{ return ((front+size-1)%cap);}
}
void enqueue(int x){
    if(isFull()){return;}
    int rear=getRear();
    rear=(rear+1)%cap;
    arr[rear]=x;
    size++;
}
void dequeue(){
    if(isEmpty()){return;}
   front=(front+1)%cap;
   size--;
}
int getFront(){
    if(isEmpty()){return -1;}
    else{return front;}
}

};