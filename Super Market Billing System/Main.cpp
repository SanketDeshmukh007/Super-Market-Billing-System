#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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

// Function to clear the contents of the file
void clearFile()
{
    ofstream out("Bill.txt", ios::trunc);
    if (!out)
    {
        cout << "Error: File Can't Open!" << endl;
    }
    // else
    // {
    //     cout << "File Cleared Successfully!" << endl;
    // }
    out.close();
}

void addItem(Bill b)
{
    bool close = false;
    while (close == false)
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

            ofstream out("D:/DSA/Super Market Billing System/Bill.txt", ios::app); // To Write
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
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

void printBill()
{
    system("cls");
    ifstream in("Bill.txt"); // To read
    string line;

    cout << "Printing Bill..." << endl;

    int Total = 0;
    int idx = 0;

    cout << "---------------------------------------------" << endl;
    cout << "   Item\t\tRate\tQuantity" << endl;
    cout << "---------------------------------------------" << endl;

    while (getline(in, line))
    {
        stringstream ss(line); // To Read
        string itemName;
        int itemRate, itemQuant;
        char delimiter;
        ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;
        cout << ++idx << ") " << itemName << "\t\t" << itemRate << "\t" << itemQuant << endl;
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
    bool exit = false;
    clearFile();
    while (exit == false)
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
            // Sleep(3000);
        }

        else if (choice == 2)
        {
            printBill();
            Sleep(3000);
        }

        else if (choice == 3)
        {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
    }
}