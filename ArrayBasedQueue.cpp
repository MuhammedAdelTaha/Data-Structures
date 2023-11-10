//
// Created by Mohamed Adel on 11/10/2023.
//

#include <iostream>
using namespace std ;
template <class t>

class ArrayBasedQueue{

private:

    int front ; int back ; int size ; t *arr ; int maxSize ;

public:

    explicit ArrayBasedQueue(int inputSize){
        if(inputSize <= 0){
            maxSize = 100 ;
        }
        else{
            maxSize = inputSize ;
        }
        arr = new t[maxSize] ;
        front = 0 ; back = maxSize - 1 ; size = 0 ;
    }

    bool isEmpty(){
        return size == 0 ;
    }

    bool isFull(){
        return size == maxSize ;
    }

    void push(t element){
        if(isFull()){
            cout << "the queue is full !" << endl ; return;
        }
        back = (back + 1) % maxSize ;
        arr[back] = element ;
        size++ ;
    }

    void pop(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ; return;
        }
        front = (front + 1) % maxSize ;
        size-- ;
    }

    t getFront(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ;
        }
        else{
            return arr[front];
        }
    }

    t getBack(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ;
        }
        else{
            return arr[back];
        }
    }

    int getSize(){
        return size;
    }

    void display(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ; return;
        }
        for(int i = front ; i != back ; i = (i+1)%maxSize){
            cout << arr[i] << ' ' ;
        }
        cout << arr[back] << endl ;
    }

};
