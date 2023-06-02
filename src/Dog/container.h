#ifndef CONTAINER_H
#define CONTAINER_H

#include "dog.h"
#include "breeding.h"
#include "breeds/breed.h"
#include "breeds/bulldog.h"
#include "breeds/amstaff.h"
#include "boarding.h"
#include "./sizes/size.h"
#include "./sizes/medium.h"
#include "./sizes/large.h"
#include "./sizes/small.h"

class Node;

class Container{
    public:
        class Node{
            private:
                Dog* dog;
                Node* next;
            public:
                Node(Dog* d, Node* n=nullptr): dog(d), next(n) {}
                Dog* getDog() const {return dog;}
                Node& setDog(Dog* d) {this->dog=d; return *this;}
                Node* getNext() const {return next;}
                Node& setNext(Node* next) {this->next=next; return *this;}
        };
    private:
        Node* head;

        /*
        static Node* copy(Node* n){
            if(!n) return 0;
            return new Node(n->getDog(),copy(n->getNext()));
        }

        static void destroy(Node* n){
        if(n){
            destroy(n->getNext());
            delete n;
        }
        }*/

    public:
        Container(): head(nullptr) {}
        ~Container() {}

        //Container(const Container& c){head(copy(c.head));}

        Node* getHead() const {return head;}



        unsigned int getSize() const{
            unsigned int t=0;
            Node* n=head;
            while(n!=nullptr){
                n=n->getNext();
                t++;
            }
            return t;
        }


        Container& push_back(Dog* d){
            head = new Node(d,head);
            return *this;
        }



        Container& erase(Dog* d){
            Node* prev=nullptr;
            Node* curr=head;

            while(curr!=nullptr){
                if(curr->getDog()==d){
                    if(prev!=nullptr){
                        prev->setNext(curr->getNext());
                    } else {
                        head=curr->getNext();
                    }


                    delete curr;
                    return *this;
                }
                prev=curr;
                curr=curr->getNext();
            }
            return *this;
        }


        Container& clearAll(){
            while(head!=nullptr){
                Node* next=head->getNext();
                delete head;
                head=next;
            }
            return *this;
        }


        Dog* getDog(Node* n) const{
            return n->getDog();
        }

        Node* getNextNode(Node* n) const{
            return n->getNext();
        }



        //filter functions

        Container filterBreeding() const{
                Container w;

                Node* n=head;
                while(n!=nullptr){
                    if(dynamic_cast<Breeding*>(n->getDog())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();

                }
                return w;
            }

        Container filterBoarding() const{
                Container w;

                Node* n=head;
                while(n!=nullptr){
                    if(dynamic_cast<Boarding*>(n->getDog())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();

                }
                return w;
            }


        Container searchDog(std::string name) const{
            Container w;

            Node* n=head;

            if(name=="" || name==" "){ //if search bar is empty show all
                while(n!=nullptr){
                    w.push_back(n->getDog());
                    n=n->getNext();
                }
            }
            else{
                while(n!=nullptr){
                    if(n->getDog()->getName()==name) w.push_back(n->getDog());
                 n=n->getNext();
                }
            }
            return w;

        }


        Container filterSize(Size* s) const{
            Container w;

            Node* n=head;

            if(dynamic_cast<Large*>(s)){
                while(n!=nullptr){
                    if(dynamic_cast<Large*>((static_cast<Boarding*>(n->getDog()))->getSize())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
                }
            }



            if(dynamic_cast<Medium*>(s)){
                while(n!=nullptr){
                     if(dynamic_cast<Medium*>((static_cast<Boarding*>(n->getDog()))->getSize())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();

                }
            }


            if(dynamic_cast<Small*>(s)){
                while(n!=nullptr){
                     if(dynamic_cast<Small*>((static_cast<Boarding*>(n->getDog()))->getSize())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();

                }
            }
            return w;

        }


        Container filterBath() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Boarding*>(n->getDog())->didBath())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }

        Container filterDiet() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Boarding*>(n->getDog())->didDiet())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }

        Container filterTraining() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Boarding*>(n->getDog())->didTraining())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }

        Container filterWalks() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Boarding*>(n->getDog())->didWalking())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }


        Container filterVax() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Breeding*>(n->getDog())->isVax())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }

        Container filterPurch() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Breeding*>(n->getDog())->isPurchasable())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }

        Container filterBooked() const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((static_cast<Breeding*>(n->getDog())->isBooked())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }


        Container filterBreed(Breed* b) const{
            Container w;

            Node* n=head;

            if(dynamic_cast<Bulldog*>(b)){
                while(n!=nullptr){
                    if(dynamic_cast<Bulldog*>((static_cast<Breeding*>(n->getDog()))->getBreed())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
                }
            }

            if(dynamic_cast<AmStaff*>(b)){
                while(n!=nullptr){
                    if(dynamic_cast<AmStaff*>((static_cast<Breeding*>(n->getDog()))->getBreed())){
                        w.push_back(n->getDog());
                    };
                    n=n->getNext();
                }
            }

            return w;
        }



        Container filterParent()const{
            Container w;

            Node* n=head;

            while(n!=nullptr){
                    if((!static_cast<Breeding*>(n->getDog())->isPurchasable())){
                        w.push_back(n->getDog());
                    }
                    n=n->getNext();
            }
            return w;
        }


};




#endif
