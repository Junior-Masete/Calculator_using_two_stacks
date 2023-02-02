#ifndef OPERATOR_H
#define OPERATOR_H


template <class T>
class Operator{
    public:
        Operator(){
            //left empty
        };
        virtual T operator()(T lhs, T rhs) = 0;
        virtual Operator<T>* clone() = 0;
        virtual ~Operator(){
            //left empty
        };

};

#endif