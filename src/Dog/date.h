#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <string>

class Date{
    private:
        unsigned int day;
        unsigned int month;
        unsigned int year;
    public:
    Date() {}
    Date(unsigned int d, unsigned int m, unsigned int y);
    ~Date();

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    void setDay(int x);
    void setMonth(int x);
    void setYear(int x);

    bool operator==(const Date& d);
    bool operator<(const Date& d);
    unsigned int operator-(const Date& d);
    static unsigned int countLeapYear(const Date& d);
    static unsigned int convert(const Date& d);
    Date addDays(unsigned int x);
    static bool checkLeapYear(int x);
    //std::string toString(Date& d);


};


std::ostream& operator<<(std::ostream& o, const Date& d);


#endif
