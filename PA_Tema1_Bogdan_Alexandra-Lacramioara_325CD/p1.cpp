#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

void minmax(int v[], int st, int dr, int& min, int& max)
{
    if (st == dr)
    {
        min = max = v[st];
    }
    else
    {
        int a_min, a_max, b_min, b_max;
        int m = (st + dr) / 2;

        minmax(v, st, m, a_min, a_max);
        minmax(v, m + 1, dr, b_min, b_max);

        min = (a_min < b_min) ? a_min : b_min;
        max = (a_max > b_max) ? a_max : b_max;
    }
}

int main()
{
    int v[10000];
    int n;
    std::ifstream fin("in/minmax.in"); // se deschide fișierul de intrare
    std::ofstream fout("out/minmax.out"); // se deschide fișierul de ieșire

    if (!fin || !fout)
    {
        std::cout << "Eroare la deschiderea fisierului input/output\n";
        return 1;
    }

    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> v[i];
    }
    fin.close();

    int min, max;
    minmax(v, 0, n - 1, min, max);

    fout << min << " " << max;
    fout.close();

    return 0;
}
