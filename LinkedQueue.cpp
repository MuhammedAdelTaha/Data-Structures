//
// Created by Mohamed Adel on 11/10/2023.
//

#include <cstddef>
#include <iostream>
using namespace std;
template<class t>

class LinkedQueue{

private:

    struct Node{
        t item ;
        Node *next ;
    };
    Node *front ; Node *back ; int size ;

public:

    LinkedQueue(){
        front = back = NULL ;
        size = 0 ;
    }

    bool isEmpty(){
        return size == 0;
    }

    void push(t element){
        Node *newPtr = new Node ;
        newPtr->item = element ;
        newPtr->next = NULL ;
        if(size == 0){
            front = back = newPtr ;
        }
        else{
            back->next = newPtr ;
            back = newPtr ;
        }
        size++ ;
    }

    void pop(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ; return;
        }
        if(front == back){
            front = back = NULL ;
        }
        else{
            Node *temp ; temp = front ;
            front = front->next ;
            temp->next = NULL ;
            delete temp ;
        }
        size-- ;
    }

    t getFront(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ;
        }
        else{
            return front->item;
        }
    }

    t getBack(){
        if(isEmpty()){
            cout << "the queue is empty !" << endl ;
        }
        else{
            return back->item;
        }
    }

    int getSize(){
        return size;
    }

    void display(){
        cout << "[ " ;
        if(!isEmpty()){
            Node *displayPtr = front ;
            while(displayPtr != back){
                cout << displayPtr->item << " , " ;
                displayPtr = displayPtr->next ;
            }
            cout << displayPtr->item ;
        }
        cout << " ]" << endl ;
    }

};
