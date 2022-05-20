#include <iostream>
#include <cstdlib>
using namespace std;

//! TIM BASKET A
struct teamA_t {
    int nopung;
    int height;
    string name;
    string position;
    string signatureMoves;
};

int main (){
    int idealHeight = 170;
    teamA_t teamA[] = {
        {10, 180, "Biboy", "Shooter", "3 Point Shoot"},
        {7, 169, "Kun", "Playmaker", "Floater"},
        {0, 192, "Cloe", "Center", "Hook Shoot"},
        {16, 176, "Kei", "Small Forward", "Double Clutch"},
        {22, 181, "Ridi", "Power Forward", "Posterize"}
    };

    for (int i = 0; i < 5; i++){
        if (teamA[i].height < idealHeight ){
            continue;
        }
        cout << teamA[i].name << " dari posisi " << teamA[i].position 
        << " berhasil mencetak point dengan kemampuan "
        << teamA[i].signatureMoves << " andalannya " << endl
        << "====================================" << endl;
    }
    cout << "Namun sayang " << teamA[1].name << " dengan nomor punggung " 
    << teamA[1].nopung << " gagal menyumbang point" << endl;
}
