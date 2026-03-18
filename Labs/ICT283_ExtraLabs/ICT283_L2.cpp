#include <iostream> //io library, cout, end

//std::cout, std""string, like a Java package
using namespace std;

//Prototype, Forward Declaration
int Sum(int x, int y);

bool Divide(int top, int bottom, int &quotient, int &remainder);

int main(){
    cout << "10 + 5 = " << endl;
    int result = Sum(10,5);
    cout << "Result: " << result << endl;


    int myQuotient;
    int myRemainder;
    int myTop = 20;
    int myBottom = 8;
    if(Divide(myTop, myBottom, myQuotient, myRemainder)){
        cout << myTop << " / " << myBottom << " = " << myQuotient << " r " << myRemainder << endl;
    }
    else{
        cout << "Divisor cannot be 0!" << endl;
    }


    return 0; //0 means no error
}

int Sum(int x, int y){
    return x + y;
}

bool Divide(int top, int bottom, int &quotient, int &remainder){
    if(bottom == 0){
        return false;
    }
    else{
        quotient = top / bottom;
        remainder = top % bottom;
        return true;
    }
}

/*
Method naming guidelines:
1). TitleCase
2). Start with a verb/action

eg. AuthenticateUser(), CalculateBMI(), ConvertToCelsius()

Variable naming guidelines:
1). CamelCasing
2). A Property

eg. color(), fullName(), studentCount()

Attribute naming guidelines:
1). Same as variable naming guidelines
2). prepend with [m_]

eg. m_height, m_firstName, m_transactionRecord
*/
