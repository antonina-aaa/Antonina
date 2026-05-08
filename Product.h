#pragma once
#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string name;
    double price;
    int quantity;

public:
    Product();
    Product(string n, double p, int q);

    string getName();
    double getPrice();
    int getQuantity();
    double getSum();

    void addQuantity(int q);
};