#include "JsonRepo.h"


JsonRepo::JsonRepo(JsonFile dataMapper)
    : dataMapper(dataMapper)
{
    std::vector<Owner*> owners(dataMapper.loadOwners());
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



const std::string& JsonRepo::getPath() const{
    return dataMapper.getPath();
}


JsonRepo& JsonRepo::setPath(const std::string path){
    dataMapper.setPath(path);
    return *this;
}



JsonRepo& JsonRepo::create(Owner *owns){
    owners.push_back(owns);
    return *this;
}


Owner* JsonRepo::read(std::string number) const{
    for(auto it= owners.begin();
        it!=owners.end();
        it++
    ){
        if((*it)->getPhone()==number) return *it;
    }

    return nullptr;
}


JsonRepo& JsonRepo::update(Owner *owner){
    return create(owner);
}



JsonRepo& JsonRepo::remove(std::string number){

    for(std::vector<Owner*>::const_iterator it = owners.begin();
        it!=owners.end();
        it++)
    {
        if((*it)->getPhone()==number) delete *it;
    }


    return *this;
}



std::vector<Owner*> JsonRepo::readAll() const {
    std::vector<Owner*> owns;
    for (
        std::vector<Owner*>::const_iterator it = owners.begin();
        it != owners.end();
        it++
    ) {
        owns.push_back(*it);
    }
    return owns;
}


JsonRepo& JsonRepo::store(){
    dataMapper.storeOwners(readAll());
    return *this;
}
