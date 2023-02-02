
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Operator.h"
#include "MinusOperator.h"
#include "MultiplyOperator.h"
#include "PlusOperator.h"
#include "Node.h"
#include "Stack.h"
#include "Calculator.h"



int main(){
     
    MinusOperator<int>* minusOp= new MinusOperator<int>();
    PlusOperator<int>* plusOp = new PlusOperator<int>();
    Calculator<int>* calculate = new Calculator<int>();
    //Adding values to the stack
    calculate->addValue(3);
    calculate->addValue(2);
    calculate->addValue(1);
    //passing the operators
    calculate->addOperator(minusOp);
    calculate->addOperator(plusOp);

    cout << "The Number of values is: " << endl;
    cout<< calculate->numValues() << endl;
    cout << "The number of operators is: " << endl;
    cout <<calculate->numOperators() << endl;

    cout << "The Expression: " << endl;
    cout << calculate->removeValue() << " ";
    cout << calculate->removeValue() << " " ;
    cout << calculate->removeValue() << endl;

    cout << "Calculations -----------" << endl;
    int calculateVal = calculate->calculate();
    cout << "Value after the calculations is: " << calculateVal << endl;
    //cout << "Calculator Value 1: " << calculate->removeValue() << endl;
    
    delete minusOp;
    delete plusOp;
    delete calculate;

    return 0;
   
}



