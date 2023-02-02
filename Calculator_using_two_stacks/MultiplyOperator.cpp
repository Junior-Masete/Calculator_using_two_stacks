#include "MultiplyOperator.h"

template <class T>
T MultiplyOperator<T>::operator()(T lhs, T rhs){
    return lhs * rhs;
}

template <class T>
Operator<T>* MultiplyOperator<T>::clone(){
    MultiplyOperator<T>* oprtPtr = new MultiplyOperator<T>();
    return oprtPtr;
}