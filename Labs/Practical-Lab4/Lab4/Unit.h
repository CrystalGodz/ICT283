/**
*Doxygen commenting
*@author KRI
*@version 1.01
*@date 25/05/2024
*/

#ifndef Unit_H
#define Unit_H

#include <iostream>
#include <cstring>

using namespace std;
using std::string;

class Unit
{
public:
    Unit();
    Unit(const string& name, const string& id, unsigned credits);


    /** \brief Method to get unit credit
     *
     * \return unsigned
     *
     */
    unsigned GetCredits() const;
    /** \brief Method to get unit name
     *
     * \param name string&
     * \return void
     *
     */
    void GetName(string& name) const;
    /** \brief Method to get unit id
     *
     * \param id string&
     * \return void
     *
     */
    void GetId(string& id) const;


    /** \brief Method to set unit credit
     *
     * \param credits unsigned
     * \return void
     *
     */
    void SetCredits(unsigned credits);
    /** \brief Method to set unit name
     *
     * \param name const string&
     * \return void
     *
     */
    void SetName(const string& name);
    /** \brief Method to set unit id
     *
     * \param id const string&
     * \return void
     *
     */
    void SetId(const string& id);


private:
    /** \brief private constructors
     *
     * \param m_name string
     * \param m_id string
     * \param m_credits int
     * \return
     *
     */
    string m_name;
    string m_id;
    int  m_credits;   //number of credits
};

istream& operator >>(istream& input, Unit& unit);
ostream& operator <<(ostream& os, const Unit& unit);

#endif
