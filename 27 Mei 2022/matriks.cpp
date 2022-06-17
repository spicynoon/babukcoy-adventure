#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100

struct character
{
    string name;
    int hp;
    int damage;

    void basicAttack(character *hit){
        int hpFrom = hit->hp;
		cout << name << " attacking " << hit->name << " ! " << endl;
		hit->hp = hit->hp - rand() %damage;
		cout << hit->name << "'s hp drop from " 
        << hpFrom << " to " << hit->hp << endl;
    }
};

struct equipment
{
    string name;
    string type;
    int armorBuffeffect;
    int attackBuffeffect;
};

//function colored output
void setcolor(unsigned short color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,color);
}

int main(){
    
    /*
    RULES
    1. lane (able)
    2. ambush (able || random find enemy 15%)
    3. puddle (able || random find item 10%)
    4. tree (disable)
    5. stone (disable)
    6. waters (able || random find item 10%)
    RULES TILE
    1. true jika ada di 1, 2, 3, 6
    DESAIN DATA
    MATRIKS LINGKUNGAN
    POSISI KARAKTER
    */

    character hero[] = {
        {"Alu", 1200, 300}, 
        {"Eudo", 800, 300},
        {"Mino", 1700, 300},
        {"Miya", 1000, 300},
        {"Ling", 900, 300},
    };

    character monster[] = {
        {"Goblin", 500, 80},
        {"Mosswine", 480, 45},
        {"Vespoid", 800, 120},
        {"Cephadrome", 1200, 400},
        {"Rathanos", 2000, 585},
        {"Rathanias", 2000, 585}
    };

    equipment item[] = {
        {"Tameng", "Armor", 200, 5}, 
        {"Kujang", "Attack", 5, 125},
        {"Zirah", "Armor", 500, 10},
        {"Keling", "Attack", 0, 75,},
        {"Trisula", "Attack", 10, 250},
    };

    int panjangMap = 10;    //x
    int lebarMap = 10;      //y
    
    int koorCharY = 0;
    int koorCharX = 0;

    
    cout << "'mobile legend x pokemon' lite game" << endl;
    setcolor(4);
    cout << "===========================" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << hero[i].name << endl;
    }
    cout << "===========================" << endl;
    cout << "choose ur character : ";
    
    // menyimpan nilai karakter yang dipilih
    int selected;
    cin >> selected;
    selected--;

    // properti my character
    // string myCharacter = character[selectedCharacter].name;
    // int hpMyCharacter = character[selectedCharacter].hp;
    // int damageMyCharacter = character[selectedCharacter].damage;
    
    // menampilkan karakter yang dipilih
    cout << "u choose " << hero[selected].name << endl; 
    setcolor(7);

    // game start
    cout << "====================" << endl;
    cout << "ready to start !!" << endl;
    cout << "u spawn at (" << koorCharY << ", " << koorCharX << ")" << endl
    << "use w,a,s,d to move" << endl;
    
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
        cout << "input arrow key :";
        arrowKey = (getch()); 
        cout << endl;
        
        // Bergerak ke atas
        if (arrowKey == 119 && (map[koorCharY-1][koorCharX] == 1 || 
                                map[koorCharY-1][koorCharX] == 2 ||
                                map[koorCharY-1][koorCharX] == 3 ||
                                map[koorCharY-1][koorCharX] == 6
                                ) && koorCharY >= 0){
            koorCharY = koorCharY-1;
        }
        // Bergerak ke bawah
        if (arrowKey == 115 && (map[koorCharY+1][koorCharX] == 1 ||
                                map[koorCharY+1][koorCharX] == 2 ||
                                map[koorCharY+1][koorCharX] == 3 ||
                                map[koorCharY+1][koorCharX] == 6
                                ) && koorCharY < lebarMap){
            koorCharY = koorCharY+1;
        }
        // Bergerak ke kiri
        if (arrowKey == 97 && (map[koorCharY][koorCharX-1] == 1 ||
                               map[koorCharY][koorCharX-1] == 2 ||
                               map[koorCharY][koorCharX-1] == 3 ||
                               map[koorCharY][koorCharX-1] == 6
                               ) && koorCharY >= 0){
            koorCharX = koorCharX-1;
        }
        // Bergerak ke kanan
        if (arrowKey == 100 && (map[koorCharY][koorCharX+1] == 1 ||
                                map[koorCharY][koorCharX+1] == 2 ||
                                map[koorCharY][koorCharX+1] == 3 ||
                                map[koorCharY][koorCharX+1] == 6
                                ) && koorCharY < panjangMap){
            koorCharX = koorCharX+1;
        }
        system ("CLS");

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

        //Random trap and enemy
        int characterPosition=map[koorCharY][koorCharX];
        int i = rand() %4;
        if (characterPosition==2)
        {
            int probabilityFindEnemy;
            srand (time(NULL));
            probabilityFindEnemy = rand() %15;

            // kemungkinan bertemu musuh
            if (probabilityFindEnemy<3)
            {
                setcolor(4);
                cout 
                << "======================" << endl
                << "u find the enemy" << endl
                << "ready to fight bruh !!" << endl
                << "======================" << endl
                << "fight (1) or run (2) : "; 
                
                int fightOrRun;
                cin >> fightOrRun;
                
                // make decision bertarung atau kabur
                if (fightOrRun == 1)
                {
                    cout 
                    << "u will fight them !!" << endl
                    << "ready to fight !!" << endl;
                    setcolor(6);
                    cout << hero[selected].name << " vs " << hero[i].name << endl;
                    
                    do
                    {
                        hero[selected].basicAttack(&hero[i]);
                        hero[i].basicAttack(&hero[selected]);
                    } while (hero[selected].hp == 0 || hero[i].hp ==0);
                    setcolor(4);
                }
                else if (fightOrRun > 1)
                {
                    cout 
                    << "run bestieee runnnn !!" << endl
                    << "kukira adu mekanik ternyata panik" << endl;
                    setcolor(6);
                    cout << hero[selected].name << " run away" << endl;
                }
                setcolor(7);
            }
        }

        //kemungkinan mendapat item 
        if (characterPosition==3 || characterPosition==6)
        {
            int probabilityFoundItem;
            srand (time(NULL));
            probabilityFoundItem = rand() %10;

            if (probabilityFoundItem<2)
            {
                setcolor(4);
                cout 
                << "==============================" << endl
                << "u found item " << item[i].name << endl
                << "==============================" << endl
                << "take it (1) or leave it (2) : ";
                
                int takeOrLeave;
                cin >> takeOrLeave;
                
                // make decision bertarung atau kabur
                if (takeOrLeave == 1)
                {
                    setcolor(6);
                    cout 
                    << item[i].name << " saved" << endl
                    << "Type   : " << item[i].type << endl
                    << "Armor  : " << item[i].armorBuffeffect << endl
                    << "Damage : " << item[i].attackBuffeffect << endl;
                    setcolor(7);
                }
                else if (takeOrLeave > 1)
                setcolor(7);
            }
        }
    }
    return 0;
}
