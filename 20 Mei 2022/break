#include <iostream>
using namespace std;

struct mobil_tol
{
    int urutan;
    int muatan;
    string merk;
    string kodeDaerah;
};

int main()
{
    mobil_tol mobil[] =
        {
            {1,
             1,
             "Kijang",
             "B"},
            {2,
             4,
             "Jazz",
             "D"},
            {3,
             2,
             "BMW",
             "Z"},
            {4,
             2,
             "Ayla",
             "D"},
            {5,
             6,
             "Inova",
             "B"},
            {6,
             2,
             "Daihatsu",
             "Z"}};

    for (int i = 0; i < 6; i++)
    {
        if (mobil[i].muatan > 4)
        {
            cout << "mobil merk " << mobil[i].merk << " dengan kode daerah " << mobil[i].kodeDaerah << " dengan muatan sebanyak " << mobil[i].muatan << " orang, dilarang melintas" << endl;
            break;
        }

        cout << "mobil merk " << mobil[i].merk << " dengan kode daerah " << mobil[i].kodeDaerah << " dengan muatan sebanyak " << mobil[i].muatan << " orang, diizinkan melintas" << endl;
    }
}
