//
// Created by Mohamed Adel on 11/10/2023.
//

#include <algorithm>
#include <ios>
using namespace std;
template<class t>

class BinarySearchTree{

private:

    struct Node{
        t info ;
        Node* left ;
        Node* right ;
    };
    Node* root ;
    int numOfNodes ;

public:

    BinarySearchTree(){
        root = NULL ;
        numOfNodes = 0 ;
    }

    bool isEmpty(){
        return getSize() == 0 ;
    }

    int getSize(){
        return numOfNodes ;
    }

    bool add(t element){
        if(contains(element)){
            return false ;
        }
        root = add(root,element) ;
        numOfNodes++ ;
        return true;
    }


    bool remove(t element){
        if(contains(element)){
            root = remove(root , element) ;
            numOfNodes-- ;
            return true ;
        }
        return false ;
    }

    bool contains(t element){
        return contains(root , element);
    }

    int height(){
        return height(root);
    }

private:

    Node* add(Node* ptr , t element){
        if(ptr == NULL){
            Node* newPtr = new Node ;
            newPtr->info = element ;
            newPtr->right = NULL ;
            newPtr->left = NULL ;
            ptr = newPtr ;
        }
        else{
            if(element > ptr->info){
                ptr->right = add(ptr->right , element) ;
            }
            else if(element < ptr->info){
                ptr->left = add(ptr->left , element) ;
            }
        }
        return ptr;
    }

    Node* remove(Node* ptr , t element){

        if(element > ptr->info){
            ptr->right = remove(ptr->right , element) ;
        }
        else if(element < ptr->info){
            ptr->left = remove(ptr->left , element) ;
        }
        else{

            if(ptr->right == NULL){
                Node* tempPtr = ptr->left ;
                delete ptr ;
                return tempPtr;
            }
            else if(ptr->left == NULL){
                Node* tempPtr = ptr->right ;
                delete ptr ;
                return tempPtr;
            }
            else{
                Node* tempPtr = digLeft(ptr->right) ;
                ptr->info = tempPtr->info ;
                ptr->right = remove(ptr->right , tempPtr->info) ;
            }

        }
        return ptr ;

    }

    bool contains(Node* ptr , t element){
        if(ptr == NULL){
            return false ;
        }
        if(element > ptr->info){
            return contains(ptr->right , element) ;
        }
        else if(element < ptr->info){
            return contains(ptr->left , element) ;
        }
        else{
            return true ;
        }
    }

    Node* digLeft(Node* ptr){
        Node* tempPtr = ptr ;
        while(tempPtr->left != NULL){
            tempPtr = tempPtr->left ;
        }
        return tempPtr;
    }

    int height(Node* ptr){
        if(ptr == NULL){
            return 0;
        }
        return max(height(ptr->left) , height(ptr->right)) + 1 ;
    }

};
