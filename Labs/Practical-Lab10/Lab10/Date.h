#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <iomanip>

/** \class Date
 * \brief Date object
 *
 * \author Clarence Lim Xing Yu
 * \version 1.01
 * \date 21/06/2024 Last Modified.
 *
 */


using namespace std;

class Date{
public:
    Date();
    Date(unsigned day, unsigned month, unsigned year);

    /** \brief Method to get the day
     *
     * \return unsigned
     *
     */
    unsigned GetDay() const;
    /** \brief Method to get the month
     *
     * \return unsigned
     *
     */
    unsigned GetMonth() const;
    /** \brief Method to get the year
     *
     * \return unsigned
     *
     */
    unsigned GetYear() const;

    /** \brief Method to set the day
     *
     * \param day unsigned
     * \return void
     *
     */
    void SetDay(unsigned day);
    /** \brief Method to set the month
     *
     * \param month unsigned
     * \return void
     *
     */
    void SetMonth(unsigned month);
    /** \brief Method to set the year
     *
     * \param year unsigned
     * \return void
     *
     */
    void SetYear(unsigned year);

private:
    /** \brief private constructors
     *
     * \param m_day unsigned
     * \param m_month unsigned
     * \param m_year unsigned
     *
     */
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
};

istream& operator >>(istream& input, Date& date);
ostream& operator <<(ostream& os, const Date& date);

#endif // DATE_H_INCLUDED
