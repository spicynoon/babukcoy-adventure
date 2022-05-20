#include <iostream>
#include <math.h>
using namespace std;

void header()
{
    cout << " ____________________________________________________ " << endl;
    cout << "|                                                    |" << endl;
    cout << "|                      MENU UTAMA                    |" << endl;
    cout << "|               =YANDIYAN  (1217050144)=             |" << endl;
    cout << "|____________________________________________________|" << endl;
}

int main()
{
    int accessCode;
    do
    {
        header();
        cout << "1 = Membuat Segitiga\n2 = Bilangan Prima\n3 = Kalkulator Faktorial\n0 = Keluar Program\n";
        cout << "===============================\n\n";
        cout << "Input Code: ";
        cin >> accessCode;

        if (accessCode == 1)
        {
            int n;
            char s;

            header();
            cout << " INPUT TINGGI : ";
            cin >> n;
            cout << " INPUT SYMBOL : ";
            cin >> s;

            for (int i = 1; i <= n; i++)
            {
                for (int j = n; j > i; j--)
                {
                    cout << " ";
                }
                for (int k = 1; k <= (2 * i - 1); k++)
                {
                    cout << s;
                }
                cout << endl;
            }
        }
        else if (accessCode == 2)
        {
            int limitNum, realNum;
            bool primeNum = true;

            cout << "INPUT BATAS BILANGAN PRIMA : ";
            cin >> limitNum;

            for (realNum = 2; realNum <= limitNum; realNum++)
            {
                for (int i = 2; i < realNum; i++)
                {
                    primeNum = true;
                    if (realNum % i == 0)
                    {
                        primeNum = false;
                        break;
                    }
                }
                if (primeNum == true)
                {
                    cout << realNum << " ";
                }
            }
        }
        else if (accessCode == 3)
        {
            int facNum;
            cout << "MASUKAN BILANGAN FAKTORIAL : ";
            cin >> facNum;
            for (long Number = 1; Number <= facNum; Number++)
            {
                // Outer loop
                long Factorial = 1;
                for (long Count = 1; Count <= Number; Count++)
                {
                    // Inner loop
                    Factorial *= Count;
                }
                cout << " Number = " << Number
                     << " Factorial = " << Factorial << endl;
            }
        }
        else if (accessCode == 0)
        {
            cout << "Keluar Program";
        }
        else
        {
            cout << "Invalid code ! Please try again";
        }
        cout << endl;
    } while (accessCode != 0);

    return 0;
}