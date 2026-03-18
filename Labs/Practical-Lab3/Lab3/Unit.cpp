// Unit.CPP - Unit class implementation

#include "Unit.h"


Unit::Unit()
{
    m_name[0] = '\0'; // it is a char * string, not a C++ string object.
    m_id[0] = '\0';
    m_credits = 0;
}

Unit::Unit( const char * name, const char * id, unsigned credits )
{
    strncpy( m_name, name, UNIT_NAME_SIZE );  //strncpy needed from string.h
    strncpy( m_id, id, UNIT_NAME_SIZE );
    m_credits = credits;
}

unsigned Unit::GetCredits() const
{
    return m_credits;
}

void Unit::SetCredits( unsigned credits )
{
    m_credits = credits;
}


// The following routine does not belong to the Unit class, so it is NOT a method
// You can see that the prefix Unit:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
istream & operator >>( istream & input, Unit & unit )
{
    input >> unit.m_name >> unit.m_id >> unit.m_credits;
    return input;
}


// The following routine does not belong to the Unit class, so it is NOT a method
// You can see that the prefix Unit:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream & operator <<( ostream & os, const Unit & unit )
{
    os << "  Unit    : " << unit.m_name << '\n'
       << "  ID      : " << unit.m_id << '\n'
       << "  Credits : " << unit.m_credits << '\n';
    return os;
}
