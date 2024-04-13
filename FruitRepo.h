#ifndef L4_FRUITREPO_H
#define L4_FRUITREPO_H
#include "vector"
#include "memory"
#include "Fruit.h"

class FruitRepo {
private:
    std::vector<std::shared_ptr<Fruit>> _fruits;

public:
    FruitRepo();
    void add(std::shared_ptr<Fruit> fruit);
    void remove(std::shared_ptr<Fruit> fruit);
    std::vector<std::shared_ptr<Fruit>> getAll(std::string filterName);
    std::vector<std::shared_ptr<Fruit>> getShortQuantity(int specifiedQuantity);
    std::vector<std::shared_ptr<Fruit>> sortExpiryDate();
    std::vector<std::shared_ptr<Fruit>> findByOrigin(std::string origin);
    void printFruits();
    void printChangedFruits(std::vector<std::shared_ptr<Fruit>> changed);

};


#endif //L4_FRUITREPO_H
