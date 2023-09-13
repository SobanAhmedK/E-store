#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


struct cart_node
{
    string item_name;
    string price;
    int item_id;
    cart_node *next;

    cart_node()
    {
        next = NULL;
        item_id = 0;
    }
    cart_node(string name, string pr, int id1)
    {
        item_name = name;
        price = pr;
        item_id = id1;
        next = NULL;
    }
};
class CART_LIST
{
public:
    cart_node *start;
    CART_LIST()
    {
        start = NULL;
    }
    void add_to_cart(string name, string pr, int id)
    {
        cart_node *n = new cart_node(name, pr, id);

        if (start == NULL)
        {
            start = n;
        }
        else
        {
            n->next = start;
            start = n;
        }
    }
    string remove_item()
    {
        if (start == NULL)
        {
            string s = "cart is empty ";
            return s;
        }
        else
        {
            cart_node *temp = start;
            start = start->next;
            return temp->item_name;
        }
    }
    void Display_cart()

    {
        if (start == NULL)
        {
            cout << "Dear customer your cart is empty  " << endl;
        }
        else

        {
            cart_node *temp;
            temp = start;
            cout << "Name of item" << setw(10) << "Price" << setw(10) << "Item ID" << endl;
            while (temp != NULL)
            {
                cout << temp->item_name << setw(10) << temp->price << setw(10) << temp->item_id << endl;
                temp = temp->next;
            }
            delete temp;
            cout << endl;
        }
    }
    cart_node *deleteNodeByKey(int k)
    {
        cart_node *temp1 = NULL;
        if (start == NULL)
        {
            return temp1;
        }
        else if (start != NULL)
        {
            if (start->item_id == k)
            {
                temp1 = start;
                start = start->next;
                return temp1;
            }
            else
            {
                // cart_node * temp = NULL;
                cart_node *prevptr = start;
                cart_node *currentptr = start->next;
                while (currentptr != NULL)
                {
                    if (currentptr->item_id == k)
                    {
                        temp1 = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp1 != NULL)
                {
                    prevptr->next = temp1->next;
                    return temp1;
                }
                else
                {
                    return temp1;
                }
            }
        }
    }
};