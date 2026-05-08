#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

using namespace std;

enum Status
{
    PENDING,
    COMPLETED,
    CANCELLED
};

enum PaymentMethod
{
    CASH,
    CARD
};

string statusToString(Status s);
string paymentToString(PaymentMethod p);

class Order
{
private:
    vector<Product> products;
    string date;
    Status status;
    PaymentMethod payment;
    bool birthdayDiscount;

public:
    Order(string d = "01-01-2026");

    void addProduct(Product p);
    void setStatus(Status s);
    void setPayment(PaymentMethod p);
    void setDate(string d);
    void setBirthdayDiscount(bool value);

    double getTotal();
    void print();
};
