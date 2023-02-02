#include "PlusOperator.h"

template <class T>
T PlusOperator<T>::operator()(T lhs, T rhs){
    return lhs + rhs;
}

template <class T>
Operator<T>* PlusOperator<T>::clone(){
    PlusOperator<T>* oprtPtr = new PlusOperator<T>();
    return oprtPtr;
}