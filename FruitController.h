#ifndef L4_FRUITCONTROLLER_H
#define L4_FRUITCONTROLLER_H
#include "FruitRepo.h"

class FruitController {
private:
    FruitRepo repo;

public:
    void add(std::string name, std::string origin, std::string expiryDate, int quantity, int price);
    void remove(std::string name, std::string origin);
    std::vector<std::shared_ptr<Fruit>> find(std::string origin);
    std::vector<std::shared_ptr<Fruit>> listAll(std::string filterName);
    std::vector<std::shared_ptr<Fruit>> listShortQuantity(int specifiedQuantity);
    std::vector<std::shared_ptr<Fruit>> listExpiryDate();
    void listAllFruits();

};


#endif //L4_FRUITCONTROLLER_H
