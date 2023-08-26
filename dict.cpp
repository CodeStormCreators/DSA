#include <bits/stdc++.h>
using namespace std;

struct node
{
    char value[20];
    char meaning[20];
    node *left;
    node *right;
};

class dict
{
public:
    node *root;
    dict()
    {
        root = NULL;
    }
    void create();
    void insert(node *root, node *temp);
    void display(node *root);
    int update(node *root, char v[]);
    int search(node *root, char v[]);
    node *del(node *root, char v[]);
    node *min(node *root);
};

void dict ::create()
{
    char ch;
    node *temp;
    do
    {
        temp = new node;
        cout << "Enter value : ";
        cin >> temp->value;
        cout << "Enter meaning : ";
        cin >> temp->meaning;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }
        cout << "Do you want to add more : ";
        cin >> ch;
    } while (ch == 'y');
}

void dict::insert(node *root, node *temp)
{
    if (strcmp(temp->value, root->value) < 0)
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
}

void dict::display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << "Value : " << root->value << endl;
        cout << "Meaning : " << root->meaning << endl;
        display(root->right);
    }
}

int dict::update(node *root, char v[20])
{
    while (root != NULL)
    {
        if (strcmp(v, root->value) == 0)
        {
            cout << "Key found...";
            cout << "Enter new meaning for " << root->value;
            cin >> root->meaning;
            return 1;
        }
        else if (strcmp(v, root->value) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return -1;
}

int dict::search(node *root, char v[20])
{
    int c = 0;
    while (root != NULL)
    {
        c++;
        if (strcmp(v, root->value) == 0)
        {
            cout << "Key found...";
            cout << "No of comparission : " << c;
            return 1;
        }
        else if (strcmp(v, root->value) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return -1;
}

node *dict::del(node *root, char v[20])
{
    node *temp;
    if (root == NULL)
    {
        cout << "Element not found...";
        return root;
    }
    if (strcmp(v, root->value) < 0)
    {
        root->left = del(root->left, v);
        return root;
    }
    if (strcmp(v, root->value) > 0)
    {
        root->right = del(root->right, v);
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        temp = root;
        delete temp;
        root = NULL;
    }
    else if (root->left == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }
    else if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    temp = min(root->right);
    strcpy(root->value, temp->value);
    root->right = del(root->right, temp->value);
    return root;
}

node *dict::min(node *q)
{
    while (q->left != NULL)
    {
        q = q->left;
    }
    return q;
}

int main()
{
    int ch;
    char ch1;
    dict d;
    do
    {
        cout << "1)Create\n2)Display\n3)Search\n4)Update\n5)Delete\n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL)
            {
                cout << "No any keyward : ";
            }
            else
            {
                d.display(d.root);
            }
            break;
        case 3:
            if (d.root == NULL)
            {
                cout << "Empty dictionary : " << endl;
            }
            else
            {
                char n[10];
                cout << "Enter keyward that you want to search :";
                cin >> n;
                if (d.search(d.root, n) == 1)
                {
                    cout << "Keyward found : " << endl;
                }
                else
                {
                    cout << "Keyward not found : " << endl;
                }
            }
            break;
        case 4:
            if (d.root == NULL)
            {
                cout << "Empty dictionary : " << endl;
            }
            else
            {
                char n[10];
                cout << "Enter keyward that you want to update : ";
                cin >> n;
                if (d.update(d.root, n) == 1)
                {
                    cout << "Meaning updated : " << endl;
                }
                else
                {
                    cout << "Keyward not found :" << endl;
                }
            }
            break;
        case 5:
            if (d.root == NULL)
            {
                cout << "Empty dictionary : " << endl;
            }
            else
            {
                char n[10];
                cout << "Enter keyward that you want to delete : ";
                cin >> n;
                if (d.root == NULL)
                {
                    cout << "Dictionary is empty : ";
                }
                else
                {
                    d.root = d.del(d.root, n);
                }
            }
            break;
        default:
            cout << "Invalid choice : " << endl;
            break;
        }
        cout << "Do you want to continue (y/n) : ";
        cin >> ch1;
    } while (ch1 == 'y'||ch1=='Y');
    return 0;
}