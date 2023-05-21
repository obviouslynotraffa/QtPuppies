#ifndef DOGVISITOR_H
#define DOGVISITOR_H

#include <QWidget>

class Breeding;
class Boarding;

class DogVisitor: public QWidget {

    public:
        virtual ~DogVisitor() = default;
        virtual void visitBreeding(Breeding& breeding)=0;
        virtual void visitBoarding(Boarding& boarding)=0;
};

#endif // DOGVISITOR_H
