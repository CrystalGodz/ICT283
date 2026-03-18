#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <iostream>
#include "Unit.h"

using namespace std;

class Result{
    public:
        Result();   // default constructor
        Result(const Unit & unit, float mark);

        //Get and Set Methods
        float GetMark() const;          //return by value
        void GetUnit(Unit & unit) const;//return by reference

        void SetMark(float mark);
        void SetUnit(Unit & unit);


        friend ostream & operator <<( ostream & ostr, const Result & result );
        friend istream & operator >>( istream & input, Result & result );

    private:
        Unit m_unit;
        float m_mark;


};

#endif // RESULT_H_INCLUDED
