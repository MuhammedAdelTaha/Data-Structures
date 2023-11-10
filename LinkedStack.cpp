//
// Created by Mohamed Adel on 11/10/2023.
//

#include <cstddef>
#include <iostream>
using namespace std;
template <class t>

class LinkedStack{

private:

    struct node{
        t item ;
        node *next ;
    };
    node *top ;
    int size ;

public:

    LinkedStack(){
        top = NULL ;
        size = 0 ;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void push(t newItem){
        node *newItemPtr = new node ;
        newItemPtr->item = newItem ;
        newItemPtr->next = top ;
        top = newItemPtr ;
        size++ ;
    }

    void pop(){
        if(isEmpty()){
            cout << "the stack is empty !" << endl ; return;
        }
        node *temp = top ;
        top = top->next ;
        delete temp ;
        size-- ;
    }

    t getTop(){
        if(isEmpty()){
            cout << "the stack is empty !" << endl ;
        }
        else{
            return top->item;
        }
    }

    int getSize(){
        return size;
    }

    void display(){
        node *temp = top ;
        while(temp != NULL){
            cout << temp->item << endl ;
            temp = temp->next ;
        }
    }
};
