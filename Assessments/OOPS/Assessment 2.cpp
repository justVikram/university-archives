/* OOPS Assessment 2 -- Customer goes to shop to buy grocery items. Grocery items could be of foods (which could then be packed or unpacked), detergents, and glass items. Customer can be gold, silver or a platinum member, and his reward points would be calculated accordingly. The item the customer buys will have a certain tax amount associated with it, which will be calculated separately for each item. */

#include <iostream>
#include <string>
#include <fstream>

#define tab '\t'

using namespace std;

ifstream fin ("input.txt");
ofstream fout("output.txt");

class DATE
{
public:
    
    int DD;
    int MM;
    int YY;
    
    //MARK:-
    
    DATE () {}
    
    DATE (int DD, int MM, int YY)
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

class ITEM
{
private:
    
    string ItemName;
    DATE DOM;
    DATE DOE;
    float price;
    float tax;
    
    //MARK:-
    
public:
    
    ITEM ()
    {
        ItemName = "UNDEFINED";
        DOE = DATE (00, 00, 00);
        DOM = DATE (00, 00, 00);
        price = 0.0;
    }
    
    ITEM (string ItemName, DATE DOE, DATE DOM, float price)
    {
        this->ItemName = ItemName;
        this->DOE = DOE;
        this->DOM = DOM;
    }
    
    string getName ()
    {
        return ItemName;
    }
    
    void showItemDetails ()
    {
        cout << "Item Name: " << ItemName << endl;
        cout << "DOM:" << endl;
        DOM.printDate();
        
        cout << "DOE:" << endl;
        DOE.printDate();
    }
    
    float getPrice ()
    {
        return price;
    }
    
    void setTax (int TaxAmount)
    {
        tax = TaxAmount;
    }
};

//MARK:-

class FOOD : public ITEM
{
public:
    
    FOOD () {}
    
    FOOD (string ItemName, DATE DOE, DATE DOM, float price) : ITEM (ItemName, DOE, DOM, price) {};
    
    void calcTax (float TaxPercent = 0.18)
    {
        if (! TaxPercent)
            setTax (TaxPercent * getPrice() + 2);
        
        else
            setTax (TaxPercent * getPrice());
    }
};

//MARK:-

class GLASSITEM : public ITEM
{
public:
    
    GLASSITEM () {}
    
    GLASSITEM (string ItemName, DATE DOE, DATE DOM, float price) : ITEM (ItemName, DOE, DOM, price) {}
    
    void calcTax ()
    {
        setTax (0.20 * getPrice());
    }
};

//MARK:-

class DETERGENT : public ITEM
{
public:
    
    DETERGENT () {}
    
    DETERGENT (string ItemName, DATE DOE, DATE DOM, float price) : ITEM ( ItemName, DOE, DOM, price) {};
    
    void calcTax ()
    {
        setTax(0.22 * getPrice());
    }
};

//MARK:-

class PACKEDFOODS : public FOOD
{
public:
    
    PACKEDFOODS (string ItemName, DATE DOE, DATE DOM, float price) : FOOD (ItemName,  DOE, DOM, price) {}
    
    void calcTax ()
    {
        FOOD :: calcTax (0.2);
    }
};

//MARK:-

class UNPACKEDFOODS : public FOOD
{
public:
    
    UNPACKEDFOODS (string ItemName, DATE DOE, DATE DOM, float price) : FOOD (ItemName,  DOE, DOM, price) {}
    
    void calcTax ()
    {
        FOOD :: calcTax (0);
    }
};

//MARK:-

class CUSTOMER
{
private:
    
    int CustomerId;
    string CustomerName;
    ITEM ItemsPurchased [4];
    int RewardPoints;
    float MoneySpentOnItems;
    
    //MARK:-
    
public:
    
    static int NumberOfItemsPurchased;
    static int NumberOfCustomers;
    
    CUSTOMER ()
    {
        CustomerId = 0;
        CustomerName = "UNDEFINED";
    }
    
    CUSTOMER (int CustomerID, string CustomerName)
    {
        this->CustomerId = CustomerID;
        this->CustomerName = CustomerName;
        
        for (int i = 0; i < 10; i++)
        this->ItemsPurchased [i] = ItemsPurchased [i];
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
        this->ItemsPurchased [i] = ItemsPurchased [i];
    }
    
    void buyItem (ITEM ItemPurchased)
    {
        this->ItemsPurchased [CUSTOMER :: NumberOfItemsPurchased++] = ItemPurchased;
        MoneySpentOnItems += ItemPurchased.getPrice();
    }
    
    
    int getTotalCost ()
    {
        int cost = 0;
        
        for (int i = 0; i < NumberOfItemsPurchased; i++)
        {
            cost += ItemsPurchased [i].getPrice();
        }
        
        return cost;
    }
    
    void showPurchasedItems ()
    {
        for (int i = 0; i < NumberOfItemsPurchased; i++)
        ItemsPurchased [i].showItemDetails();
    }
    
    void setRewardPointsEarned (float RewardPercentage)
    {
        RewardPoints = RewardPercentage * MoneySpentOnItems;
    }
};

//MARK:-

class GOLDMEMBER : public CUSTOMER
{
public:
    
    GOLDMEMBER (int CustomerID, string CustomerName) : CUSTOMER (CustomerID, CustomerName) {}
    
    void calcRewardPoints ()
    {
        setRewardPointsEarned (0.1);
    }
};

class SILVERMEMBER : public CUSTOMER
{
public:
    
    SILVERMEMBER (int CustomerID, string CustomerName) : CUSTOMER (CustomerID, CustomerName) {}
    
    void calcRewardPoints ()
    {
        setRewardPointsEarned (0.05);
    }
};

class PLATINUMMEMBER : public CUSTOMER
{
public:
    
    PLATINUMMEMBER (int CustomerID, string CustomerName) : CUSTOMER (CustomerID, CustomerName) {}
    
    void calcRewardPoints ()
    {
        setRewardPointsEarned (0.01);
    }
};

//MARK:-

int CUSTOMER :: NumberOfCustomers = 0;
int CUSTOMER :: NumberOfItemsPurchased = 0;

//MARK:-

class SHOP
{
private:
    
    int ShopID;
    string ShopName;
    ITEM ItemsAvailable [10];
    CUSTOMER ListOfCustomers [10];
    
    //MARK:-
    
public:
    
    static int NumberOfItems;
    static int NumberOfCustomersInShop;
    static int NumberOfItemsSold;
    
    SHOP (int ShopID, string ShopName, ITEM ItemsAvailable [10])
    {
        this->ShopID = ShopID;
        this->ShopName = ShopName;
        
        for (int i = 0; i < 4; i++)
        this->ItemsAvailable [i] = ItemsAvailable [i];
    }
    
    void addCustomer (CUSTOMER NewCustomer)
    {
        ListOfCustomers [SHOP :: NumberOfCustomersInShop++] = NewCustomer;
    }
    
    void showShop ()
    {
        cout << "Shop name: " << ShopName;
        cout << "Shop ID: " << ShopID;
        
        for (auto i : ItemsAvailable)
            i.showItemDetails ();
    }
    
    int calcTotalProfit ()
    {
        int profit = 0;
        
        for (int i = 0; i < NumberOfCustomersInShop; i++)
            profit += ListOfCustomers [i].getTotalCost();
        
        return profit;
    }
    
    
};
int SHOP :: NumberOfItems = 0;
int SHOP :: NumberOfCustomersInShop = 0;
int SHOP :: NumberOfItemsSold = 0;

//MARK:-

int main  (int argc, const char * argv[])
{
    
    DATE DOM (10, 11, 12);
    DATE DOE (11, 12, 13);
    
    ITEM ListOfItems [4];
    
    PACKEDFOODS PF ("RajmaChawal", DOE, DOM, 300);
    UNPACKEDFOODS UPF ("Veggies", DOE, DOM, 150);
    
    GLASSITEM GI ("Crockeries", DOE, DOM, 600);
    
    DETERGENT D ("Tide", DOE, DOM, 400);
    
    ListOfItems [0] = PF;
    ListOfItems [1] = UPF;
    ListOfItems [2] = GI;
    ListOfItems [3] = D;
    
    SHOP :: NumberOfItems = 4;
    
    //MARK:-
    
    SHOP GroceryStore (001, "JioMart", ListOfItems);
    
    //MARK:-
    
    CUSTOMER :: NumberOfCustomers = 3;
    
    CUSTOMER ListOfCustomers [3];
    
    GOLDMEMBER GM (1, "Person1");
    SILVERMEMBER SM (2, "Person2");
    PLATINUMMEMBER PM (3, "Person3");
    
    ListOfCustomers [0] = GM;
    ListOfCustomers [1] = SM;
    ListOfCustomers [2] = PM;
    
    
    //MARK:-
    
    bool KeepPurchasing = true;
    
    do
    {
        string CustomerType;
        cout << "What kind of customer are you?";
        cin >> CustomerType;
     
        int CustomerSelected;
        
        if (CustomerType == "G")
            CustomerSelected = 0;
        
        else if (CustomerType == "P")
            CustomerSelected = 1;
        
        else if (CustomerType == "S")
            CustomerSelected = 2;
        
        else
            CustomerSelected = -1;
        
        GroceryStore.addCustomer(ListOfCustomers [CustomerSelected]);
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                cout << "Select item." << endl;
                
                string ItemName;
                cout << "Enter item name ";
                cin >> ItemName;
                
                int flag = 0;
                
                for (int i = 0; i < SHOP :: NumberOfItems; i++)
                {
                    if (ListOfItems [i].getName() == ItemName)
                    {
                        SHOP :: NumberOfItemsSold++;
                        
                        if (CustomerType == "G")
                            ListOfCustomers [CustomerSelected]. buyItem(ListOfItems [i]);
                        
                        else if (CustomerType == "P")
                            ListOfCustomers [CustomerSelected]. buyItem(ListOfItems [i]);
                        
                        if (CustomerType == "S")
                            ListOfCustomers [CustomerSelected]. buyItem(ListOfItems [i]);
                        
                        flag = 1;
                    }
                }
                
                if (! flag)
                    cout << "Invalid name";
                
                break;
            }
                
            case 2:
            {
                cout << "Get item details.";
                
                for (int i = 0; i < SHOP :: NumberOfItems; i++)
                ListOfItems [i].showItemDetails ();
                
                break;
            }
                
            case 3:
            {
                cout << "The total number of items sold = " << SHOP :: NumberOfItemsSold << endl;
                
                break;
            }
                
            case 4:
            {
                cout << "Total amount collected by the shop = " << GroceryStore.calcTotalProfit() << endl;
            }
                
        }
        
        cout << "Keep purchasing?" << endl;
        cin >> KeepPurchasing;
    }
    while (KeepPurchasing);
    
    cout << " -- processing transaction... thank you." << endl << endl;
}
