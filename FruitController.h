#ifndef L4_FRUITCONTROLLER_H
#define L4_FRUITCONTROLLER_H
#include "FruitRepo.h"

class FruitController {
private:
    FruitRepo repo;

public:
    void add(std::string name, std::string origin, std::string expiryDate, int quantity, int price);
    void remove(std::string name, std::string origin);
    void find(std::string origin);
    void listAll(std::string filterName);
    void listShortQuantity(int specifiedQuantity);
    void listExpiryDate();
    void listAllFruits();

};


#endif //L4_FRUITCONTROLLER_H
