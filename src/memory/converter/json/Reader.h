#ifndef READER_H
#define READER_H


#include <QList>
#include "Dog/breeding.h"
#include "Dog/boarding.h"
#include "Dog/owner.h"

#include <QJsonObject>

class Reader
{

private:
    QList<Dog*> dogList;
    QList<Owner*> ownerList;

public:

    //const QList<Dog*> getListDog() const;
    const QList<Owner*> getListOwner() const;

    //Reader& clearDog();
    Reader& clearOwner();

    //Dog* readDog(const QJsonObject& object);
    Owner* readOwner(const QJsonObject& object);


private:
    //Dog* readBreeding(const QJsonObject& object) const;
    //Dog* readBoarding(const QJsonObject& object) const;

    Owner* readOwner(const QJsonObject& object) const;


};

#endif // READER_H
