#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "Dog/dogvisitor.h"
#include "Dog/boarding.h"
#include "Dog/breeding.h"
#include <QJsonObject>
#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"


class JsonVisitor  : public DogVisitor
{
  private:
    QJsonObject object;

public:

    QJsonObject getObject() const;
    void visitBoarding(Boarding& boarding);
    void visitBreeding(Breeding& breeding);

};

#endif // JSONVISITOR_H
