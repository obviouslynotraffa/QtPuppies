#include "date.h"

#include <QDate>

Date::Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y) {}

Date::~Date() {}


unsigned int Date::getYear() const {
    return year;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getDay() const {
    return day;
}

std::ostream& operator<<(std::ostream& o, const Date& d){
    return o<<d.getDay()<<"/"<<d.getMonth()<<"/"<<d.getYear();
}


unsigned int Date::countLeapYear(const Date& d){

    unsigned int an=d.getYear();

    if(d.getMonth()<=2) an--;

    return an/4-an/100+an/400;
}


Date* Date::setDay(const int& x){
    day=x;
    return this;
}

Date* Date::setMonth(const int& x){
    month=x;
    return this;
}

Date* Date::setYear(const int& x){
    year=x;
    return this;
}

unsigned int Date::operator-(const Date& d){

    Date aux;
    aux.year= year;
    aux.day=day;
    aux.month=month;

    int n1=convert(aux);
    int n2=convert(d);

    return n1-n2;
}



unsigned int Date::convert(const Date& d){
    const int daysMonth[12]={30,28,31,30,31,30,31,31,30,31,30,31};

    long n=d.getYear()*365+d.getDay();

    for(unsigned int i=0;i<d.getMonth()-1;i++)n+=daysMonth[i];

    n+=countLeapYear(d);

    return n;

}



bool Date::operator==(const Date& d){
    return day==d.day && month==d.month && year==d.year;
}

bool Date::operator<(const Date& d){

    unsigned int dy=d.getYear();
    unsigned int dm=d.getMonth();
    unsigned int dd=d.getDay();

    if(dy>year) return true;
    else if(dy<year) return false;
    else{
        if(dm>month) return true;
        else if(dm<month) return false;
        else{
            if(dd>day) return true;
            else if(dd<day) return false;
            else return true;
        }
    }


}

bool Date::checkLeapYear(int x){
      if (x % 400 == 0)
        return true;

    if (x % 100 == 0)
        return false;

    if (x % 4 == 0)
        return true;
    return false;
}

Date Date::addDays(unsigned int x){

    unsigned int daysMonth[12]={30,28,31,30,31,30,31,31,30,31,30,31};;
    if(checkLeapYear(year)) daysMonth[1]=29;


    x=x-daysMonth[month-1]+day;
    day=1;
    month++;

    while(x>=daysMonth[month-1]){
        if(month!=12){
            x=x-daysMonth[month-1];
            month++;
        } else{
            x=x-daysMonth[11];
            month=1;
            year++;
            if(checkLeapYear(year))daysMonth[1]=29;
            else daysMonth[1]=28;
        }
    }
    day=day+x;

    Date date(day,month,year);

    return date;
}


std::string Date::toString() const{
    std::string date= ""+ std::to_string(day) + "/" + std::to_string(month) + "/"+ std::to_string(year);
    return date;
}


Date Date::toDate(std::string s) {

    QString str= QString::fromStdString(s);
    QString format("d/M/yyyy");

    QDate time=QDate::fromString(str, format);

    unsigned int d= time.day();
    unsigned int m= time.month();
    unsigned int y= time.year();

    Date date(d,m,y);

    return date;

}
