#ifndef BREED_H
#define BREED_H
#include <string>

class Breed{
    public:
    virtual double price() const=0;
    virtual std::string toString()const =0;
    virtual ~Breed()=default;
};

#endif
