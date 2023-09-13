#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
 
class TreeNode
{
public:
    string name2;
    string price2;
    string manufacturer2;
    int item_id2;
    int item_priority2;
    TreeNode *left;
    TreeNode *right;
    TreeNode *previous;
    TreeNode()
    {
        item_priority2 = 0;
        left = NULL;
        right = NULL;
        previous = NULL;
    }
    TreeNode(string n, string p, int id, string m, int priority)
    {
        left = NULL;
        right = NULL;
        previous = NULL;
        name2 = n;
        price2 = p;
        manufacturer2 = m;
        item_priority2 = priority;
        item_id2 = id;
    }
};

class BST
{

public:
    TreeNode *head;
    TreeNode *end;
    BST()
    {
        end = NULL;
        head = NULL;
    }

    TreeNode *insert(TreeNode *head, string name, string price, int id, string description, int priority)
    {
        if (head == NULL)
        {
            TreeNode *newNode = new TreeNode(name, price, id, description, priority);
            return newNode;
        }

        if (id < head->item_id2)
            head->left = insert(head->left, name, price, id, description, priority);
        else if (id > head->item_id2)
            head->right = insert(head->right, name, price, id, description, priority);
        return head;
    }
    TreeNode *PriorityInsert(TreeNode *head, string name, string price, int id, string description, int priority)
    {
        if (head == NULL)
        {
            TreeNode *newNode = new TreeNode(name, price, id, description, priority);
            return newNode;
        }

        if (priority < head->item_priority2)
            head->left = PriorityInsert(head->left, name, price, id, description, priority);
        else if (priority >= head->item_priority2)
            head->right = PriorityInsert(head->right, name, price, id, description, priority);
        return head;
    }

    TreeNode *searcchinBst(TreeNode *root, int val)
    {
        if (root == NULL)

            return NULL;
        if (root->item_id2 == val)
            return root;
        else if (root->item_id2 > val)
        {
            return searcchinBst(root->left, val);
        }
        else
        {
            return searcchinBst(root->right, val);
        }
    }
    TreeNode *UpdatePrice(TreeNode *root, string price, int id)
    {
        if (root == NULL)

            return NULL;
        if (root->item_id2 == id)
        {
            root->price2 = price;
            return root;
        }
        else if (root->item_id2 > id)
        {
            return UpdatePrice(root->left, price, id);
        }
        else
        {
            return UpdatePrice(root->right, price, id);
        }
    }

    int InsertInBst(TreeNode *parent, string name, string price, int id, string description, int priority)
    {
        int val = 0;
        TreeNode *previous = NULL;
        while (parent != NULL)
        {
            previous = parent;
            if (id == parent->item_id2)
            {
                val = -1;
                return val;
            }
            else if (id < parent->item_id2)
            {
                parent = parent->left;
            }
            else
            {
                parent = parent->right;
            }
        }
        TreeNode *new_node = new TreeNode(name, price, id, description, priority);
        if (id < previous->item_id2)
        {
            previous->left = new_node;
            return val;
        }
        else
        {
            previous->right = new_node;
            return val;
        }
    }

    TreeNode *successor(TreeNode *root)
    {
        TreeNode *current = root;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteInBSt(TreeNode *root, int key)
    {
        if (key < root->item_id2)
        {
            root->left = deleteInBSt(root->left, key);
        }
        else if (key > root->item_id2)
        {
            root->right = deleteInBSt(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                free(root);
                return temp;
            }
            TreeNode *temp = successor(root->right);
            root->item_id2 = temp->item_id2;
            root->right = deleteInBSt(root->right, temp->item_id2);
        }
        return root;
    }

    void InOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            InOrder(root->left);
            cout << setw(20) << left << root->name2;
            cout << setw(20) << left << root->price2;
            cout << setw(20) << left << root->item_id2;
            cout << setw(20) << left << root->manufacturer2;
            cout << setw(20) << left << root->item_priority2 << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            InOrder(root->right);
        }
    }
};
void inOrderTraversal(TreeNode *root, ofstream &file)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, file);
    file << root->name2 << "," << root->price2 << "," << root->item_id2 << "," << root->manufacturer2 << "," << root->item_priority2 << endl;
    inOrderTraversal(root->right, file);
}
void writeTreeToCSV(TreeNode *root, string fileName)
{

    ofstream file(fileName, ios::out | ios::trunc);

    if (!file.is_open())
    {
        cout << "Error opening file " << fileName << endl;
        return;
    }

    file << "name,price,id,description,priority" << endl;

    inOrderTraversal(root, file);

    file.close();
}
