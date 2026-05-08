#include "Order.h"

string statusToString(Status s)
{
    switch (s)
    {
    case PENDING:
        return "Pending";
    case COMPLETED:
        return "Completed";
    case CANCELLED:
        return "Cancelled";
    }

    return "";
}

string paymentToString(PaymentMethod p)
{
    switch (p)
    {
    case CASH:
        return "Cash";
    case CARD:
        return "Card";
    }

    return "";
}

Order::Order(string d)
{
    date = d;
    status = PENDING;
    payment = CASH;
    birthdayDiscount = false;
}

void Order::addProduct(Product p)
{
    for (auto& item : products)
    {
        if (item.getName() == p.getName())
        {
            item.addQuantity(p.getQuantity());
            return;
        }
    }

    products.push_back(p);
}

void Order::setStatus(Status s)
{
    status = s;
}

void Order::setPayment(PaymentMethod p)
{
    payment = p;
}

void Order::setDate(string d)
{
    date = d;
}

void Order::setBirthdayDiscount(bool value)
{
    birthdayDiscount = value;
}

double Order::getTotal()
{
    double total = 0;

    for (auto& p : products)
    {
        total += p.getSum();
    }

    if (birthdayDiscount)
    {
        total *= 0.85;
    }

    return total;
}

void Order::print()
{
    cout << "\n================ ORDER CHECK ================\n";
    cout << "Date: " << date << endl;
    cout << "Status: " << statusToString(status) << endl;
    cout << "Payment: " << paymentToString(payment) << endl;

    cout << "\n--- PRODUCTS ---\n";

    double subtotal = 0;

    for (auto& p : products)
    {
        double sum = p.getSum();

        cout << p.getName()
            << " x" << p.getQuantity()
            << " = $" << sum << endl;

        subtotal += sum;
    }

    cout << "--------------------------------------------\n";

    if (birthdayDiscount)
    {
        double discount = subtotal * 0.15;
        double finalTotal = subtotal * 0.85;

        cout << "Subtotal: $" << subtotal << endl;
        cout << "Birthday discount (-15%): -$" << discount << endl;
        cout << "TOTAL: $" << finalTotal << endl;
    }
    else
    {
        cout << "TOTAL: $" << subtotal << endl;
    }

    cout << "\n";
}