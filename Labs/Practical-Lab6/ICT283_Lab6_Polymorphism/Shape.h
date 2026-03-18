#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

using namespace std;

class Shape{
public:
    Shape();
    virtual ~Shape() {};

    int GetHeight() const;
    void GetDescription(string& description) const;

    void SetHeight(int height);
    void SetDescription(const string& description);

    virtual int area() const = 0;

protected:
    int m_height;
    string m_description;
};


#endif // SHAPE_H_INCLUDED
