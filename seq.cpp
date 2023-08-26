#include <bits/stdc++.h>
using namespace std;

class student_data
{
    typedef struct stud1
    {
        int roll;
        char name[20];
        char add[20];
        char div;
    } stud1;
    stud1 s_obj;

public:
    void create();
    void display();
    void del();
    int search();
};

void student_data::create()
{
    char ch;
    ofstream w_obj;
    w_obj.open("student.txt", ios::out | ios::binary);
    do
    {
        cout << "Enter roll no of student : ";
        cin >> s_obj.roll;
        cout << "Enter name of student : ";
        cin >> s_obj.name;
        cout << "Enter add of student : ";
        cin >> s_obj.add;
        cout << "Enter division of student : ";
        cin >> s_obj.div;
        w_obj.write((char *)&s_obj, sizeof(stud1));

        cout << "Do you want to continue(y/n) : ";
        cin >> ch;
    } while (ch == 'y'||ch=='Y');
    w_obj.close();
}

void student_data::display()
{
    ifstream r_obj;
    r_obj.open("student.txt", ios::in | ios::binary);
    r_obj.seekg(0, ios::beg);
    
    cout << "ROLL\tNAME\tDIV\tADD" << endl;
    while (r_obj.read((char *)&s_obj, sizeof(stud1)))
    {
        if (s_obj.roll != -1)
        {
            cout << s_obj.roll << "\t" << s_obj.name << "\t" << s_obj.div << "\t" << s_obj.add << endl;
        }
    }
    r_obj.close();
}
int student_data::search()
{
    int r, i = 0;
    ifstream r_obj;
    r_obj.open("student.txt", ios::in | ios::binary);
    r_obj.seekg(0, ios::beg);

    cout << "Enter roll no which you want to search : ";
    cin >> r;

    while (r_obj.read((char *)&s_obj, sizeof(stud1)))
    {
        if (s_obj.roll == r)
        {
            cout << "Entry found...." << endl;
            cout << s_obj.roll << "\t" << s_obj.name << "\t" << s_obj.div << "\t" << s_obj.add << endl;
            return i;
        }
        i++;
    }
    r_obj.close();
    return 0;
}
void student_data::del()
{
    fstream f_obj;
    f_obj.open("student.txt", ios::in | ios::out | ios::binary);
    f_obj.seekg(0, ios::beg);
    
    int pos = search();
    if (pos == 0)
    {
        cout << "Roll no not found..." << endl;
        return;
    }
    int real = pos * sizeof(stud1);
    f_obj.seekp(real);

    s_obj.roll = -1;
    strcpy(s_obj.name, "NULL");
    strcpy(s_obj.add, "NULL");
    s_obj.div = 'N';

    f_obj.write((char *)&s_obj, sizeof(stud1));
    cout << "Entry deleted...." << endl;
    f_obj.seekg(0, ios::beg);
    f_obj.close();
}
int main()
{
    student_data o;
    char ch;
    int ch1,x;
    do
    {
        cout << "1)Create\n2)Display\n3)Search\n4)Delete\n5)Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            o.create();
            break;
        case 2:
            o.display();
            break;
        case 3:
            x = o.search();
            if (x == 0)
            {
                cout << "Roll no not found..." << endl;
            }
            break;
        case 4:
            o.del();
            break;
        case 5:
            break;
        }
        cout << "Do you want to continue (y/n) : ";
        cin >> ch;
    } while (ch == 'y'|| ch=='Y');
}