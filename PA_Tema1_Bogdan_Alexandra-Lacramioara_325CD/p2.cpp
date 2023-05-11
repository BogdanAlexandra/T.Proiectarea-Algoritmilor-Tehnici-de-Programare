#include <iostream>
#include <fstream>

std::ofstream file2;

void egyptianFraction(int n, int d)
{
    if (d == 0 || n == 0)
        return;
    if (d % n == 0) {
        file2 << "1/" << d / n;
        return;
    }
    if (n % d == 0) {
        file2 << n / d;
        return;
    }
    if (n > d) {
        file2 << n / d << " + ";
        egyptianFraction(n % d, d);
        return;
    }
    int x = d / n + 1;
    file2 << "1/" << x << " + ";
    egyptianFraction(n * x - d, d * x);
}

int main()
{
    int numerator, denominator;
    std::ifstream file1("in/ef.in");
    file2.open("out/ef.out");
    if (!file1 || !file2) {
        std::cout << "Error opening input/output file" << std::endl;
        return 1;
    }

    // Read numerator and denominator from file
    if (!(file1 >> numerator >> denominator)) {
        std::cout << "Error reading from file" << std::endl;
        file1.close();
        file2.close();
        return 1;
    }

    file1.close();

    file2 << "Egyptian Fraction representation of " << numerator << "/" << denominator << " is" << std::endl;
    egyptianFraction(numerator, denominator);
    file2.close();
    return 0;
}
