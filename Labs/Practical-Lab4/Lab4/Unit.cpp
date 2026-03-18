#include "Unit.h"


Unit::Unit()
{
    m_name = "";
    m_id = "";
    m_credits = 0;
}

Unit::Unit(const string& name, const string& id, unsigned credits)
{
    m_name = name;
    m_id = id;
    m_credits = credits;
}



unsigned Unit::GetCredits() const
{
    return m_credits;
}

void Unit::GetName(string& name) const
{
    name = m_name;
}

void Unit::GetId(string& id) const
{
    id = m_id;
}



void Unit::SetCredits( unsigned credits )
{
    m_credits = credits;
}

void Unit::SetName(const string& name)
{
    m_name = name;
}

void Unit::SetId(const string& id)
{
    m_id = id;
}


istream& operator >>(istream& input, Unit& unit)
{
    char delimiter = ',';
    string data;
    getline(input, data, delimiter);
    unit.SetName(data);

    getline(input, data, delimiter);
    unit.SetId(data);

    getline(input, data, delimiter);
    unit.SetCredits(stoi(data));
    cout << unit.GetCredits() << "Credit" << endl;

    return input;
}


ostream& operator <<(ostream& os, const Unit& unit)
{
    string name;
    string id;
    unit.GetName(name);     //return via parameter
    unit.GetId(id);         //return via parameter

    os << "  Unit   : " << name << '\n'
       << "  ID     : " << id << '\n'
       << "  Credit : " << unit.GetCredits() << '\n';

    return os;
}
