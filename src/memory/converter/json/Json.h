#ifndef JSON_H
#define JSON_H


#include <QJsonObject>
#include "Dog/breeding.h"
#include "Dog/boarding.h"
#include "Dog/owner.h"

#include "Reader.h"

class Json {

    private:
    Reader& reader;

    public:
        Json(Reader& reader);
        const Reader& getReader() const;

        //QJsonObject fromObject(const Breeding& dog) const;
        //QJsonObject fromObject(const Boarding& dog) const;
        QJsonObject fromObject(const Owner& owner) const;

        //Dog* toDogObject(const QJsonObject& json) const;
        Owner* toOwnerObject(const QJsonObject &json) const;

};


#endif
