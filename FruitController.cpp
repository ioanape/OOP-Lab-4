#include "FruitController.h"

void FruitController::add(std::string name, std::string origin, std::string expiryDate, int quantity, int price) {
    repo.add(std::make_shared<Fruit>(name,origin,expiryDate,quantity,price));
}

void FruitController::remove(std::string name, std::string origin) {
    std::shared_ptr<Fruit> fruitRemove=std::make_shared<Fruit>(name,origin,"",0,0);
    repo.remove(fruitRemove);
}

std::vector<std::shared_ptr<Fruit>> FruitController::find(std::string origin) {
    return repo.findByOrigin(origin);
}

std::vector<std::shared_ptr<Fruit>> FruitController::listAll(std::string filterName) {
    return repo.getAll(filterName);
}

std::vector<std::shared_ptr<Fruit>> FruitController::listShortQuantity(int specifiedQuantity) {
    return repo.getShortQuantity(specifiedQuantity);
}

std::vector<std::shared_ptr<Fruit>> FruitController::listExpiryDate() {
    return repo.sortExpiryDate();
}

void FruitController::listAllFruits() {
    repo.printFruits();
}
