#ifndef L4_FRUITUI_H
#define L4_FRUITUI_H
#include "FruitController.h"

class FruitUI {
public:
    void menu();
    void addFruit();
    void removeFruit();
    void findFruit();
    void listFruitAll();
    void listFruitShortQuantity();
    void listFruitExpiryDate();
    void listAllFruits();
    void run();
private:
    FruitController ctrl;
};


#endif //L4_FRUITUI_H
