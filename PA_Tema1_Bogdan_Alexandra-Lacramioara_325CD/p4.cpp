#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#define MAX_N 1000
#define MAX_L 1000

char C[MAX_N][MAX_L];
int X[MAX_N], P[MAX_N];
int n, m;
std::ofstream file2;

void afisare()
{
    for (int i = 1; i <= n; i++)
        file2 << C[X[i]] << " ";
    file2 << "\n";
}

int fazan(const char x[], const char y[])
{
    if (x[strlen(x) - 2] == y[0] &&
        x[strlen(x) - 1] == y[1])
        return 1;
    else
        return 0;
}

void back(int k)
{
    if (k > m)
    {
        afisare();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!P[i])
        {
            X[k] = i;
            P[i] = 1;
            if (k == 1 || fazan(C[X[k - 1]], C[X[k]]))
                back(k + 1);
            P[i] = 0;
        }
    }
}

int main()
{
    std::ifstream fin("in/fazan.in");
    file2.open("out/fazan.out");
    if (!fin.is_open() || !file2.is_open())
    {
        std::cout << "Error opening input/output files.\n";
        return 1;
    }

    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> C[i];

    fin.close();

    back(1);

    file2.close();

    return 0;
}
