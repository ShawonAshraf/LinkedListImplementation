#include <iostream>
#include <list>
#include <algorithm> // for reverse

using namespace std;

// if you want to use STL
// use list
// otherwise do it manually

//-----------------------------------

// a singly linked list
//////////////////////

template <class T>
class ListNode
{
public:
    
    T element;
    ListNode<T> *next;
};

template <class T>
class LinkedList
{
public:
    LinkedList()
    {
        head = 0; // NULL == 0
    }
    ~LinkedList()
    {
        MakeEmpty();
    }
    
    void Insert(T item)
    {
        ListNode<T> *t = new ListNode<T>;
        
        t->element = item;
        t->next = head;
        head = t;
        
    }
    
    void ReverseList()
    {
        ListNode<T> *current, *next, *prev;
        
        current = new ListNode<T>;
        next = 0;
        prev = 0;
        
        current = head;
        while(current != 0)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
    }
    
    void Print()
    {
        ListNode<T> *t = new ListNode<T>;
        
        t = head;
        while(t != 0)
        {
            cout << t-> element << " ";
            t = t->next;
        }
        cout << endl;
        
        delete t;
        t = 0;
    }
    
    
    void MakeEmpty()
    {
        while(head != 0)
        {
            ListNode<T> *t = new ListNode<T>;
            t = head;
            head = head->next;
            
            delete t;
            t = 0;
        }
    }
    
    
    
private:
    
    ListNode<T> *head;
    
};


int main()
{
    //
    //
    // using STL list container
    
    cout << "\t\tUsing STL list container\n" << endl;
    
    list<int> l; // using a int type list
    
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    
    cout << "Before reversing : ";
    for(list <int> :: iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    l.reverse();
    cout << "After reversing : ";
    for(list <int> :: iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
    
    
    //--------------------------------
    
    
    //
    //
    // manually
    
    cout << "\t\tManual Implementation\n" << endl;
    
    LinkedList<int> link;
    
    link.Insert(6);
    link.Insert(7);
    link.Insert(8);
    
    cout << "Before Reversing : ";
    link.Print();
    
    link.ReverseList();
    cout << "After Reversing : ";
    link.Print();
    cout << endl;
    
    return 0;
}