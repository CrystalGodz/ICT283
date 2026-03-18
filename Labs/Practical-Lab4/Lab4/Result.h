#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <iostream>

#include "Unit.h"
#include "Date.h"

using namespace std;

class Result
{
public:
    Result();   // default constructor
    Result(const Unit& unit, const Date& date, float mark);


    /** \brief Method to get mark
     *
     * \return float
     *
     */
    float GetMark() const;          //return by value
    /** \brief Method to get unit
     *
     * \param unit Unit&
     * \return void
     *
     */
    void GetUnit(Unit& unit) const; //return by reference
    /** \brief Method to get date
     *
     * \param date Date&
     * \return void
     *
     */
    void GetDate(Date& date) const; //return by reference

    /** \brief Method to set mark
     *
     * \param mark float
     * \return void
     *
     */
    void SetMark(float mark);
    /** \brief Method to set unit
     *
     * \param unit const Unit&
     * \return void
     *
     */
    void SetUnit(const Unit& unit);
    /** \brief Method to set date
     *
     * \param date const Date&
     * \return void
     *
     */
    void SetDate(const Date& date);

private:
    /** \brief private constructors
     *
     * \param m_unit Unit
     * \param m_date Date
     * \param m_mark float
     * \return
     *
     */
    Unit m_unit;
    Date m_date;
    float m_mark;
};

istream& operator >>(istream& input, Result& result);
ostream& operator <<(ostream& ostr, const Result& result);

#endif // RESULT_H_INCLUDED
