#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main(){
    /*
    RULES
    1. lane (able)
    2. ambush (able/hide)
    3. puddle (able)
    4. tree (disable)
    5. stone (disable)
    6. waters (able || random 0,0 - 1,0 || trap = < 0,2)
    RULES TILE
    1. true jika ada di 1, 2, 3, 6
    DESAIN DATA
    MATRIKS LINGKUNGAN
    POSISI KARAKTER
    */
    
    int panjangMap = 10;    //x
    int lebarMap = 10;      //y
    
    int koorCharY = 0;
    int koorCharX = 0;
    
    cout << "karakter berada di (" << koorCharY << ", " << koorCharX << ")" << endl;
    
    int map[lebarMap][panjangMap] = {
        {1,1,1,1,1,2,2,1,6,4},
        {4,4,4,1,2,2,2,6,6,4},
        {4,4,2,1,1,5,6,6,6,4},
        {1,1,1,1,6,6,6,6,2,2},
        {5,5,5,1,6,6,1,1,5,5},
        {5,5,2,1,1,1,1,1,4,4},
        {4,4,2,2,2,1,1,2,2,2},
        {4,5,1,1,1,1,2,2,2,4},
        {4,4,6,6,6,1,1,3,3,3},
        {1,1,1,5,5,2,3,3,3,3},
        {1,1,5,5,5,5,2,3,3,3},
    };
    
    int arrowKey = 0;
    while (1){
        
        // Input arrow key
        cout << "Masukkan arrow key :";
        cin >> arrowKey;
        
        // Bergerak ke atas
        if (arrowKey == 72 && (map[koorCharY-1][koorCharX] == 1 || map[koorCharY-1][koorCharX] == 4) && koorCharY >= 0){
            koorCharY = koorCharY-1;
        }
        // Bergerak ke bawah
        if (arrowKey == 80 && (map[koorCharY+1][koorCharX] == 1 || map[koorCharY+1][koorCharX] == 4) && koorCharY < lebarMap){
            koorCharY = koorCharY+1;
        }
        // Bergerak ke kiri
        if (arrowKey == 75 && (map[koorCharY][koorCharX-1] == 1 || map[koorCharY][koorCharX-1] == 4) && koorCharY >= 0){
            koorCharX = koorCharX-1;
        }
        // Bergerak ke kanan
        if (arrowKey == 72 && (map[koorCharY][koorCharX+1] == 1 || map[koorCharY][koorCharX+1] == 4) && koorCharY < panjangMap){
            koorCharX = koorCharX+1;
        }
        
        // Render
        for(int y=0; y<lebarMap; y++){
            for(int x=0; x<panjangMap; x++){
                if (koorCharX == x && koorCharY == y){
                    cout << 0 << " ";
                }
                else {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}