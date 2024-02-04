#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill()
    {
        Item = "";
        Rate = 0;
        Quantity = 0;
    }

    void setItem(string item)
    {
        Item = item;
    }

    void setRate(int rate)
    {
        Rate = rate;
    }

    void setQuantity(int quantity)
    {
        Quantity = quantity;
    }

    string getItem()
    {
        return Item;
    }

    int getRate()
    {
        return Rate;
    }

    int getQuantity()
    {
        return Quantity;
    }
};

void clearFile()
{
    ofstream out("Bill.txt", ios::trunc);
    out.close();
}

void addItem(Bill b)
{
    while (true)
    {
        int choice;
        cout << "\t1.Add." << endl;
        cout << "\t2.close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin.ignore();
            getline(cin, item);
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;
            b.setQuantity(quant);

            ofstream out("Bill.txt", ios::app);
            if (!out)
            {
                cout << "\tError: File Can't Open!" << endl;
            }
            else
            {
                out << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl;
            }
            out.close();
            cout << "\tItem Added Successfuly" << endl;
            Sleep(3000);
        }

        else if (choice == 2)
        {
            system("cls");
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
            break;
        }
    }
}

void printBill()
{
    system("cls");
    ifstream in("Bill.txt");
    string line;

    cout << "Printing Bill..." << endl;

    int Total = 0;
    int idx = 0;

    cout << "---------------------------------------------" << endl;
    cout << "   Item\t\tRate\tQuantity" << endl;
    cout << "---------------------------------------------" << endl;

    while (getline(in, line))
    {
        stringstream ss(line);
        string itemName1, itemName2;
        int itemRate, itemQuant;
        char delimiter;
        ss >> itemName1 >> itemName2 >> delimiter >> itemRate >> delimiter >> itemQuant;
        cout << ++idx << ") " << (itemName1 + " " + itemName2) << "\t\t" << itemRate << "\t" << itemQuant << endl;
        Total += (itemRate * itemQuant);
    }

    cout << "---------------------------------------------" << endl;
    cout << "Total Bill: Rs. " << Total << "/-" << endl;

    in.close();
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000);
}

int main()
{
    Bill b;
    clearFile();
    while (true)
    {
        system("cls");

        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t\t1.Add Item." << endl;
        cout << "\t\t2.Print Bill." << endl;
        cout << "\t\t3.Exit." << endl;
        cout << "\t\tEnter Choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            addItem(b);
        }

        else if (choice == 2)
        {
            printBill();
            Sleep(5000);
        }

        else if (choice == 3)
        {
            system("cls");
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
            break;
        }
    }
}