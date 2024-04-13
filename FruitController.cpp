#include "FruitController.h"
#include "iostream"

void FruitController::add(std::string name, std::string origin, std::string expiryDate, int quantity, int price) {
    repo.add(std::make_shared<Fruit>(name,origin,expiryDate,quantity,price));
}

void FruitController::remove(std::string name, std::string origin) {
    std::shared_ptr<Fruit> fruitRemove=std::make_shared<Fruit>(name,origin,"",0,0);
    repo.remove(fruitRemove);
}

void FruitController::find(std::string origin) {
    repo.printChangedFruits(repo.findByOrigin(origin));
}

void FruitController::listAll(std::string filterName) {
    repo.printChangedFruits(repo.getAll(filterName));
}

void FruitController::listShortQuantity(int specifiedQuantity) {
    repo.printChangedFruits(repo.getShortQuantity(specifiedQuantity));
}

void FruitController::listExpiryDate() {
    repo.printChangedFruits(repo.sortExpiryDate());
}

void FruitController::listAllFruits() {
    repo.printFruits();
}
