#include "FruitUI.h"
#include "iostream"

void FruitUI::menu() {
    std::cout<<"Fruit Store"<<'\n';
    std::cout<<"Choose what you want to do:"<<'\n';
    std::cout<<"1. Add Fruit"<<'\n';
    std::cout<<"2. Remove Fruit"<<'\n';
    std::cout<<"3. Find Fruit by Origin"<<'\n';
    std::cout<<"4. List all Fruits that contain a certain word"<<'\n';
    std::cout<<"5. List all Fruits that have a short Quantity"<<'\n';
    std::cout<<"6. List all Fruits sorted by Expiry Date"<<'\n';
    std::cout<<"7. List all Fruit"<<'\n';
    std::cout<<"0. Exit"<<'\n';
}

void FruitUI::addFruit() {
    std::string name, origin, expiryDate;
    int quantity,price;
    std::cout<<"Enter name: ";
    std::cin>>name;
    std::cout<<"Enter origin: ";
    std::cin>>origin;
    std::cout<<"Enter expiry Date: ";
    std::cin>>expiryDate;
    std::cout<<"Enter quantity: ";
    std::cin>>quantity;
    std::cout<<"Enter price: ";
    std::cin>>price;
    ctrl.add(name,origin,expiryDate,quantity,price);
    std::cout<<"Fruit added!";
}

void FruitUI::removeFruit() {
    std::string name, origin;
    std::cout<<"Enter name: ";
    std::cin>>name;
    std::cout<<"Enter origin: ";
    std::cin>>origin;
    ctrl.remove(name,origin);
    std::cout<<"Fruit removed!";
}

void FruitUI::findFruit() {
    std::string origin;
    std::cout<<"Enter origin: ";
    std::cin>>origin;
    ctrl.find(origin);
}

void FruitUI::listFruitAll() {
    std::string filterString;
    std::cout<<"Enter a word, to list the fruits that contain it either in its name or in its origin: ";
    std::cin>>filterString;
    ctrl.listAll(filterString);
}

void FruitUI::listFruitShortQuantity() {
    int quantity;
    std::cout<<"Enter a number, to list the fruits that have a shorter quantity as it";
    std::cin>>quantity;
    ctrl.listShortQuantity(quantity);
}

void FruitUI::listFruitExpiryDate() {
    ctrl.listExpiryDate();
}

void FruitUI::listAllFruits() {
    ctrl.listAllFruits();
}

void FruitUI::run() {
    int option;
    do{
        menu();
        std::cin>>option;
        switch (option) {
            case 1:
                addFruit();
                break;
            case 2:
                removeFruit();
                break;
            case 3:
                findFruit();
                break;
            case 4:
                listFruitAll();
                break;
            case 5:
                listFruitShortQuantity();
                break;
            case 6:
                listFruitExpiryDate();
                break;
            case 7:
                listAllFruits();
                break;
            case 0:
                std::cout<<"Thank you for using Fruit Store!";
                break;
            default:
                std::cout<<"Invalid option, pick again!";
                break;
        }
    } while (option!=0);

}
