/**
*Doxygen commenting
*@author KRI
*@version 1.01
*@date 25/5/2024
*/

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

#include "Result.h"

using namespace std;

const unsigned MAX_RESULTS = 10;

class Registration
{
public:
    Registration();

    /** \brief Method to get total credits of all units
     *
     * \return unsigned
     *
     */
    unsigned GetTotalCredit() const;
    /** \brief Method to get unit count
     *
     * \return unsigned
     *
     */
    unsigned GetCount() const;
    /** \brief Method to get student's id
     *
     * \return long
     *
     */
    long GetStudentId() const;
    /** \brief Method to get semester
     *
     * \return unsigned
     *
     */
    unsigned GetSemester() const;
    /** \brief Method to get result array
     *
     * \return const Result*
     *
     */
    const Result* GetResults() const;                       //returns the array of Result
    //void GetResult(unsigned index, Result& result) const;   //returns a single Result

    /** \brief Method to set unit count
     *
     * \param count unsigned
     * \return void
     *
     */
    void SetCount(unsigned count);
    /** \brief Method to set student id
     *
     * \param studentId long
     * \return void
     *
     */
    void SetStudentId(long studentId);
    /** \brief Method to set semester
     *
     * \param semester unsigned
     * \return void
     *
     */
    void SetSemester(unsigned semester);
    /** \brief Method to set a single result
     *
     * \param index unsigned
     * \param result Result&
     * \return void
     *
     */
    void SetResult(unsigned index, Result& result);

private:
    /** \brief private constructors
     *
     * \param m_studentId long
     * \param m_semester unsigned
     * \param m_count unsigned
     * \param m_results Result
     * \return
     *
     */
    long m_studentId;               // student ID number
    unsigned m_semester;            // semester year, number
    unsigned m_count;               // number of Units
    Result m_results[MAX_RESULTS];  // array of Units
};

istream& operator >>(istream& input, Registration & registration);
ostream& operator <<(ostream& os, const Registration & registration);

#endif
