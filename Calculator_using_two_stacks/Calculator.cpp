#include "Calculator.h"

template <class T>
Calculator<T>::Calculator(){
    valueStack = new Stack<T>();
    operatorStack = new Stack<Operator<T>*>();
}

template <class T>
Calculator<T>::~Calculator(){
    delete valueStack;
    delete operatorStack;
}

template <class T>
void Calculator<T>::addValue(T val){
    valueStack->push(val);
}

template <class T>
void Calculator<T>::addOperator(Operator<T>* op){
    operatorStack->push(op->clone());
}

template <class T>
T Calculator<T>::removeValue(){
    T val;
    Node<T>* topVal;
    topVal = valueStack->pop();
    val = topVal->getData();
    return val;
}

template <class T>
Operator<T>* Calculator<T>::removeOperator(){
    Node<Operator<T>*>* topOp;
    topOp = operatorStack->pop();
    return topOp;
}

template <class T>
int Calculator<T>::numValues(){
    return valueStack->size();
}

template <class T>
int Calculator<T>::numOperators(){
    return operatorStack->size();
}

template <class T>
T Calculator<T>::calculate(){
    T val1, val2, val3;

    Node<Operator<T>*>* opp;
    if((numValues() < 2 && numOperators() > 0) || numValues()-1 != numOperators()){
        return 0;
    }
    else{
        while(!operatorStack->isEmpty()){
            val1 = valueStack->pop()->getData();
            val2 = valueStack->pop()->getData();
            opp = operatorStack->pop();
            val3 = opp->getData()->operator()(val1, val2);
            valueStack->push(val3);

        }

        return valueStack->getTop()->getData();
    }

}