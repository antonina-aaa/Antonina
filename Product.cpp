#include "Product.h"


Product::Product()
{
    name = "";
    price = 0;
    quantity = 0;
}

Product::Product(string n, double p, int q)
{
    name = n;
    price = p;
    quantity = q;
}

string Product::getName()
{
    return name;
}

double Product::getPrice()
{
    return price;
}

int Product::getQuantity()
{
    return quantity;
}

double Product::getSum()
{
    return price * quantity;
}

void Product::addQuantity(int q)
{
    quantity += q;
}