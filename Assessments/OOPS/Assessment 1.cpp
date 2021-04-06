//OOPS Assessment 1 -- Customer goes to a shop to buy medicines, such that total weight of medicines shouldn't exceed 300 mg.

#include <iostream>
#include <string>

#define tab '\t'

using namespace std;

class DATE
{
public:
    
    int DD;
    int MM;
    int YY;
    
    //MARK:-
    
    DATE ()
    {
        DD = MM = YY = 00;
    }
    
    void readDate (int DD, int MM, int YY)
    {
        this->DD = DD;
        this->MM = MM;
        this->YY = YY;
    }
    
    void printDate ()
    {
        cout << DD << "-" << MM << "-" << YY << endl;
    }
};

//MARK:-

class MEDICINE
{
private:
    
    int ItemID;
    string ItemName;
    DATE DOM;
    DATE DOE;
    float price;
    float wt;
    
    //MARK:-
    
public:
    
    MEDICINE ()
    {
        ItemID = 0;
        ItemName = "UNDEFINED";
        DOM.readDate (00, 00, 00);
        DOE.readDate (00, 00, 00);
        price = 0.0;
        wt = 0.0;
    }
    
    void getMedicineDetails (int ItemID, string ItemName, DATE DOE, DATE DOM, float price, float wt)
    {
        this->ItemID = ItemID;
        this->ItemName = ItemName;
        this->DOE = DOE;
        this->DOM = DOM;
        this->wt = wt;
    }
    
    int getID ()
    {
        return ItemID;
    }
    
    int getPrice ()
    {
        return price;
    }
    
    void showMedicineDetails ()
    {
        cout << "Medicine's Item ID: " << ItemID << endl;
        cout << "Medicine Name: " << ItemName << endl;
        cout << "DOM:" << endl;
        DOM.printDate();
        
        cout << "DOE:" << endl;
        DOE.printDate();
        
        cout << "Weight of medicine: " << wt << endl;
    }
};

//MARK:-

class CUSTOMER
{
private:
    
    int CustomerId;
    string CustomerName;
    MEDICINE MedicinesPurchased [10];
    
    //MARK:-
    
public:
    
    static int NumberOfMedicinesPurchased;
    static int NumberOfCustomers;
    
    CUSTOMER ()
    {
        CustomerId = 0;
        CustomerName = "UNDEFINED";
    }
    
    void getNumberOfCustomers ()
    {
        cin >> NumberOfCustomers;
    }
    
    void getCustomerDetails (int CustomerID, string CustomerName)
    {
        this->CustomerId = CustomerID;
        this->CustomerName = CustomerName;
        
        for (int i = 0; i < 10; i++)
            this->MedicinesPurchased [i] = MedicinesPurchased [i];
    }
    
    void buyMedicine (MEDICINE MedicinePurchased)
    {
        this->MedicinesPurchased [CUSTOMER :: NumberOfMedicinesPurchased++] = MedicinePurchased;
    }
    
    
    int getCost ()
    {
        int cost = 0;
        
        for (auto i : MedicinesPurchased)
            cost += i.getPrice();
          
        return cost;
    }
};

int CUSTOMER :: NumberOfCustomers = 0;
int CUSTOMER :: NumberOfMedicinesPurchased = 0;

//MARK:-

class SHOP
{
private:
    
    int ShopID;
    string ShopName;
    MEDICINE MedicinesAvailable [10];
    CUSTOMER ListOfCustomers [10];
    
    //MARK:-
    
public:
    
    static int NumberOfMedicines;
    static int NumberOfCustomersInShop;
    
    void setupShop (int ShopID, string ShopName, MEDICINE MedicinesAvailable [10])
    {
        this->ShopID = ShopID;
        this->ShopName = ShopName;
        
        for (int i = 0; i < 10; i++)
            this->MedicinesAvailable [i] = MedicinesAvailable [i];
    }
    
    void addCustomer (CUSTOMER NewCustomer)
    {
        ListOfCustomers [SHOP :: NumberOfCustomersInShop++] = NewCustomer;
    }
    
    void showShop ()
    {
        cout << "Shop name: " << ShopName;
        cout << "Shop ID: " << ShopID;
        
        for (auto i : MedicinesAvailable)
            i.showMedicineDetails ();
    }
};
int SHOP :: NumberOfMedicines = 0;
int SHOP :: NumberOfCustomersInShop = 0;

//MARK:-

int main  (int argc, const char * argv[])
{
    CUSTOMER CustomerList [10];
    SHOP MedicalStore;
    MEDICINE ListOfMedicines [10];
    
    cout << "Enter number of meds available at the shop:";
    cin >> SHOP :: NumberOfMedicines;
    
    for (int i = 0; i < SHOP :: NumberOfMedicines; i++)
    {
        int ItemID;
        string ItemName;
        DATE DOM;
        DATE DOE;
        float price;
        float wt;
        
        cout << "Enter Item ID for medicine " << i+1 << ":";
        cin >> ItemID;
        
        cout << "Enter Item Name for medicine " << i+1 << ":";
        cin >> ItemName;
        
        
        int DD;
        int MM;
        int YY;
        
        cout << "Enter DOM for medicine " << i+1 << ":";
        cin >> DD >> MM >> YY;
        DOM.readDate(DD, MM, YY);
        
        cout << "Enter DOE for medicine " << i+1 << ":" << endl;
        cin >> DD >> MM >> YY;
        DOE.readDate(DD, MM, YY);
        
        cout << "Enter cost of medicine " << i+1 << ":" << endl;
        cin >> price;
        
        cout << "Enter weight of medicine " << i+1 << " in mg:";
        cin >> wt;
        
        ListOfMedicines [i].getMedicineDetails(ItemID, ItemName, DOE, DOM, price, wt);
    }
    
    //MARK:-
    
    int ShopID;
    string ShopName;
    
    cout << "Enter shop ID: ";
    cin >> ShopID;
    
    cout << "Enter shop name: ";
    cin >> ShopName;
    
    MedicalStore.setupShop (ShopID, ShopName, ListOfMedicines);

    //MARK:-
    
    cout << "Enter number of customers: ";
    cin >> CUSTOMER :: NumberOfCustomers;
    
    for (int i = 0; i < CUSTOMER :: NumberOfCustomers; i++)
    {
    
        int CustomerId;
        string CustomerName;
        MEDICINE MedicinesPurchased [10];
        
        cout << "Enter customer " << i << "'s ID";
        cin >> CustomerId;
        
        cout << "Enter customer " << i << "'s name";
        cin >> CustomerName;
        
        CustomerList [i].getCustomerDetails (CustomerId, CustomerName);
    
    }
    
    //MARK:-
    
    int CustomerRank;
    cout << "Select customer rank: ";
    cin >> CustomerRank;
    
    bool MinWtOfMedsSelected = true;
    
    do
    {
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                cout << "Select medicine." << endl;
                
                int MedicineID;
                cout << "Enter medicine ID: ";
                cin >> MedicineID;
                
                int flag = 0;
                
                for (int i = 0; i < SHOP :: NumberOfMedicines; i++)
                {
                    if (ListOfMedicines [i].getID() == MedicineID)
                    {
                        CustomerList [CustomerRank].buyMedicine(ListOfMedicines [i]);
                        flag = 1;
                    }
                }
                
                if (! flag)
                    cout << "Invalid ID";
                
                break;
            }
                
            case 2:
            {
                cout << "Get medicine details.";
                
                for (int i = 0; i < SHOP :: NumberOfMedicines; i++)
                ListOfMedicines [i].showMedicineDetails ();
            }
        }
        
        MinWtOfMedsSelected = CustomerList[CustomerRank].getCost() >= 300;
        MedicalStore.addCustomer(CustomerList [CustomerRank]);
    }
    while (! MinWtOfMedsSelected);
    
    cout << "You have selected more than 300 mg of medicines -- processing transaction... thank you." << endl;
}
