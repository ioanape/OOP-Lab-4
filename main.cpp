#include <iostream>
#include "FruitUI.h"
#include "cassert"

void tests()
{
    FruitRepo repo;
    std::shared_ptr<Fruit> apple = std::make_shared<Fruit>("Apple", "Bulgaria", "2024.05", 10, 1);
    repo.add(apple);
    assert(repo.getAll("").size() == 10);

    repo.remove(apple);
    assert(repo.getAll("").size() == 10);

    repo.add(std::make_shared<Fruit>("Banana", "Brazil", "2024.05", 15, 2));
    assert(repo.getAll("").size() == 11);
    assert(repo.getAll("Braz").size() == 2);
    assert(repo.getAll("a").size() == 8);

    assert(repo.getShortQuantity(10).size() == 1);

    repo.add(std::make_shared<Fruit>("Orange", "Spain", "2021.05", 18, 1));
    auto sortedFruits = repo.sortExpiryDate();
    assert(sortedFruits.size() == 12);
    assert(sortedFruits[0]->get_name() == "Orange");
    assert(sortedFruits[1]->get_name() == "Cherry");

    assert(repo.findByOrigin("Brazil").size() == 2);
}

int main() {
    tests();
    FruitUI ui;
    ui.run();
    return 0;
}
