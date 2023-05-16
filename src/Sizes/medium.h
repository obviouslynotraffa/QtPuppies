#ifndef MEDIUM_H
#define MEDIUM_H
#include "size.h"
#include "Dog/date.h"



class Medium: public Size {

    private:
    static double multiplier;
    public:
         double stayTax(const Date& d) const;
         double bath() const;
         double training() const;
         double diet () const;
         double walkDog() const;
};


#endif
