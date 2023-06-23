#include "Json.h"
#include "QJsonArray"

#include <QVariant>

Json::Json(Reader &reader)
    :reader(reader)
{
}


const Reader& Json::getReader() const{
    return reader;
}

/*
QJsonObject Json::fromObject(const Boarding &dog) const{
    QJsonObject boardingObject;

    boardingObject.insert("type",QJsonValue::fromVariant("boarding"));
    boardingObject.insert("name",QJsonValue::fromVariant(dog.getName()).c_str);
    boardingObject.insert("date",QJsonValue::fromVariant(dog.getDate()));
    boardingObject.insert("size",QJsonValue::fromVariant(dog.getSize()));
    boardingObject.insert("owner",QJsonValue::fromVariant(dog.getOwner()));
    boardingObject.insert("breed",QJsonValue::fromVariant(dog.getBreed().c_str);
    boardingObject.insert("bath",QJsonValue::fromVariant(dog.didBath()));
    boardingObject.insert("walking",QJsonValue::fromVariant(dog.didWalking()));
    boardingObject.insert("diet",QJsonValue::fromVariant(dog.didDiet()));
    boardingObject.insert("training",QJsonValue::fromVariant(dog.didTraining()));

    return boardingObject;
}


QJsonObject Json::fromObject(const Breeding &dog) const{

    QJsonObject breedingObject;

    breedingObject.insert("type",QJsonValue::fromVariant("breeding"));
    boardingObject.insert("name",QJsonValue::fromVariant(dog.getName().c_str));
    boardingObject.insert("date",QJsonValue::fromVariant(dog.getDate()));
    boardingObject.insert("breed",QJsonValue::fromVariant(dog.getBreed()));
    boardingObject.insert("vax",QJsonValue::fromVariant(dog.isVax()));
    boardingObject.insert("booked",QJsonValue::fromVariant(dog.isBooked()));
    boardingObject.insert("purch",QJsonValue::fromVariant(dog.isPurchasable()));
    boardingObject.insert("mom",QJsonValue::fromVariant(dog.getMother()));
    boardingObject.insert("dad",QJsonValue::fromVariant(dog.getFather()));

    return breedingObject;

}
*/

QJsonObject Json::fromObject(const Owner &owner) const{

    QJsonObject ownerObject;

    ownerObject.insert("type", QJsonValue(QString("owner")));
    ownerObject.insert("name", QJsonValue(QString::fromStdString(owner.getName())));
    ownerObject.insert("surname", QJsonValue(QString::fromStdString(owner.getSurname())));
    ownerObject.insert("phone", QJsonValue(QString::fromStdString(owner.getPhone())));
    ownerObject.insert("address", QJsonValue(QString::fromStdString(owner.getAddress())));
    ownerObject.insert("house_number", QJsonValue(QString::fromStdString(owner.getHouseNumber())));
    ownerObject.insert("birth", QJsonValue(QString::fromStdString(owner.getBirthD().toString())));


    return ownerObject;

}

/*
Dog* Json::toDogObject(const QJsonObject &json) const{
    return reader.readDog(json);
}
*/

Owner* Json::toOwnerObject(const QJsonObject &json) const{
    return reader.readOwner(json);
}
