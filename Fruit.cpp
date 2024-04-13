#include "Fruit.h"

Fruit::Fruit(std::string name, std::string origin, std::string expiryDate, int quantity, int price)
    :_name(name),_origin(origin),_expiryDate(expiryDate),_quantity(quantity),_price(price)
{

}

std::string Fruit::get_name() {
    return _name;
}

std::string Fruit::get_origin() {
    return _origin;
}

int Fruit::get_price() {
    return _price;
}

void Fruit::set_price(int newPrice) {
    _price=newPrice;
}

int Fruit::get_quantity() {
    return _quantity;
}

void Fruit::set_quantity(int newQuantity) {
    _quantity=newQuantity;
}

std::string Fruit::get_expiryDate() {
    return _expiryDate;
}
