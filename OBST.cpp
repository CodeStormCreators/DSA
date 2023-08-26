#include <bits/stdc++.h>
using namespace std;
#define size 10

char ident[size][size];
int p[size], q[size], n, w[size][size], c[size][size], r[size][size], x;

int find(int a, int b)
{
    int min = INT_MAX;
    for (x = a + 1; x <= b; x++)
    {
        int z = c[a][x - 1] + c[x][b];
        if (z < min)
        {
            min = z;
            int l = x;
        }
    }
    return x;
}

void display(int a, int b)
{
    if (a < b)
    {
        cout << ident[r[a][b]] << " ";
    }
    else
    {
        return;
    }
    display(a, r[a][b] - 1);
    display(r[a][b], b);
}

int main()
{
    cout << "No. of entries tou want to take : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter identifier : ";
        cin >> ident[i];
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter success probability : ";
        cin >> p[i];
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << "Enter failuare probability : ";
        cin >> q[i];
    }
    cout << endl;
    cout << "\tLevel-0\n";
    cout << "WEIGHT\tCOST\tROOT" << endl;
    for (int k = 0; k <= n; k++)
    {
        w[k][k] = q[k];
        c[k][k] = r[k][k] = 0;
        cout << w[k][k] << "\t" << c[k][k] << "\t" << r[k][k] << endl;
    }
    cout << "\tLevel-1\n";
    cout << "WEIGHT\tCOST\tROOT" << endl;
    for (int k = 0; k < n; k++)
    {
        int j = k + 1;
        w[k][j] = w[k][k] + p[j] + q[j];
        c[k][j] = w[k][k] + c[k][k] + c[j][j];
        r[k][j] = j;
        cout << w[k][j] << "\t" << c[k][j] << "\t" << r[k][j] << endl;
    }
    for (int i = 2; i <= n; i++)
    {
        cout << "\tLevel-" << i << "\n";
        cout << "WEIGHT\tCOST\tROOT" << endl;
        for (int k = 0; k < n - i; k++)
        {
            int j = k + i;
            w[k][j] = w[k][j - 1] + p[j] + q[j];
            int q = find(k, j);
            r[k][j] = q;
            c[k][j] = w[k][j] + c[k][q - 1] + c[q][j];
            cout << w[k][j] << "\t" << c[k][j] << "\t" << r[k][j] << endl;
        }
    }
    cout << "Final obst is : " << endl;
    display(0, n);
}