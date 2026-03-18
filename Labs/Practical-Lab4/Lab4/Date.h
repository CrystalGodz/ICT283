#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;
using std::string;

class Date{
public:
    /** \brief
     *
     * Default Constructor
     *
     */
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
     * \param m_day int
     * \param m_month int
     * \param m_year int
     * \return
     *
     */
    int m_day;
    int m_month;
    int m_year;
};

istream& operator >>(istream& input, Date& date);
ostream& operator <<(ostream& os, const Date& date);

#endif // DATE_H_INCLUDED
