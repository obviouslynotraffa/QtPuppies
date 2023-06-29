#ifndef READER_H
#define READER_H


#include <QList>
#include "Dog/breeding.h"
#include "Dog/boarding.h"
#include "Dog/owner.h"
#include <QIODevice>


#include <QJsonObject>
#include <vector>

class Reader
{
private:
    std::vector<Owner*> owners;
    std::vector<Dog*> dogs;

    //Dog* lastDog;
    //Owner* lastOwner;

public:

    const std::vector<Dog*> getDogs() const;
    const std::vector<Owner*> getOWners() const;

    Reader& clearCache();


    //Dog* getLastDog() const;
    //Owner* getLastOwner() const;

    void read(const QJsonObject& object);


private:

    Dog* readBoarding(const QJsonObject& object)const;
    //Dog* readBreeding(const QJsonObject& object)const;
    Owner* readOwner(const QJsonObject& object)const;

};

#endif // READER_H
