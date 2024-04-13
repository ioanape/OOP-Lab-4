#include <algorithm>
#include "FruitRepo.h"
#include "iostream"

FruitRepo::FruitRepo() {
    _fruits.push_back(std::make_shared<Fruit>("Apple", "Bulgaria", "2025.12",20,4));
    _fruits.push_back(std::make_shared<Fruit>("Banana", "Romania", "2026.02",15,2));
    _fruits.push_back(std::make_shared<Fruit>("Kiwi", "South Korea", "2024.07",4,3));
    _fruits.push_back(std::make_shared<Fruit>("Mango", "Germany", "2025.11",13,2));
    _fruits.push_back(std::make_shared<Fruit>("Pineapple", "Iran", "2025.04",40,1));
    _fruits.push_back(std::make_shared<Fruit>("Lemon", "Mexico", "2026.12",14,4));
    _fruits.push_back(std::make_shared<Fruit>("Avocado", "Brazil", "2024.10",24,3));
    _fruits.push_back(std::make_shared<Fruit>("Strawberry", "Somalia", "2025.07",20,3));
    _fruits.push_back(std::make_shared<Fruit>("Blackberry", "Romania", "2024.12",18,1));
    _fruits.push_back(std::make_shared<Fruit>("Cherry", "USA", "2024.01",21,2));
}

void FruitRepo::add(std::shared_ptr<Fruit> fruit) {
    bool existingFruit= false;
    for(int i=0;i<_fruits.size();i++)
        if(fruit->get_name()==_fruits[i]->get_name() && fruit->get_origin()==_fruits[i]->get_origin())
        {
            _fruits[i]->set_quantity(_fruits[i]->get_quantity()+1);
            existingFruit=true;
            break;
        }
    if(!existingFruit)
        _fruits.push_back(fruit);
}

void FruitRepo::remove(std::shared_ptr<Fruit> fruit) {
    for(int i=0;i<_fruits.size();i++)
        if(fruit->get_name()==_fruits[i]->get_name() && fruit->get_origin()==_fruits[i]->get_origin())
        {
            if(_fruits[i]->get_quantity()>=2)
            {
            _fruits[i]->set_quantity(_fruits[i]->get_quantity()-1);
            break;
            }
            else
            {
                _fruits.erase(_fruits.begin()+i);
                break;
            }
        }
}

std::vector<std::shared_ptr<Fruit>> FruitRepo::getShortQuantity(int specifiedQuantity) {
    std::vector<std::shared_ptr<Fruit>> fruitsShortQuantity;
    for(int i=0;i<_fruits.size();i++)
        if(_fruits[i]->get_quantity()<specifiedQuantity)
            fruitsShortQuantity.push_back(_fruits[i]);
    return fruitsShortQuantity;
}

std::vector<std::shared_ptr<Fruit>> FruitRepo::getAll(std::string filterName) {
    std::vector<std::shared_ptr<Fruit>> fruitsFiltered;
    if(filterName.empty()){
        std::sort(_fruits.begin(),_fruits.end(),[](std::shared_ptr<Fruit> x, std::shared_ptr<Fruit> y){return x->get_name()<y->get_name();});
        return _fruits;}
    for(int i=0;i<_fruits.size();i++)
        if(_fruits[i]->get_name().find(filterName)!=std::string::npos || _fruits[i]->get_origin().find(filterName)!=std::string::npos)
            fruitsFiltered.push_back(_fruits[i]);
    std::sort(fruitsFiltered.begin(),fruitsFiltered.end(),[](std::shared_ptr<Fruit> x, std::shared_ptr<Fruit> y){return x->get_name()<y->get_name();});
    return fruitsFiltered;
}

std::vector<std::shared_ptr<Fruit>> FruitRepo::sortExpiryDate() {
    std::sort(_fruits.begin(),_fruits.end(),[](std::shared_ptr<Fruit> x, std::shared_ptr<Fruit> y){return x->get_expiryDate()<y->get_expiryDate();});
    return _fruits;
}

std::vector<std::shared_ptr<Fruit>> FruitRepo::findByOrigin(std::string origin) {
    std::vector<std::shared_ptr<Fruit>> fruitsFound;
    for(int i=0;i<_fruits.size();i++)
        if(_fruits[i]->get_origin()==origin)
            fruitsFound.push_back(_fruits[i]);
    return fruitsFound;
}

void FruitRepo::printFruits() {
    for(int i=0;i<_fruits.size();i++)
        std::cout<<"Name: "<<_fruits[i]->get_name()<<", Origin: " << _fruits[i]->get_origin()<< ", Expiry Date: " << _fruits[i]->get_expiryDate()<< ", Quantity: " << _fruits[i]->get_quantity() << ", Price: " << _fruits[i]->get_price() <<'\n';
}


