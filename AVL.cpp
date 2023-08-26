#include <iostream>
using namespace std;

class node
{
public:
    string key;
    string meaning;
    node *left;
    node *right;
};

class AVL
{
    node *root;

public:
    AVL()
    {
        root = NULL;
    }

    void create();
    node *insert(node *root, node *temp);
    node *balance(node *root);
    int dif(node *temp);
    int height(node *temp);
    int maximum(int a, int b);

    void ascending(node *temp);
    void descending(node *temp);
    void display();
    bool search(node *root, string key1);
    void search_value();
    node *delete_n(node *root, string key1);
    void deleten();
    node *extractmin(node *temp);

    node *LL(node *par);
    node *RR(node *par);
    node *LR(node *par);
    node *RL(node *par);
};

void AVL::create()
{
    node *temp;
    char ans;
    do
    {
        temp = new node();
        cout << "enter a keyward : ";
        cin >> temp->key;
        cout << "enter the meaning : ";
        cin >> temp->meaning;
        temp->left = temp->right = NULL;

        root = insert(root, temp);

        cout << "do you want to add more(Y/N) : ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

node *AVL::insert(node *root, node *temp)
{
    if (root == NULL)
    {
        return temp;
    }
    if (temp->key < root->key)
    {
        root->left = insert(root->left, temp);
        root = balance(root);
    }
    else if (temp->key >= root->key)
    {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

node *AVL::balance(node *root)
{
    int bal = dif(root);
    if (bal >= 2)
    {
        if (dif(root->left) < 0)
        {
            root = LR(root);
        }
        else
        {
            root = LL(root);
        }
    }
    else if (bal <= -2)
    {
        if (dif(root->right) < 0)
        {
            root = RR(root);
        }
        else
        {
            root = RL(root);
        }
    }
    return root;
}

int AVL::dif(node *temp)
{
    int l = height(temp->left);
    int r = height(temp->right);
    return l - r;
}

int AVL::height(node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        return (maximum(height(temp->left), height(temp->right)));
    }
}

int AVL::maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

node *AVL::LL(node *par)
{
    node *temp, *temp1;
    temp = par->left;
    temp1 = temp->right;
    temp->right = par;
    par->left = temp1;
    return temp;
}

node *AVL::RR(node *par)
{
    node *temp, *temp1;
    temp = par->right;
    temp1 = temp->left;
    temp->left = par;
    par->right = temp1;
    return temp;
}

node *AVL::RL(node *par)
{
    par->right = LL(par->right);
    return (RR(par));
}

node *AVL::LR(node *par)
{
    par->left = RR(par->left);
    return (LL(par));
}

void AVL::ascending(node *temp)
{
    if (temp != NULL)
    {
        ascending(temp->left);
        cout << "\t" << temp->key << " : " << temp->meaning <<endl;
        ascending(temp->right);
    }
}

void AVL::descending(node *temp)
{
    if (temp != NULL)
    {
        descending(temp->right);
        cout << "\t" << temp->key << " : " << temp->meaning << endl;
        descending(temp->left);
    }
}

void AVL::display()
{
    cout << "The keywards in ascending order are : " << endl;
    ascending(root);
    cout << "The keywards in descending order are : " << endl;
    descending(root);
}

bool AVL::search(node *root, string key1)
{
    if (root != NULL)
    {
        if (root->key == key1)
        {
            return true;
        }
        else if (root ->key > key1)
        {
            return search(root->left, key1);
        }
        else
        {
            return search(root->right, key1);
        }
    }
    return false;
}

void AVL::search_value()
{
    string key2;
    cout << "enter keyward that you wish to search : ";
    cin >> key2;
    if (search(root, key2))
    {
        cout << "Entered keyward is present in AVL tree..."<<endl;
    }
    else 
    {
        cout << "Entered keyward is not present in AVL tree..."<<endl;
    }
}

node *AVL::delete_n(node *root, string key1)
{
    if (search(root, key1))
    {
        if (key1 < root->key)
        {
            root->left = delete_n(root->left, key1);
        }
        else if (key1 > root->key)
        {
            root->right = delete_n(root->right, key1);
        }
        else
        {
            node *l = root->left;
            node *r = root->right;
            delete root;
            if (r == NULL)
            {
                return l;
            }
            node *m = r;
            while (m->left != NULL)
            {
                m = m->left;
            }
            m->right = extractmin(r);
            m->left = l;
            return balance(m);
        }
        cout<<"Your key is deleted..."<<endl;
        return balance(root);
    }
    else
    {
        cout << "key not found..." << endl;
        return balance(root);
    }
}

node *AVL::extractmin(node *temp)
{
    if (temp->left == NULL)
    {
        return temp->right;
    }
    temp->left = extractmin(temp->left);
    return balance(temp);
}

void AVL::deleten()
{
    string key2;
    cout << "Enter keywaard to be deleted : ";
    cin >> key2;
    root = delete_n(root, key2);
}

int main()
{
    int ch;
    char c;
    AVL obj;
    do
    {
        cout << "1)Insert keyward\n2)Display tree\n3)Search keyward\n4)Delete keyward" << endl;
        cout << "enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.search_value();
            break;
        case 4:
            obj.deleten();
            break;
        default:
            cout << "wrong choice..."<<endl;
            break;
        }
        cout << "Do you want to continue ? (Y/N) : ";
        cin >> c;
    } while (c == 'y' | c == 'Y');
    return 0;
}