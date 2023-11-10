//
// Created by Mohamed Adel on 11/10/2023.
//

#include <iostream>
using namespace std;
template <class t>

class ArrayBasedStack {

    int top ; t *arr ; int maxSize ;

    public :
    explicit ArrayBasedStack(int inputSize){
        if(inputSize <= 0){
            maxSize = 100 ;
        }
        else{
            maxSize = inputSize ;
        }
        arr = new t[maxSize] ;
        top = -1 ;
    }

    bool isEmpty(){
        return top == -1 ;
    }

    void push(t element){
        if(top == maxSize-1){
            cout << "the stack is full !" << endl ; return ;
        }
        top++ ;
        arr[top] = element ;
    }

    void pop(){
        if(isEmpty()){
            cout << "the stack is empty !" << endl ; return ;
        }
        top-- ;
    }

    t getTop(){
        if(isEmpty()){
            cout << "the stack is empty !" << endl ;
        }
        else{
            return arr[top] ;
        }
    }

    int size(){
        return top+1 ;
    }

    void display(){
        if(isEmpty()){
            cout << "the stack is empty !" << endl ;
        }
        for(int i = top ; i >= 0 ; i--){
            cout << arr[i] << endl ;
        }
    }

};
