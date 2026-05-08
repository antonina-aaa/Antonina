#include <iostream>
#include <vector>
#include "Order.h"
#include "Product.h"

using namespace std;

int main()
{
    vector<string> names = { "Milk", "Bread", "Cheese", "Apple", "Juice" };
    vector<double> prices = { 10.5, 3.4, 60.0, 8.5, 15.0 };

    string date;
    cout << "Enter date: ";
    cin >> date;

    Order order(date);

    int confirm;
    cout << "Birthday discount in Diya? (1-yes / 0-no): ";
    cin >> confirm;
    order.setBirthdayDiscount(confirm == 1);

    int payment;
    cout << "Payment (0-Cash, 1-Card): ";
    cin >> payment;
    order.setPayment(payment == 0 ? CASH : CARD);

    int status;
    cout << "Status (0-Pending, 1-Completed, 2-Cancelled): ";
    cin >> status;
    order.setStatus((Status)status);

    int choice;

    while (true)
    {
        cout << "\n=================================\n";
        cout << "           La Silpo MENU            \n";
        cout << "=================================\n";
        cout << "1. Add product\n";
        cout << "2. Show order\n";
        cout << "3. Change status\n";
        cout << "4. Change payment\n";
        cout << "5. Change date\n";
        cout << "6. Toggle birthday discount\n";
        cout << "7. Show total\n";
        cout << "8. Exit\n";
        cout << "=================================\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n--- PRODUCTS ---\n";

            for (int i = 0; i < names.size(); i++)
            {
                cout << i + 1 << ". " << names[i]
                    << " - $" << prices[i] << endl;
            }

            int id;
            cout << "Choose product: ";
            cin >> id;

            if (id < 1 || id > names.size())
            {
                cout << "Invalid product!\n";
                continue;
            }

            int qty;
            cout << "Quantity: ";
            cin >> qty;

            order.addProduct(Product(names[id - 1], prices[id - 1], qty));
            cout << " Product added!\n";
        }
        else if (choice == 2)
        {
            order.print();
        }
        else if (choice == 3)
        {
            int newStatus;
            cout << "\n--- STATUS ---\n";
            cout << "0 - Pending\n";
            cout << "1 - Completed\n";
            cout << "2 - Cancelled\n";
            cout << "Choose: ";
            cin >> newStatus;

            order.setStatus((Status)newStatus);
            cout << " Status updated!\n";
        }
        else if (choice == 4)
        {
            int newPayment;
            cout << "\n--- PAYMENT ---\n";
            cout << "0 - Cash\n";
            cout << "1 - Card\n";
            cout << "Choose: ";
            cin >> newPayment;

            order.setPayment(newPayment == 0 ? CASH : CARD);
            cout << " Payment updated!\n";
        }
        else if (choice == 5)
        {
            string newDate;
            cout << "Enter new date: ";
            cin >> newDate;

            order.setDate(newDate);
            cout << " Date updated!\n";
        }
        else if (choice == 6)
        {
            int discount;
            cout << "Birthday discount? (1-yes / 0-no): ";
            cin >> discount;

            order.setBirthdayDiscount(discount == 1);
            cout << " Discount updated!\n";
        }
        else if (choice == 7)
        {
            cout << " Total: $" << order.getTotal() << endl;
        }
        else if (choice == 8)
        {
            cout << " Exiting program...\n";
            break;
        }
        else
        {
            cout << "Wrong choice!\n";
        }
    }

    return 0;
}