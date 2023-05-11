#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

int max(int a, int b) { return (a > b) ? a : b; }

int cutRod(std::vector<int>& price, int n)
{
    std::vector<int> val(n + 1);
    val[0] = 0;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (j = 0; j < i; j++)
            max_val = std::max(max_val, price[j] + val[i - j - 1]);
        val[i] = max_val;
    }

    return val[n];
}

int main()
{
    std::ifstream file("in/cr.in");
    std::ofstream file2("out/cr.out");

    int n;
    file >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        file >> arr[i];
    }

    file.close();

    file2 << "Maximum Obtainable Value is " << cutRod(arr, n);

    file2.close();
    return 0;
}
