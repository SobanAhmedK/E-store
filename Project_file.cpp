#include "authentication.h"
#include "time_calculation.h"
#include "cart_functions.h"
#include "CRUD_operations.h"


int main()

{
   
    CART_LIST cart;
    BST order_tree;
    BST book_tree;
    BST food_tree;
    BST elect_tree;
    BST dress_tree;
    BST medicine_tree;

    int order_count = 0;
    string orderName;
    string orderPrice;
    string orderDescription;
    int orderID;
    int orderPriority;
    ifstream order_file("order_list.csv");
    if (order_file.is_open())
    {

        while (!order_file.eof())
        {
            if (order_count == 0)

            {

                string temp;
                getline(order_file, temp);
                order_count = 1;
            }
            else
            {

                getline(order_file, orderName, ',');
                getline(order_file, orderPrice, ',');
                order_file >> orderID;
                string temp1;
                string temp2;
                getline(order_file, temp1, ',');
                getline(order_file, orderDescription, ',');
                order_file >> orderPriority;
                getline(order_file, temp2, '\n');
                order_tree.head = order_tree.PriorityInsert(order_tree.head, orderName, orderPrice, orderID, orderDescription, orderPriority);
                time_updation();
            }
        }
        order_file.close();
    }
    else
    {
        cout << "error" << endl;
    }
    int count2 = 0;
    string name2;
    string price2;
    string manufacturer2;
    int id2;
    int priority2;

    ifstream file2("Medicine_project.csv");
    if (file2.is_open())
    {

        while (!file2.eof())
        {
            if (count2 == 0)

            {
                string temp;
                getline(file2, temp);
                count2 = 1;
            }
            else
            {
                getline(file2, name2, ',');
                getline(file2, price2, ',');
                file2 >> id2;
                string temp1;
                string temp2;
                getline(file2, temp1, ',');
                getline(file2, manufacturer2, ',');
                file2 >> priority2;
                getline(file2, temp2, '\n');
                medicine_tree.head = medicine_tree.insert(medicine_tree.head, name2, price2, id2, orderDescription, priority2);
            }
        }
        file2.close();
    }
    else
    {
        cout << "error" << endl;
    }
    int count4 = 0;
    string name4;
    string price4;
    string publishers;
    int id4;
    int priority4;

    ifstream file4("Books.csv");
    if (file4.is_open())
    {

        while (!file4.eof())
        {
            if (count4 == 0)

            {
                string temp;
                getline(file4, temp);
                count4 = 1;
            }
            else
            {
                getline(file4, name4, ',');
                getline(file4, price4, ',');
                file4 >> id4;
                string temp1;
                string temp2;
                getline(file4, temp1, ',');
                getline(file4, publishers, ',');
                file4 >> priority4;
                getline(file4, temp2);
                book_tree.head = book_tree.insert(book_tree.head, name4, price4, id4, publishers, priority4);
            }
        }
        file4.close();
    }
    else
    {
        cout << "error" << endl;
    }

    int count1 = 0;
    string name1;
    string price1;
    string description1;
    int id1;
    int priority1;

    ifstream file1("food.csv");
    if (file1.is_open())
    {

        while (!file1.eof())
        {
            if (count1 == 0)

            {
                string temp;
                getline(file1, temp);
                count1 = 1;
            }
            else
            {
                getline(file1, name1, ',');
                getline(file1, price1, ',');
                file1 >> id1;
                string temp1;
                string temp2;
                getline(file1, temp1, ',');
                getline(file1, description1, ',');
                file1 >> priority1;
                getline(file1, temp2, '\n');
                food_tree.head = food_tree.insert(food_tree.head, name1, price1, id1, description1, priority1);
            }
        }
        file1.close();
    }
    else
    {
        cout << "error" << endl;
    }

    int count3 = 0;
    string name3;
    string price3;
    string description3;
    int id3;
    int priority3;

    ifstream file3("garments.csv");
    if (file3.is_open())
    {

        while (!file3.eof())
        {
            if (count3 == 0)

            {
                string temp;
                getline(file3, temp);
                count3 = 1;
            }
            else
            {
                getline(file3, name3, ',');
                getline(file3, price3, ',');
                file3 >> id3;
                string temp1;
                string temp2;
                getline(file3, temp1, ',');
                getline(file3, description3, ',');
                file3 >> priority3;
                getline(file3, temp2, '\n');
                dress_tree.head = dress_tree.insert(dress_tree.head, name3, price3, id3, description3, priority3);
            }
        }
        file3.close();
    }
    else
    {
        cout << "error" << endl;
    }
    int count5 = 0;
    string name5;
    string price5;
    string description5;
    int id5;
    int priority5;

    ifstream file5("Electronics.csv");
    if (file5.is_open())
    {

        while (!file5.eof())
        {
            if (count5 == 0)

            {
                string temp;
                getline(file5, temp);
                count5 = 1;
            }
            else
            {
                getline(file5, name5, ',');
                getline(file5, price5, ',');
                file5 >> id5;
                string temp1;
                string temp2;
                getline(file5, temp1, ',');
                getline(file5, description5, ',');
                file5 >> priority5;
                getline(file5, temp2, '\n');
                elect_tree.head = elect_tree.insert(elect_tree.head, name5, price5, id5, description5, priority5);
            }
        }
        file5.close();
    }
    else
    {
        cout << "error" << endl;
    }

    int option;
    string user_name;
    int pass;
    // 1st do loop
    do
    {
        cout << "Press 1 to login as Customer:  " << endl;
        cout << "press 2 to login as a Seller: " << endl;
        cout << "press 0 to  EXIT ! " << endl;
        cin >> option;
        // 1st switch
        switch (option)
        {
        case 1:
        {
            int count_customer = 0;
        jump:
            cout << "Please Enter your username: " << endl;
            cin >> user_name;
            cout << "Plese Enter your PIN: " << endl;
            cin >> pass;
            if (authentication(user_name, pass) == true)
            {
                cout << " You have logged in successfully: " << endl;
                int opt_customer;
                // do loop 2
                do
                {
                    cout << " Press 1 to place an order: " << endl;
                    cout << " Press 2 to visit your your cart: " << endl;
                    cout << "press 0 to exit: " << endl;
                    cin >> opt_customer;
                    // switch 2
                    switch (opt_customer)
                    {
                    case 1:
                    {
                        int opt_category;
                        // do loop 3
                        do
                        {
                            cout << "***********Select the category***************" << endl;
                            cout << "Press 1 for a food item : " << endl;
                            cout << "Press 2 for Pharmaceutical item: " << endl;
                            cout << "Press 3 for Garments:  " << endl;
                            cout << "Press 4 for Books: " << endl;
                            cout << "Press 5 for electronics: " << endl;
                            cout << "Press 0 to SAVE and  EXit. " << endl;
                            cin >> opt_category;
                            // switch 3
                            switch (opt_category)
                            {
                            case 1:
                            {
                                int count = 0;
                                food_tree.InOrder(food_tree.head);
                                cout << endl;
                            jump_food:
                                cout << "Enter the ID of item you want to order: " << endl;
                                int key;
                                cin >> key;
                                TreeNode *searched = food_tree.searcchinBst(food_tree.head, key);
                                if (searched != NULL)
                                {
                                    order_tree.PriorityInsert(order_tree.head, searched->name2, searched->price2, searched->item_id2, searched->manufacturer2, searched->item_priority2);
                                    cart.add_to_cart(searched->name2, searched->price2, searched->item_id2);
                                    ifstream time_file("time.csv");
                                    if (time_file.is_open())
                                    {
                                        time_file >> minutes;
                                        string temp;
                                        getline(time_file, temp, ',');
                                        time_file >> count_of_orders;
                                        if (minutes == 0 && count_of_orders == 0)
                                        {
                                            minutes = 30;
                                            count_of_orders = 1;
                                        }
                                        else if (minutes > 0 && (count_of_orders % 100) == 0)
                                        {
                                            minutes = minutes + 30;
                                            count_of_orders++;
                                        }
                                        else if (minutes > 0 && count_of_orders > 0)
                                        {
                                            count_of_orders++;
                                        }
                                        time_file.close();
                                        ofstream file("time.csv", ios ::out | ios::trunc);
                                        file << minutes << "," << count_of_orders;
                                        file.close();
                                    }

                                    cout << " Your order has been placed successfully! " << endl;
                                    time(minutes);
                                    int undo;
                                    cout << "Press 1 to undo the order " << endl;
                                    cout << "press 0 to carry on" << endl;
                                    cin >> undo;
                                    if (undo == 1)
                                    {

                                        cout << cart.remove_item() << " is removed from your cart! " << endl;
                                        order_tree.deleteInBSt(order_tree.head, searched->item_id2);
                                    }
                                }
                                else
                                {
                                    cout << "No such item exist in the MENU , kindly search again! " << endl;
                                    count++;
                                    if (count != 3)
                                    {
                                        goto jump_food;
                                    }
                                }
                            }
                            break;

                            case 2:
                            {
                                int count = 0;
                                medicine_tree.InOrder(medicine_tree.head);
                                cout << endl;
                            jump_medicine:
                                cout << "Enter the ID of item you want to order: " << endl;
                                int key;
                                cin >> key;
                                TreeNode *searched = medicine_tree.searcchinBst(medicine_tree.head, key);
                                if (searched != NULL)
                                {
                                    order_tree.PriorityInsert(order_tree.head, searched->name2, searched->price2, searched->item_id2, searched->manufacturer2, searched->item_priority2);
                                    cart.add_to_cart(searched->name2, searched->price2, searched->item_id2);
                                    ifstream time_file("time.csv");
                                    if (time_file.is_open())
                                    {
                                        time_file >> minutes;
                                        string temp;
                                        getline(time_file, temp, ',');
                                        time_file >> count_of_orders;
                                        if (minutes == 0 && count_of_orders == 0)
                                        {
                                            minutes = 30;
                                            count_of_orders = 1;
                                        }
                                        else if (minutes > 0 && (count_of_orders % 100) == 0)
                                        {
                                            minutes = minutes + 30;
                                            count_of_orders++;
                                        }
                                        else if (minutes > 0 && count_of_orders > 0)
                                        {
                                            count_of_orders++;
                                        }
                                        time_file.close();
                                        ofstream file("time.csv", ios ::out | ios::trunc);
                                        file << minutes << "," << count_of_orders;
                                        file.close();
                                    }
                                    cout << " Your order has been placed successfully! " << endl;
                                    time(minutes);
                                    int undo;
                                    cout << "Press 1 to undo the order " << endl;
                                    cout << "press 0 to carry on" << endl;
                                    cin >> undo;
                                    if (undo == 1)
                                    {

                                        cout << cart.remove_item() << " is removed from your cart! " << endl;
                                        order_tree.deleteInBSt(order_tree.head, searched->item_id2);
                                    }
                                }
                                else
                                {
                                    cout << "No such item exist in the MENU , kindly search again! " << endl;
                                    count++;
                                    if (count != 3)
                                    {
                                        goto jump_medicine;
                                    }
                                }
                            }
                            break;

                            case 3:
                            {
                                int count = 0;
                                dress_tree.InOrder(dress_tree.head);
                                cout << endl;
                            jump_dress:
                                cout << "Enter the ID of item you want to order: " << endl;
                                int key;
                                cin >> key;
                                TreeNode *searched = dress_tree.searcchinBst(dress_tree.head, key);
                                if (searched != NULL)
                                {
                                    order_tree.PriorityInsert(order_tree.head, searched->name2, searched->price2, searched->item_id2, searched->manufacturer2, searched->item_priority2);
                                    cart.add_to_cart(searched->name2, searched->price2, searched->item_id2);
                                    ifstream time_file("time.csv");
                                    if (time_file.is_open())
                                    {
                                        time_file >> minutes;
                                        string temp;
                                        getline(time_file, temp, ',');
                                        time_file >> count_of_orders;
                                        if (minutes == 0 && count_of_orders == 0)
                                        {
                                            minutes = 30;
                                            count_of_orders = 1;
                                        }
                                        else if (minutes > 0 && (count_of_orders % 100) == 0)
                                        {
                                            minutes = minutes + 30;
                                            count_of_orders++;
                                        }
                                        else if (minutes > 0 && count_of_orders > 0)
                                        {
                                            count_of_orders++;
                                        }
                                        time_file.close();
                                        ofstream file("time.csv", ios ::out | ios::trunc);
                                        file << minutes << "," << count_of_orders;
                                        file.close();
                                    }
                                    cout << " Your order has been placed successfully! " << endl;
                                    time(minutes);
                                    int undo;
                                    cout << "Press 1 to undo the order " << endl;
                                    cout << "press 0 to carry on" << endl;
                                    cin >> undo;
                                    if (undo == 1)
                                    {

                                        cout << cart.remove_item() << " is removed from your cart! " << endl;
                                        order_tree.deleteInBSt(order_tree.head, searched->item_id2);
                                    }
                                }
                                else
                                {
                                    cout << "No such item exist in the MENU , kindly search again! " << endl;
                                    count++;
                                    if (count != 3)
                                    {
                                        goto jump_dress;
                                    }
                                }
                            }
                            break;

                            case 4:
                            {
                                int count = 0;
                                book_tree.InOrder(book_tree.head);
                                cout << endl;
                            jump_book:
                                cout << "Enter the ID of item you want to order: " << endl;
                                int key;
                                cin >> key;
                                TreeNode *searched = book_tree.searcchinBst(book_tree.head, key);
                                if (searched != NULL)
                                {
                                    order_tree.PriorityInsert(order_tree.head, searched->name2, searched->price2, searched->item_id2, searched->manufacturer2, searched->item_priority2);
                                    cart.add_to_cart(searched->name2, searched->price2, searched->item_id2);
                                    ifstream time_file("time.csv");
                                    if (time_file.is_open())
                                    {
                                        time_file >> minutes;
                                        string temp;
                                        getline(time_file, temp, ',');
                                        time_file >> count_of_orders;
                                        if (minutes == 0 && count_of_orders == 0)
                                        {
                                            minutes = 30;
                                            count_of_orders = 1;
                                        }
                                        else if (minutes > 0 && (count_of_orders % 100) == 0)
                                        {
                                            minutes = minutes + 30;
                                            count_of_orders++;
                                        }
                                        else if (minutes > 0 && count_of_orders > 0)
                                        {
                                            count_of_orders++;
                                        }
                                        time_file.close();
                                        ofstream file("time.csv", ios ::out | ios::trunc);
                                        file << minutes << "," << count_of_orders;
                                        file.close();
                                    }
                                    cout << " Your order has been placed successfully! " << endl;
                                    time(minutes);
                                    int undo;
                                    cout << "Press 1 to undo the order " << endl;
                                    cout << "press 0 to carry on" << endl;
                                    cin >> undo;
                                    if (undo == 1)
                                    {

                                        cout << cart.remove_item() << " is removed from your cart! " << endl;
                                        order_tree.deleteInBSt(order_tree.head, searched->item_id2);
                                    }
                                }
                                else
                                {
                                    cout << "No such item exist in the MENU , kindly search again! " << endl;
                                    count++;
                                    if (count != 3)
                                    {
                                        goto jump_book;
                                    }
                                }
                            }
                            break;

                            case 5:
                            {

                                int count = 0;
                                elect_tree.InOrder(elect_tree.head);
                                cout << endl;
                            jump_elect:
                                cout << "Enter the ID of item you want to order: " << endl;
                                int key;
                                cin >> key;
                                TreeNode *searched = elect_tree.searcchinBst(elect_tree.head, key);
                                if (searched != NULL)
                                {
                                    order_tree.PriorityInsert(order_tree.head, searched->name2, searched->price2, searched->item_id2, searched->manufacturer2, searched->item_priority2);
                                    cart.add_to_cart(searched->name2, searched->price2, searched->item_id2);
                                    ifstream time_file("time.csv");
                                    if (time_file.is_open())
                                    {
                                        time_file >> minutes;
                                        string temp;
                                        getline(time_file, temp, ',');
                                        time_file >> count_of_orders;
                                        if (minutes == 0 && count_of_orders == 0)
                                        {
                                            minutes = 30;
                                            count_of_orders = 1;
                                        }
                                        else if (minutes > 0 && (count_of_orders % 100) == 0)
                                        {
                                            minutes = minutes + 30;
                                            count_of_orders++;
                                        }
                                        else if (minutes > 0 && count_of_orders > 0)
                                        {
                                            count_of_orders++;
                                        }
                                        time_file.close();
                                        ofstream file("time.csv", ios ::out | ios::trunc);
                                        file << minutes << "," << count_of_orders;
                                        file.close();
                                    }
                                    cout << " Your order has been placed successfully! " << endl;
                                    time(minutes);
                                    int undo;
                                    cout << "Press 1 to undo the order " << endl;
                                    cout << "press 0 to carry on" << endl;
                                    cin >> undo;
                                    if (undo == 1)
                                    {

                                        cout << cart.remove_item() << " is removed from your cart! " << endl;
                                        order_tree.deleteInBSt(order_tree.head, searched->item_id2);
                                    }
                                }
                                else
                                {
                                    cout << "No such item exist in the MENU , kindly search again! " << endl;
                                    count++;
                                    if (count != 3)
                                    {
                                        goto jump_elect;
                                    }
                                }
                            }
                            break;

                            case 0:
                            {
                                writeTreeToCSV(order_tree.head, "order_list.csv");
                                break;
                            }
                            break;
                            }
                        } while (opt_category != 0);
                    }
                    break;

                    case 2:
                    {
                        // do loop 4

                        int opt_cart;
                        do
                        {
                            cout << "Press 1 to display your cart: " << endl;
                            cout << "press 2 to delete an item from your cart: " << endl;
                            cout << "Press 0 to  Exit. " << endl;
                            cin >> opt_cart;
                            // switch 4
                            switch (opt_cart)
                            {
                            case 1:
                            {
                                cart.Display_cart();
                            }
                            break;
                            case 2:
                            {
                                int count = 0;
                                int key;
                            jump_cart:
                                cout << "kindly enter the key of the item: " << endl;
                                cin >> key;
                                cart_node *deleted = cart.deleteNodeByKey(key);
                                if (deleted != NULL)
                                {
                                    cout << deleted->item_name << " is removed from your cart! " << endl;
                                    order_tree.deleteInBSt(order_tree.head, deleted->item_id);
                                }
                                else
                                {
                                    cout << "No such item found with this id , please Re-enter it!  " << endl;
                                    count++;
                                    if (count != 3)
                                    {
                                        goto jump_cart;
                                    }
                                }
                            }
                            break;

                            case 0:
                            {
                                break;
                            }
                            break;
                            }
                        } while (opt_cart != 0);
                    }
                    break;
                    case 0:
                    {
                        break;
                    }
                    break;
                    }

                } while (opt_customer != 0);
            }
            else
            {
                cout << "Wrong password, please try again: " << endl;
                count_customer++;
                if (count_customer != 3)
                {
                    goto jump;
                }
            }
        }
        break;
        case 2:
        {
            int count_seller = 0;
        jump2:
            cout << "Please Enter your username: " << endl;
            cin >> user_name;
            cout << "Plese Enter your PIN: " << endl;
            cin >> pass;
            if (authentication(user_name, pass) == true)
            {
                int opt_seller;
                cout << " You have logged in successfully: " << endl;
                // do loop 5
                do
                {
                    cout << "Press 1 to visit order list: " << endl;
                    cout << "Press 2 to visit your store's item categories: " << endl;
                    cout << "press 0 to Back. " << endl;
                    cin >> opt_seller;
                    // switch 5
                    switch (opt_seller)
                    {

                    case 1:
                    { // do loop 6
                        int opt_order;
                        do
                        {
                            cout << "Press 1 to display Order List: " << endl;
                            cout << "Press 2 to delete an order( If you are out of stock): " << endl;
                            cout << "press 0 to SAVE and EXIT. " << endl;
                            cin >> opt_order;
                            // switch 6
                            switch (opt_order)
                            {
                            case 1:
                            {
                                order_tree.InOrder(order_tree.head);
                                cout << endl;
                            }
                            break;
                            case 2:
                            {
                                int id, priority;
                                order_tree.InOrder(order_tree.head);
                                cout << endl;
                            jump_order:
                                cout << "Enter the order ID  you want to remove: " << endl;
                                cin >> id;
                                TreeNode *searched = order_tree.searcchinBst(order_tree.head, id);
                                if (searched != NULL)
                                {
                                    order_tree.deleteInBSt(order_tree.head, id);
                                    cout << "Item has been deleted from order list. " << endl;
                                    cart.deleteNodeByKey(id);
                                }
                                else
                                {
                                    cout << "No such item exist in  the order list. " << endl;
                                    int again;
                                    cout << "If you want to delete other Order's press 1" << endl;
                                    cout << "Otherwise press 0 to carry on. " << endl;
                                    cin >> again;
                                    if (again == 1)
                                    {
                                        goto jump_order;
                                    }
                                }
                            }
                            break;
                            case 0:
                            {
                                writeTreeToCSV(order_tree.head, "order_list.csv");
                                break;
                            }
                            break;
                            }

                        } while (opt_order != 0);
                    }
                    break;
                    case 2:
                    {
                        int opt_categories;
                        // do loop 7
                        do
                        {

                            cout << "Press 1 to visit food category: " << endl;
                            cout << "Press 2 to visit medicine category: " << endl;
                            cout << "Press 3 to visit Garments category: " << endl;
                            cout << "Press 4 to visit books category:  " << endl;
                            cout << "Press 5 to visit Electronics category: " << endl;
                            cout << "Press 0 to Exit. " << endl;
                            cin >> opt_categories;
                            // switch 7
                            switch (opt_categories)
                            {
                            case 1:
                            {
                                int op_food;
                                do
                                {
                                    cout << "Press 1 to display items of the category: " << endl;
                                    cout << "Press 2 to to delete an item :" << endl;
                                    cout << "Press 3 to insert  a new food item : " << endl;
                                    cout << "Press 4 to update price of an item: " << endl;
                                    cout << "Press 0 to SAVE and Exit. " << endl;
                                    cin >> op_food;
                                    // switch 7
                                    switch (op_food)
                                    {
                                    case 1:
                                    {
                                        cout << "ITEMS in the Category are: " << endl;
                                        food_tree.InOrder(food_tree.head);
                                        cout << endl;
                                    }
                                    break;
                                    case 2:
                                    {
                                        food_tree.InOrder(food_tree.head);
                                        cout << endl;
                                        int id;
                                        int again;
                                    jump_here:
                                        cout << "Enter the ID of item you want to delete: " << endl;
                                        cin >> id;
                                        TreeNode *search = food_tree.searcchinBst(food_tree.head, id);
                                        if (search != NULL)
                                        {
                                            food_tree.deleteInBSt(food_tree.head, id);
                                            cout << " The item " << search->name2 << " with ID " << id << " has been deleted. " << endl;
                                            cout << " IF you want to delete more items press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here;
                                            }
                                        }
                                        else
                                        {
                                            cout << "The ID you enter is incorrect, Re-enter please." << endl;
                                            cout << " IF you want to re-enter  press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here;
                                            }
                                        }
                                    }
                                    break;

                                    case 3:
                                    {
                                        int id;
                                        int again;
                                        string name, price, description;
                                    jump_insert1:
                                        cout << "Enter the Information of new item: " << endl;
                                        cout << "Name: ";
                                        cin >> name;
                                        cout << endl;
                                        cout << "Price: ";
                                        cin >> price;
                                        cout << endl;
                                        cout << "ID: ";
                                        cin >> id;
                                        cout << "Description : ";
                                        cin >> description;
                                        cout << endl;
                                        int insert = food_tree.InsertInBst(food_tree.head, name, price, id, description1, 1);
                                        if (insert == -1)
                                        {

                                            cout << "Try different ID! " << endl;
                                            cout << "Press 1 to try different ID: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert1;
                                            }
                                        }
                                        else
                                        {
                                            cout << "Item " << name << " successfully added to the category. " << endl;
                                            cout << "Press 1 to  add more items: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert1;
                                            }
                                        }
                                    }
                                    break;
                                    case 4:
                                    {
                                        int id;
                                        int again;
                                        string price;
                                    jump_price1:
                                        food_tree.InOrder(food_tree.head);
                                        cout << endl;
                                        cout << "Enter the id of the item : ";
                                        cin >> id;
                                        cout << endl;
                                        cout << "Enter the new price of item: ";
                                        cin >> price;
                                        cout << endl;
                                        TreeNode *search = food_tree.UpdatePrice(food_tree.head, price, id);
                                        if (search != NULL)
                                        {
                                            cout << "Price of the item " << search->name2 << " is updated successfully! " << endl;
                                            cout << "IF you want to update another press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price1;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No item found with such id! " << endl;
                                            cout << "IF you want to Re_enter press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price1;
                                            }
                                        }
                                    }
                                    break;
                                    case 0:

                                    {
                                        writeTreeToCSV(food_tree.head, "food.csv");
                                        break;
                                    }
                                    break;
                                    }

                                } while (op_food != 0);
                            }
                            break;
                            case 2:
                            {

                                int op_med;
                                do
                                {
                                    cout << "Press 1 to display items of the category: " << endl;
                                    cout << "Press 2 to to delete an item :" << endl;
                                    cout << "Press 3 to insert  a new Medicine item : " << endl;
                                    cout << "Press 4 to update price of an item: " << endl;
                                    cout << "Press 0 to SAVE and Exit. " << endl;
                                    cin >> op_med;
                                    // switch 8
                                    switch (op_med)
                                    {
                                    case 1:
                                    {
                                        cout << "ITEMS in the Category are: " << endl;
                                        medicine_tree.InOrder(medicine_tree.head);
                                        cout << endl;
                                    }
                                    break;
                                    case 2:
                                    {
                                        medicine_tree.InOrder(medicine_tree.head);
                                        cout << endl;
                                        int id;
                                        int again;
                                    jump_here1:
                                        cout << "Enter the ID of item you want to delete: " << endl;
                                        cin >> id;
                                        TreeNode *search = medicine_tree.searcchinBst(medicine_tree.head, id);
                                        if (search != NULL)
                                        {
                                            medicine_tree.deleteInBSt(medicine_tree.head, id);
                                            cout << " The item " << search->name2 << " with ID " << id << " has been deleted. " << endl;
                                            cout << " IF you want to delete more items press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here1;
                                            }
                                        }
                                        else
                                        {
                                            cout << "The ID you enter is incorrect, Re-enter please." << endl;
                                            cout << " IF you want to re-enter  press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here1;
                                            }
                                        }
                                    }
                                    break;

                                    case 3:
                                    {
                                        int id;
                                        int again;
                                        string name, price, description;
                                    jump_insert2:
                                        cout << "Enter the Information of new item: " << endl;
                                        cout << "Name: ";
                                        cin >> name;
                                        cout << endl;
                                        cout << "Price: ";
                                        cin >> price;
                                        cout << endl;
                                        cout << "ID: ";
                                        cin >> id;
                                        cout << "Description : ";
                                        cin >> description;
                                        cout << endl;
                                        int insert = medicine_tree.InsertInBst(medicine_tree.head, name, price, id, description, 2);
                                        if (insert == -1)
                                        {

                                            cout << "Try different ID! " << endl;
                                            cout << "Press 1 to try different ID: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert2;
                                            }
                                        }
                                        else
                                        {
                                            cout << "Item " << name << " successfully added to the category. " << endl;
                                            cout << "Press 1 to  add more items: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert2;
                                            }
                                        }
                                    }
                                    break;
                                    case 4:
                                    {
                                        int id;
                                        int again;
                                        string price;
                                    jump_price2:
                                        medicine_tree.InOrder(medicine_tree.head);
                                        cout << endl;
                                        cout << "Enter the id of the item : ";
                                        cin >> id;
                                        cout << endl;
                                        cout << "Enter the new price of item: ";
                                        cin >> price;
                                        cout << endl;
                                        TreeNode *search = medicine_tree.UpdatePrice(medicine_tree.head, price, id);
                                        if (search != NULL)
                                        {
                                            cout << "Price of the item " << search->name2 << " is updated successfully! " << endl;
                                            cout << "IF you want to update another press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price2;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No item found with such id! " << endl;
                                            cout << "IF you want to Re_enter press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price2;
                                            }
                                        }
                                    }
                                    break;
                                    case 0:
                                    {
                                        writeTreeToCSV(medicine_tree.head, "Medicine_project.csv");

                                        break;
                                    }
                                    break;
                                    }

                                } while (op_med != 0);
                            }
                            break;

                            case 3:
                            {

                                int op_dress;
                                do
                                {
                                    cout << "Press 1 to display items of the category: " << endl;
                                    cout << "Press 2 to to delete an item :" << endl;
                                    cout << "Press 3 to insert  a new dress item : " << endl;
                                    cout << "Press 4 to update price of an item: " << endl;
                                    cout << "Press 0 to SAVE and Exit. " << endl;
                                    cin >> op_dress;
                                    // switch 9
                                    switch (op_dress)
                                    {
                                    case 1:
                                    {
                                        cout << "ITEMS in the Category are: " << endl;
                                        dress_tree.InOrder(dress_tree.head);
                                        cout << endl;
                                    }
                                    break;
                                    case 2:
                                    {
                                        dress_tree.InOrder(dress_tree.head);
                                        cout << endl;
                                        int id;
                                        int again;
                                    jump_here3:
                                        cout << "Enter the ID of item you want to delete: " << endl;
                                        cin >> id;
                                        TreeNode *search = dress_tree.searcchinBst(dress_tree.head, id);
                                        if (search != NULL)
                                        {
                                            dress_tree.deleteInBSt(dress_tree.head, id);
                                            cout << " The item " << search->name2 << " with ID " << id << " has been deleted. " << endl;
                                            cout << " IF you want to delete more items press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here3;
                                            }
                                            //program for the customer and the buyer are in two different splits that can be used by different numbers of differnt method by multiplying teh numbers of different behaviours that can never be the multiple by the number of different subjects by the number of different parameters that can be done by the multiple features by the number of multiple parameters that can be changed and neither any of the good by the multiple sub behaviours of the number of the data set and our machine learning models by obtaining the multiple of the differnet behaviourtal patterns by the number of behaviours 
                                        }
                                        else
                                        {
                                            cout << "The ID you enter is incorrect, Re-enter please." << endl;
                                            cout << " IF you want to re-enter  press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here3;
                                            }
                                        }
                                    }
                                    break;

                                    case 3:
                                    {
                                        int id;
                                        int again;
                                        string name, price, description;
                                    jump_insert3:
                                        cout << "Enter the Information of new item: " << endl;
                                        cout << "Name: ";
                                        cin >> name;
                                        cout << endl;
                                        cout << "Price: ";
                                        cin >> price;
                                        cout << endl;
                                        cout << "ID: ";
                                        cin >> id;
                                        cout << "Description : ";
                                        cin >> description;
                                        cout << endl;
                                        int insert = dress_tree.InsertInBst(dress_tree.head, name, price, id, description, 3);
                                        if (insert == -1)
                                        {

                                            cout << "Try different ID! " << endl;
                                            cout << "Press 1 to try different ID: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert3;
                                            }
                                        }
                                        else
                                        {
                                            cout << "Item " << name << " successfully added to the category. " << endl;
                                            cout << "Press 1 to  add more items: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert3;
                                            }
                                        }
                                    }
                                    break;
                                    case 4:
                                    {
                                        int id;
                                        int again;
                                        string price;
                                    jump_price3:
                                        dress_tree.InOrder(dress_tree.head);
                                        cout << endl;
                                        cout << "Enter the id of the item : ";
                                        cin >> id;
                                        cout << endl;
                                        cout << "Enter the new price of item: ";
                                        cin >> price;
                                        cout << endl;
                                        TreeNode *search = dress_tree.UpdatePrice(dress_tree.head, price, id);
                                        if (search != NULL)
                                        {
                                            cout << "Price of the item " << search->name2 << " is updated successfully! " << endl;
                                            cout << "IF you want to update another press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price3;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No item found with such id! " << endl;
                                            cout << "IF you want to Re_enter press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price3;
                                            }
                                        }
                                    }
                                    break;
                                    case 0:
                                    {
                                        writeTreeToCSV(dress_tree.head, "garments.csv");

                                        break;
                                    }
                                    break;
                                    }

                                } while (op_dress != 0);
                            }
                            break;

                            case 4:
                            {

                                int op_book;
                                do
                                {
                                    cout << "Press 1 to display items of the category: " << endl;
                                    cout << "Press 2 to to delete an item :" << endl;
                                    cout << "Press 3 to insert  a new book item : " << endl;
                                    cout << "Press 4 to update price of an item: " << endl;
                                    cout << "Press 0 to SAVE and Exit. " << endl;
                                    cin >> op_book;
                                    // switch 9
                                    switch (op_book)
                                    {
                                    case 1:
                                    {
                                        cout << "ITEMS in the Category are: " << endl;
                                        book_tree.InOrder(book_tree.head);
                                        cout << endl;
                                    }
                                    break;
                                    case 2:
                                    {
                                        book_tree.InOrder(book_tree.head);
                                        cout << endl;
                                        int id;
                                        int again;
                                    jump_here4:
                                        cout << "Enter the ID of item you want to delete: " << endl;
                                        cin >> id;
                                        TreeNode *search = book_tree.searcchinBst(book_tree.head, id);
                                        if (search != NULL)
                                        {
                                            book_tree.deleteInBSt(book_tree.head, id);
                                            cout << " The item " << search->name2 << " with ID " << id << " has been deleted. " << endl;
                                            cout << " IF you want to delete more items press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here4;
                                            }
                                        }
                                        else
                                        {
                                            cout << "The ID you enter is incorrect, Re-enter please." << endl;
                                            cout << " IF you want to re-enter  press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here4;
                                            }
                                        }
                                    }
                                    break;

                                    case 3:
                                    {
                                        int id;
                                        int again;
                                        string name, price, description;
                                    jump_insert4:
                                        cout << "Enter the Information of new item: " << endl;
                                        cout << "Name: ";
                                        cin >> name;
                                        cout << endl;
                                        cout << "Price: ";
                                        cin >> price;
                                        cout << endl;
                                        cout << "ID: ";
                                        cin >> id;
                                        cout << "Description : ";
                                        cin >> description;
                                        cout << endl;
                                        int insert = book_tree.InsertInBst(book_tree.head, name, price, id, description, 4);
                                        if (insert == -1)
                                        {

                                            cout << "Try different ID! " << endl;
                                            cout << "Press 1 to try different ID: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert4;
                                            }
                                        }
                                        else
                                        {
                                            cout << "Item " << name << " successfully added to the category. " << endl;
                                            cout << "Press 1 to  add more items: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert4;
                                            }
                                        }
                                    }
                                    break;
                                    case 4:
                                    {
                                        int id;
                                        int again;
                                        string price;
                                    jump_price4:
                                        book_tree.InOrder(book_tree.head);
                                        cout << endl;
                                        cout << "Enter the id of the item : ";
                                        cin >> id;
                                        cout << endl;
                                        cout << "Enter the new price of item: ";
                                        cin >> price;
                                        cout << endl;
                                        TreeNode *search = book_tree.UpdatePrice(book_tree.head, price, id);
                                        if (search != NULL)
                                        {
                                            cout << "Price of the item " << search->name2 << " is updated successfully! " << endl;
                                            cout << "IF you want to update another press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price4;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No item found with such id! " << endl;
                                            cout << "IF you want to Re_enter press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price4;
                                            }
                                        }
                                    }
                                    break;
                                    case 0:
                                    {

                                        writeTreeToCSV(book_tree.head, "Books.csv");
                                        break;
                                    }
                                    break;
                                    }

                                } while (op_book != 0);
                            }
                            break;

                            case 5:
                            {

                                int op_elect;
                                do
                                {
                                    cout << "Press 1 to display items of the category: " << endl;
                                    cout << "Press 2 to to delete an item :" << endl;
                                    cout << "Press 3 to insert  a new Eectronic item : " << endl;
                                    cout << "Press 4 to update price of an item: " << endl;
                                    cout << "Press 0 to SAVE and Exit. " << endl;
                                    cin >> op_elect;
                                    // switch 10
                                    switch (op_elect)
                                    {
                                    case 1:
                                    {
                                        cout << "ITEMS in the Category are: " << endl;
                                        elect_tree.InOrder(elect_tree.head);
                                        cout << endl;
                                    }
                                    break;
                                    case 2:
                                    {
                                        elect_tree.InOrder(elect_tree.head);
                                        cout << endl;
                                        int id;
                                        int again;
                                    jump_here5:
                                        cout << "Enter the ID of item you want to delete: " << endl;
                                        cin >> id;
                                        TreeNode *search = elect_tree.searcchinBst(elect_tree.head, id);
                                        if (search != NULL)
                                        {
                                            elect_tree.deleteInBSt(elect_tree.head, id);
                                            cout << " The item " << search->name2 << " with ID " << id << " has been deleted. " << endl;
                                            cout << " IF you want to delete more items press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here5;
                                            }
                                        }
                                        else
                                        {
                                            cout << "The ID you enter is incorrect, Re-enter please." << endl;
                                            cout << " IF you want to re-enter  press 1 " << endl;
                                            cout << "Else Press 0 to carry on." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_here5;
                                            }
                                        }
                                    }
                                    break;

                                    case 3:
                                    {
                                        int id;
                                        int again, insert;
                                        string name, price, description;
                                    jump_insert5:
                                        cout << "Enter the Information of new item: " << endl;
                                        cout << "Name: ";
                                        cin >> name;
                                        cout << endl;
                                        cout << "Price: ";
                                        cin >> price;
                                        cout << endl;
                                        cout << "ID: ";
                                        cin >> id;
                                        cout << "Description : ";
                                        cin >> description;
                                        cout << endl;
                                        insert = elect_tree.InsertInBst(elect_tree.head, name, price, id, description, 5);
                                        if (insert == -1)
                                        {

                                            cout << "Try different ID! " << endl;
                                            cout << "Press 1 to try different ID: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert5;
                                            }
                                        }
                                        else
                                        {
                                            cout << "Item " << name << " successfully added to the category. " << endl;
                                            cout << "Press 1 to  add more items: " << endl;
                                            cout << "Else press 0 to continue. " << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_insert5;
                                            }
                                        }
                                    }
                                    break;
                                    case 4:
                                    {
                                        int id;
                                        int again;
                                        string price;
                                    jump_price5:
                                        elect_tree.InOrder(elect_tree.head);
                                        cout << endl;
                                        cout << "Enter the id of the item : ";
                                        cin >> id;
                                        cout << endl;
                                        cout << "Enter the new price of item: ";
                                        cin >> price;
                                        cout << endl;
                                        TreeNode *search = elect_tree.UpdatePrice(elect_tree.head, price, id);
                                        if (search != NULL)
                                        {
                                            cout << "Price of the item " << search->name2 << " is updated successfully! " << endl;
                                            cout << "IF you want to update another press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price5;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No item found with such id! " << endl;
                                            cout << "IF you want to Re_enter press 1: " << endl;
                                            cout << "Else press 0 to continue." << endl;
                                            cin >> again;
                                            if (again == 1)
                                            {
                                                goto jump_price5;
                                            }
                                        }
                                    }
                                    break;
                                    case 0:
                                    {
                                        writeTreeToCSV(elect_tree.head, "Electronics.csv");
                                        break;
                                    }
                                    break;
                                    }

                                } while (op_elect != 0);
                            }
                            break;
                            case 0:
                            {
                                break;
                            }
                            break;
                            }
                        } while (opt_categories != 0);
                    }
                    break;
                    }

                } while (opt_seller != 0);
            }
            else
            {
                cout << "Wrong password, please try again: " << endl;
                count_seller++;
                if (count_seller != 3)
                {
                    goto jump2;
                }
            }
        }
        break;
        case 0:
        {
            writeTreeToCSV(food_tree.head, "food.csv");
            writeTreeToCSV(medicine_tree.head, "Medicine_project.csv");
            writeTreeToCSV(dress_tree.head, "garments.csv");
            writeTreeToCSV(book_tree.head, "Books.csv");
            writeTreeToCSV(elect_tree.head, "Electronics.csv");
            writeTreeToCSV(order_tree.head, "order_list.csv");

            break;
        }
        break;
        }

    } while (option != 0);
    return 0;
}
