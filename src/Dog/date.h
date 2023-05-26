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

    Date* setDay(const int& x);
    Date* setMonth(const int& x);
    Date* setYear(const int& x);

    bool operator==(const Date& d);
    bool operator<(const Date& d);
    unsigned int operator-(const Date& d);

    static unsigned int countLeapYear(const Date& d);
    static unsigned int convert(const Date& d);
    Date addDays(unsigned int x);
    static bool checkLeapYear(int x);

    std::string toString() const;


};


#endif
