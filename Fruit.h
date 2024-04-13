#ifndef L4_FRUIT_H
#define L4_FRUIT_H
#include "string"

class Fruit {
public:
    Fruit(std::string name, std::string origin, std::string expiryDate, int quantity, int price);
    std::string get_name();
    std::string get_origin();
    int get_quantity();
    int get_price();
    void set_price(int newPrice);
    void set_quantity(int newQuantity);
    std::string get_expiryDate();
private:
    std::string _name;
    std::string _origin;
    std::string _expiryDate;
    int _price;
    int _quantity;
};


#endif //L4_FRUIT_H
