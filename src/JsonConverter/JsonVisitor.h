#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>

#include "../Dog/boarding.h"
#include "../Dog/breeding.h"
#include "../Dog/owner.h"

class JsonVisitor{
    private:
       QJsonObject object;

    public:
       QJsonObject getObj() const;
       void visit(const Breeding& breeding);
       void visit(const Boarding& boarding);
       void visit(const Owner& owner);
};

#endif
