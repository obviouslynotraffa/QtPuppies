#include "JsonRepo.h"

JsonRepo::JsonRepo(JsonFile dataMapper)
    : dataMapper(dataMapper)
{
    std::vector<Owner*> ownersVector(dataMapper.loadOwners());
    std::vector<Dog*> dogsVector(dataMapper.loadDogs());


    for(auto it = ownersVector.begin();
        it!=ownersVector.end();
        it++)
    {
        owners.push_back(*it);
    }


    for(auto it = dogsVector.begin();
        it!=dogsVector.end();
        it++)
    {
        dogs.push_back(*it);
    }

}


JsonRepo::~JsonRepo(){

    owners.clear();


    for(auto it = dogs.begin();
        it!=dogs.end();
        it++)
    {
        delete *it;
    }

}

JsonRepo JsonRepo::fromPath(const std::string path){
    Reader reader;
    Json converter(reader);
    JsonFile dataMapper(path, converter);
    JsonRepo repository(dataMapper);

    return repository;
}


const JsonFile& JsonRepo::getDataMapper() const{
    return dataMapper;
}




const std::vector<Owner*>& JsonRepo::getRepoOwner() const{
    return owners;
}

const std::vector<Dog*>& JsonRepo::getRepoDog() const{
    return dogs;
}

/*
const std::string& JsonRepo::getPath() const{
    return dataMapper.getPath();
}*/

JsonRepo& JsonRepo::setPath(const std::string path){
    dataMapper.setPath(path);
    return *this;
}



JsonRepo& JsonRepo::create(Owner *owns){
    owners.push_back(owns);
    return *this;
}


Owner* JsonRepo::readOwner(std::string number) const{
    for(auto it= owners.begin(); it!=owners.end(); it++){
        if((*it)->getPhone()==number) return *it;
    }

    return nullptr;
}



JsonRepo& JsonRepo::removeOwner(std::string number){

    for(std::vector<Owner*>::const_iterator it = owners.begin(); it!=owners.end(); it++)
    {
        if((*it)->getPhone()==number) delete *it;
        return *this;
    }

    return *this;
}



std::vector<Owner*> JsonRepo::readAllOwners() const {
    std::vector<Owner*> ownsVector;
    for (std::vector<Owner*>::const_iterator it = owners.begin(); it != owners.end(); it++){

        ownsVector.push_back(*it);
    }
    return ownsVector;
}




JsonRepo& JsonRepo::create(Dog *dog){
    dogs.push_back(dog);
    return *this;
}


Dog* JsonRepo::readDog(std::string name) const{

    for(auto it = dogs.begin();
        it!=dogs.end();
        it++)
    {
    if((*it)->getName()==name) return *it;
    }
    return nullptr;

}



JsonRepo& JsonRepo::removeDog(Dog *dog){

    for(auto it = dogs.begin();
        it!=dogs.end();
        it++)
    {
    if((*it)==dog) dogs.erase(it);
    }

    return *this;
}



std::vector<Dog*> JsonRepo::readAllDogs() const{

    std::vector<Dog*> dogsVector;
    for (
        std::vector<Dog*>::const_iterator it = dogs.begin();
        it != dogs.end();
        it++
    ) {
        dogsVector.push_back(*it);
    }
    return dogsVector;
}



JsonRepo& JsonRepo::store(){

    dataMapper.store(readAllDogs(),readAllOwners());
    return *this;
}


