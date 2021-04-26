//  Hackerrank Assessment 1
//  Created by Aditya Vikram on 4/26/21.
//  USN : 01fe19bcs220

#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#if 0

class Person
{
private:
    
    string name;
    int age;
    
public:
    
    Person () {}
    
    static int cur_id_professors;
    static int cur_id_students;
    
    void setName ()
    {
        cin >> name;
    }
    
    void setAge ()
    {
        cin >> age;
    }
    
    string getName ()
    {
        return name;
    }
    
    int getAge ()
    {
        return age;
    }
    
    virtual void getdata () {}
    
    virtual void putdata () {}
};
int Person :: cur_id_students = 0;
int Person :: cur_id_professors = 0;

class Student : public Person
{
private:
    
    vector <int> marks;
    int cur_id;
    
public:
    
    Student ()
    {
        marks.resize(6);
        cur_id = ++ Person :: cur_id_students;
    }
    
    void getdata () override
    {
        setName ();
        setAge ();
        
        for (auto &i : marks)
            cin >> i;
    }
    
    void putdata () override
    {
        int sum_of_marks = 0;
        
        for (auto i : marks)
            sum_of_marks += i;
        
        cout << getName() << "\t" << getAge() << "\t" << sum_of_marks << "\t" << cur_id << endl;
    }
};

class Professor : public Person
{
private:
    
    int publications;
    int cur_id;
    
public:
    
    Professor ()
    {
        cur_id = ++ Person :: cur_id_professors;
    }
    
    
    void getdata () override
    {
        setName ();
        setAge ();
        cin >> publications;
    }
    
    void putdata () override
    {
        cout << getName() << "\t" << getAge() << "\t" << publications << "\t" << cur_id << endl;
    }
    
};




int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n)
{
    try
    {
        if (n == 0)
            throw 0;
        
        else if (n == 1)
            throw 1;
        
        else if (n <= 100)
        {
            int d = largest_proper_divisor(n);
            cout << "result=" << d << endl;
        }
    }
    
    catch (int a)
    {
        if  (a == 0)
            cout << "largest proper divisor is not defined for n=0" << endl;
        
        else if (a == 1)
            cout << "largest proper divisor is not defined for n=1" << endl;
    }
    cout << "returning control flow to caller" << endl;
}

int main()
{
    int n;
    cin >> n;
    process_input(n);
    return 0;
}

#endif


struct Node
{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
    
protected:
    map <int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
};

class LRUCache: public Cache
{
public:
    LRUCache(int c)
    {
        cp = c;
    }
    
    void set(int key, int value)
    {
        Node* list;
        
        if (mp.empty())
        {
            
            list = new Node (key,value);
            tail = head = list;
            mp [key] = list;
        }
        
        
        map <int, Node*> :: iterator it = mp.find (key);
        
        if ( it != mp.end() )
        {
            it->second->value = value;
            
            if (head == it->second)
                return;
            
            it->second->prev->next = it->second->next;
            
            if (tail == it->second)
                tail = tail->prev;
            
            else
                it->second->next->prev = it->second->prev;
            
            it->second->next = head;
            it->second->prev = nullptr;
            head->prev = it->second;
            head = it->second;
        }
        else
        {
            list = new Node(head->prev, head, key, value);
            head->prev = list;
            head = list;
            mp [key] = list;
            if (mp.size() > cp)
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = nullptr;
            }
        }
    }
    int get(int k)
    {
        auto it = mp.find(k);
        if ( it != mp.end() )
        {
            return it->second->value;
        }
        
        return -1;
    }
};
