#include "Json.h"
#include "QJsonArray"
#include "memory/converter/json/JsonVisitor.h"

#include <QVariant>

Json::Json(Reader &reader)
    :reader(reader)
{
}


const Reader& Json::getReader() const{
    return reader;
}



QJsonObject Json::fromDog(Dog &dog) const{
    JsonVisitor visitor;
    dog.accept(visitor);
    return visitor.getObject();
}


QJsonObject Json::fromOwner(const Owner &owner) const{

    QJsonObject ownerObject;

    ownerObject.insert("type", QJsonValue::fromVariant("owner"));
    ownerObject.insert("name",QJsonValue::fromVariant(owner.getName().c_str()));
    ownerObject.insert("surname",QJsonValue::fromVariant(owner.getSurname().c_str()));
    ownerObject.insert("phone",QJsonValue::fromVariant(owner.getPhone().c_str()));
    ownerObject.insert("day",QJsonValue::fromVariant(owner.getBirthD().getDay()));
    ownerObject.insert("month",QJsonValue::fromVariant(owner.getBirthD().getMonth()));
    ownerObject.insert("year",QJsonValue::fromVariant(owner.getBirthD().getYear()));
    ownerObject.insert("address",QJsonValue::fromVariant(owner.getAddress().c_str()));
    ownerObject.insert("house_number",QJsonValue::fromVariant(owner.getHouseNumber().c_str()));

    return ownerObject;
}


Dog* Json::toDogObject(const QJsonObject &json) const{
    reader.read(json);
    return reader.getDogs().back();
}


Owner* Json::toOwnerObject(const QJsonObject &json) const{
    reader.read(json);
    return reader.getOWners().back();
}
