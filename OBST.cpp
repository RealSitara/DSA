/*
Given sequence k = k1 &lt;k2 &lt; … &lt;kn of n sorted keys, with a search probability pi for
each key ki . Build the Binary search tree that has the least search cost given the access
probability for each key?
*/
#include <iostream>
using namespace std;

void con_obst();
void print(int, int);

float a[20], b[20], wt[20][20], c[20][20];
int r[20][20], n;
int keys[20];

int main()
{
    cout << "\n****** PROGRAM FOR OBST ******\n";
    cout << "\nEnter the number of nodes: ";
    cin >> n;

    cout << "\nEnter the keys for each node:\n";
    cout << "----------------------------------------------\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Key[" << i << "]: ";
        cin >> keys[i];
    }

    cout << "\nEnter the probability for successful search:\n";
    cout << "----------------------------------------------\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "p[" << i << "]: ";
        cin >> a[i];
    }

    cout << "\nEnter the probability for unsuccessful search:\n";
    cout << "----------------------------------------------\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "q[" << i << "]: ";
        cin >> b[i];
    }

    con_obst();
    print(0, n);
    cout << endl;

    return 0;
}

void con_obst()
{
    for (int i = 0; i < n; i++)
    {
        c[i][i] = 0.0;
        r[i][i] = 0;
        wt[i][i] = b[i];

        wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        c[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        r[i][i + 1] = i + 1;
    }
    c[n][n] = 0.0;
    r[n][n] = 0;
    wt[n][n] = b[n];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            wt[j][j + i] = b[j + i] + a[j + i] + wt[j][j + i - 1];
            c[j][j + i] = 9999;
            for (int l = j + 1; l <= j + i; l++)
            {
                if (c[j][j + i] > (c[j][l - 1] + c[l][j + i]))
                {
                    c[j][j + i] = c[j][l - 1] + c[l][j + i];
                    r[j][j + i] = l;
                }
            }
            c[j][j + i] += wt[j][j + i];
        }
    }

    cout << "\n\nOptimal BST is:";
    cout << "\nw[0][" << n << "]: " << wt[0][n];
    cout << "\nc[0][" << n << "]: " << c[0][n];
    cout << "\nr[0][" << n << "]: " << r[0][n];
    cout<<"\nRoot Node is : "<<keys[r[0][n]];
}

void print(int i, int j)
{
    if (i >= j)
        return;

    if (r[i][r[i][j] - 1] != 0)
        cout << "\nLeft child of " << keys[r[i][j]] << ": " << keys[r[i][r[i][j] - 1]];

    if (r[r[i][j]][j] != 0)
        cout << "\nRight child of " << keys[r[i][j]] << ": " << keys[r[r[i][j]][j]];

    print(i, r[i][j] - 1);
    print(r[i][j], j);
}
