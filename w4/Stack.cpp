#include "Stack.h"
Stack::Stack(){
    tail=0;
    printf("Stack constructor\n");
}
Stack::~Stack(){
    printf("Stack destructor\n");
}
void Stack::push(int val){
    if(tail<=20) datas[tail++]=val;
    if(tail>20) printf("Stack is full!\n");
}
void Stack::pop(){
    if(tail==0) printf("Stack is empty!\n");
    else tail--;
}
int Stack::top() const{
    if(tail==0){
        printf("Stack is empty!\n");
        return -1;
    }
    return datas[tail-1];
}
bool Stack::empty() const{
    return tail==0;
}
void Stack::clear(){
    tail=0;
}