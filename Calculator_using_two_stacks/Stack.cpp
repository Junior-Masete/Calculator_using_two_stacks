#include "Stack.h"

template <class T>
Stack<T>::Stack(){
    this->top = NULL;
}

template <class T>
Stack<T>::~Stack(){
    Node<T>* nodePtr;
    nodePtr = top;
    while(nodePtr != NULL){
        top = nodePtr->getNext();
        delete nodePtr;
        nodePtr = top;
    }
}

template <class T>
void Stack<T>::push(T data){
    Node<T>* newNode = new Node<T>(data);
    if(isEmpty() == true){
        top = newNode;
    }
    else{
        newNode->setNext(top);
        top = newNode;
        
    }
}

template <class T>
Node<T>* Stack<T>::pop(){
    if(isEmpty()){
        return NULL;
    }
    else{
        Node<T>* nodePtr;
        Node<T>* nodePtr2;
        //nodePtr->getTop();
        nodePtr = top;
        top = top->getNext();
        nodePtr2 = nodePtr;
        //delete nodePtr;
        return nodePtr2;
    }
}

template <class T>
bool Stack<T>::isEmpty(){
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
Node<T>* Stack<T>::getTop(){
    if(isEmpty()){
        return NULL;
    }
    else{
        return top;
    }
}

template <class T>
int Stack<T>::size(){
    int numNodes = 0;
    

    if(top == NULL){
        return 0;
    }
    else{
        Node<T>* nodePtr;
        nodePtr = top;
        while(nodePtr != NULL){
           // nodePtr = top;
            numNodes++;
            //nodePtr->setNext(nodePtr->getNext());
            nodePtr = nodePtr->getNext();
        }

        return numNodes;
    }
}

template <class T> 
Stack<T>* Stack<T>::reverse(){
    Stack<T>* temp = new Stack<T>();
    Stack<T>* temp2 = new Stack<T>();

    temp2->top = top;

    if(!temp2->isEmpty()){
        while(temp2->getTop() != NULL){
            temp->push(temp2->pop()->getData());
        
        }

        return temp;
    }
    else{
        return temp;
    }
}

template <class T>
bool Stack<T>::contains(T data){

    if(!isEmpty()){
        Node<T>* nodePtr;
        nodePtr = top;

        while(nodePtr != NULL && nodePtr->getData() != data){
            nodePtr = nodePtr->getNext();
        }

        if(nodePtr != NULL){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}