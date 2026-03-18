#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <iomanip>

/** \class Time
 * \brief Time object
 *
 * \author Clarence Lim Xing Yu
 * \version 1.01
 * \date 21/06/2024 Last Modified.
 *
 */

using namespace std;

class Time{
public:
    Time();
    Time(unsigned hour, unsigned minute, unsigned second);

    /** \brief Method to get hour
     *
     * \return unsigned
     *
     */
    unsigned GetHour() const;
    /** \brief Method to get minute
     *
     * \return unsigned
     *
     */
    unsigned GetMinute() const;
    /** \brief Method to get second
     *
     * \return unsigned
     *
     */
    unsigned GetSecond() const;

    /** \brief Method to set hour
     *
     * \param hour unsigned
     * \return void
     *
     */
    void SetHour(unsigned hour);
    /** \brief Method to set minute
     *
     * \param minute unsigned
     * \return void
     *
     */
    void SetMinute(unsigned minute);
    /** \brief Method to set second
     *
     * \param second unsigned
     * \return void
     *
     */
    void SetSecond(unsigned second);

private:
    /** \brief
     *
     * \param m_hour unsigned
     * \param m_minute unsigned
     * \param m_second unsigned
     *
     */
    unsigned m_hour = 0;
    unsigned m_minute = 0;
    unsigned m_second = 0;
};

istream& operator >>(istream& input, Time& time);
ostream& operator <<(ostream& os, const Time& time);

#endif // TIME_H_INCLUDED
