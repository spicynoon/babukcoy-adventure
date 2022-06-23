#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "color.hpp"
using namespace std;

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define ENTER 13
#define ESC 27

void header()
{
    cout << "************************ " << endl;
    cout << "|| Babukcoy Adventure ||" << endl;
    cout << "||  -Beat The Enemy-  ||" << endl;
    cout << "|| -and Win The Game- ||" << endl;
    cout << "************************ " << endl;
};

struct character
{
    string name;
    int hp;
    int damage;
    int ulti;
    int armor;

    void basicAttack(character *hit)
    {
        int hpFrom = hit->hp;

        cout << dye::red(name) << " attacking " << dye::red(hit->name) << " ! " << endl;
        hit->hp = hit->hp - (damage + rand() % damage);
        if (hit->hp <= 0 || hpFrom <= 0)
        {
            hit->hp = 0;
            hpFrom = 0;
        }

        cout << dye::red(hit->name) << "'s hp drop from "
             << dye::red(hpFrom) << " to " << dye::red(hit->hp) << endl;

    }

    void ultimate(character *skill, int ultiRemain)
    {
        int counter = ultiRemain;

        if (ultiRemain > 0)
        {
            int hpFrom = skill->hp;

            cout << dye::red(name) << " ulti " << dye::red(skill->name) << " ! " << endl;
            cout << "total damage = " << dye::red(ulti) << " - " << dye::red(skill->armor) << endl;
            ulti = ulti - skill->armor;
            skill->hp = skill->hp - ulti;
            if (skill->hp <= 0 || hpFrom <= 0)
            {
                skill->hp = 0;
                hpFrom = 0;
            }
            
            cout << dye::red(skill->name) << "'s hp drop from "
                 << dye::red(hpFrom) << " to " << dye::red(skill->hp) << endl;

        }
    }
};

struct equipment
{
    string name;
    string type;
    int armorBuffeffect;
    int attackBuffeffect;
    int healEffect;
};

// function colored output
void setcolor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

int main()
{
    /*
    RULES
    1. lane (able)
    2. ambush (able || random find enemy 15%)
    3. puddle (able || random find item 10%)
    4. tree (disable)
    5. stone (disable)
    6. waters (able || random find potion 10%)
    7. barrier y (disable)
    8. barrier x (disable)
    RULES TILE
    1. true jika ada di 1, 2, 3, 6
    DESAIN DATA
    MATRIKS LINGKUNGAN
    POSISI KARAKTER
    */

    character hero[] = {
        {"Gruitz", 1200, 125, 365, 0},
        {"Mellowfaz", 900, 150, 395, 0},
        {"Kirigaya", 1300, 115, 300, 0},
        {"Smountar", 1100, 135, 350, 0},
        {"Ulqio", 1000, 145, 385, 0}};

    character monster[] = {
        {"Goblin", 500, 80, 100},
        {"Mosswine", 480, 45, 125},
        {"Vespoid", 800, 120, 215},
        {"Cephadrome", 1200, 400, 315},
        {"Rathanos", 2000, 585, 450},
        {"Rathanias", 2000, 585, 450}};

    equipment item[] = {
        {"Tameng", "Armor", 20, 5},
        {"Kujang", "Attack", 5, 25},
        {"Zirah", "Armor", 30, 10},
        {"Keling", "Attack", 5, 15},
        {"Trisula", "Attack", 10, 50}};

    equipment potion[] = {
        {"Energen", "Heal", 0, 0, 100},
        {"STMJ", "Heal", 0, 0, 200},
        {"Susu Beruang", "Heal", 0, 0, 300},
        {"Paracetamol", "Heal", 0, 0, 400}};

    int panjangMap = 12; // x
    int lebarMap = 10;   // y
    int koorCharY = 0;
    int koorCharX = 1;

    int map[lebarMap][panjangMap] = {
        {7, 1, 1, 1, 1, 1, 2, 2, 1, 6, 4, 7},
        {7, 4, 4, 4, 1, 2, 2, 2, 3, 6, 4, 7},
        {7, 4, 4, 2, 1, 1, 5, 6, 3, 3, 4, 7},
        {7, 1, 1, 1, 1, 6, 6, 6, 6, 2, 2, 7},
        {7, 5, 5, 5, 1, 6, 3, 1, 1, 5, 5, 7},
        {7, 5, 5, 2, 1, 1, 1, 1, 1, 4, 4, 7},
        {7, 4, 4, 2, 2, 2, 1, 1, 2, 2, 2, 7},
        {7, 4, 5, 1, 1, 1, 1, 2, 2, 2, 4, 7},
        {7, 4, 4, 6, 6, 6, 1, 1, 3, 3, 3, 7},
        {7, 1, 1, 1, 5, 5, 2, 3, 6, 6, 3, 7},
        {7, 1, 1, 5, 5, 5, 5, 2, 3, 6, 6, 7}};

    setcolor(4);
    header();

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << hero[i].name << endl;
    }
    setcolor(5);
    cout << endl
         << "choose ur character : ";

    // menyimpan nilai karakter yang dipilih
    int selected;
    cin >> selected;
    selected--;

    cout << "========================" << endl;
    cout << "u choose ";
    setcolor(7);
    cout << dye::red(hero[selected].name) << endl;

    // game start
    cout << "========================" << endl;
    cout << "prepare yourself !!" << endl;
    cout << "your adventure is ready to " + dye::red("BEGIN") + "!!" << endl;
    cout << "u spawn at (" << koorCharY << ", " << koorCharX << ")" << endl;

    int arrowKey = 0;
    while (1)
    {

        // Input arrow key
        cout << "use w, a, s, d to move" << endl;
        cout << "input arrow key :";
        arrowKey = (getch());
        cout << endl;

        // Bergerak ke atas
        if (arrowKey == UP && (map[koorCharY - 1][koorCharX] == 1 || map[koorCharY - 1][koorCharX] == 2 || map[koorCharY - 1][koorCharX] == 3 || map[koorCharY - 1][koorCharX] == 6) && koorCharY >= 0)
        {
            koorCharY = koorCharY - 1;
        }
        // Bergerak ke bawah
        if (arrowKey == DOWN && (map[koorCharY + 1][koorCharX] == 1 || map[koorCharY + 1][koorCharX] == 2 || map[koorCharY + 1][koorCharX] == 3 || map[koorCharY + 1][koorCharX] == 6) && koorCharY < lebarMap)
        {
            koorCharY = koorCharY + 1;
        }
        // Bergerak ke kiri
        if (arrowKey == LEFT && (map[koorCharY][koorCharX - 1] == 1 || map[koorCharY][koorCharX - 1] == 2 || map[koorCharY][koorCharX - 1] == 3 || map[koorCharY][koorCharX - 1] == 6) && koorCharY >= 0)
        {
            koorCharX = koorCharX - 1;
        }
        // Bergerak ke kanan
        if (arrowKey == RIGHT && (map[koorCharY][koorCharX + 1] == 1 || map[koorCharY][koorCharX + 1] == 2 || map[koorCharY][koorCharX + 1] == 3 || map[koorCharY][koorCharX + 1] == 6) && koorCharY < panjangMap)
        {
            koorCharX = koorCharX + 1;
        }
        // enter
        if (arrowKey == ENTER)
        {
            cout << "name           : " << hero[selected].name << endl;
            cout << "hp             : " << hero[selected].hp << endl;
            cout << "basic damage   : " << hero[selected].damage << endl;
            cout << "ulti damage    : " << hero[selected].ulti << endl;
            cout << "armor          : " << hero[selected].armor << endl;
            getch();
        }
        // exit
        if (arrowKey == ESC)
        {
            cout << "dadah .." << endl;
            break;
        }
        system("CLS");

        // Render
        for (int y = 0; y < lebarMap; y++)
        {
            for (int x = 0; x < panjangMap; x++)
            {
                if (koorCharX == x && koorCharY == y)
                {
                    cout << " " << 0 << " ";
                }
                else if (map[y][x] == 1) //! LANE
                {
                    cout << " _ ";
                }
                else if (map[y][x] == 2) //! AMBUSH
                {
                    setcolor(2);
                    cout << " v ";
                    setcolor(7);
                }
                else if (map[y][x] == 3) //! PUDDLE
                {
                    setcolor(3);
                    cout << " o ";
                    setcolor(7);
                }
                else if (map[y][x] == 4) //! TREE
                {
                    cout << dye::white_on_green(" $ ");
                    setcolor(7);
                }
                else if (map[y][x] == 5) //! STONE
                {
                    cout << dye::white_on_grey(" # ");
                    setcolor(7);
                }
                else if (map[y][x] == 6) //! WATER
                {
                    setcolor(1);
                    cout << " ~ ";
                    setcolor(7);
                }
                else if (map[y][x] == 7) //! BARRIER Y
                {
                    cout << "||";
                }
                else
                {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }

        // Random trap and enemy
        int characterPosition = map[koorCharY][koorCharX];
        int i = rand() % 4;

        if (characterPosition == 2)
        {
            int probabilityFindEnemy;
            srand(time(NULL));
            probabilityFindEnemy = rand() % 15;

            // kemungkinan bertemu musuh
            if (probabilityFindEnemy < 3)
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
                    cout << "ready to fight !!" << endl;
                    setcolor(6);
                    int ultiRemain = 2;

                    while (hero[selected].hp > 0 || hero[i].hp > 0)
                    {
                        cout << dye::purple(hero[selected].name) << " vs " << dye::yellow(hero[i].name) << endl
                             << "hp: " << dye::purple(hero[selected].hp) << "|||"
                             << "hp: " << dye::yellow(hero[i].hp) << endl;

                        cout << "1. Basic Attack" << endl
                             << "2. Ultimate Skill (" << ultiRemain << "/2)" << endl;

                        cout << "what will u do : ";
                        int chosen;
                        cin >> chosen;

                        system("CLS");

                        if (chosen == 1)
                        {
                            hero[selected].basicAttack(&hero[i]);
                            hero[i].basicAttack(&hero[selected]);

                            if (ultiRemain < 0)
                            {
                                ultiRemain = 0;
                            }
                        }
                        else if (chosen == 2)
                        {
                            hero[selected].ultimate(&hero[i], ultiRemain);
                            hero[i].ultimate(&hero[selected], ultiRemain);
                            ultiRemain--;

                            if (ultiRemain < 0)
                            {
                                ultiRemain = 0;
                            }
                        }

                        if (hero[selected].hp <= 0)
                        {
                            hero[selected].hp = 0;
                            cout << dye::white_on_blue("u lose !!") << endl;

                            break;
                        }
                        if (hero[i].hp <= 0)
                        {
                            hero[i].hp = 0;
                            cout << dye::white_on_blue("u win !!") << endl;

                            break;
                        }
                    }

                    setcolor(4);
                }
                else if (fightOrRun > 1)
                {
                    setcolor(7);
                    cout
                        << "run bestieee runnnn !!" << endl
                        << "kukira adu mekanik ternyata panik" << endl;
                    setcolor(6);
                    cout << hero[selected].name << " run away" << endl;
                }
                setcolor(7);
            }
        }

        // kemungkinan mendapat item
        if (characterPosition == 6)
        {
            int probabilityFoundItem;
            srand(time(NULL));
            probabilityFoundItem = rand() % 10;

            if (probabilityFoundItem < 2)
            {
                setcolor(4);
                cout
                    << "==============================" << endl
                    << "u found item " << item[i].name << endl
                    << "==============================" << endl
                    << "take it (1) or leave it (2) : ";

                int takeOrLeave;
                cin >> takeOrLeave;

                // make decision ambil atau buang
                if (takeOrLeave == 1)
                {
                    setcolor(6);
                    cout
                        << item[i].name << " saved" << endl
                        << "Type   : " << item[i].type << endl
                        << "Armor  : " << item[i].armorBuffeffect << endl
                        << "Damage : " << item[i].attackBuffeffect << endl;
                    setcolor(7);
                    
                    // armor buff
                    cout << "ur armor buffed from " << dye::red(hero[selected].armor) << " to ";
                    hero[selected].armor = hero[selected].armor + item[i].armorBuffeffect;
                    cout << dye::red(hero[selected].armor) << endl;

                    // attack buff
                    cout << "ur damage buffed from " << dye::red(hero[selected].damage) << " to ";
                    hero[selected].damage = hero[selected].damage + item[i].attackBuffeffect;
                    cout << dye::red(hero[selected].damage) << endl;
                }
                else if (takeOrLeave == 2)
                    setcolor(7);
            }
        }

        // kemungkinan mendapat potion
        if (characterPosition == 3)
        {
            int probabilityFoundPotion;
            srand(time(NULL));
            probabilityFoundPotion = rand() % 10;

            if (probabilityFoundPotion < 3)
            {
                setcolor(4);
                cout
                    << "==============================" << endl
                    << "u found potion " << potion[i].name << endl
                    << "==============================" << endl
                    << "take it (1) or leave it (2) : ";
                
                int takeOrLeave;
                cin >> takeOrLeave;

                // make decision ambil atau buang
                if (takeOrLeave == 1)
                {
                    setcolor(6);
                    cout
                        << potion[i].name << " saved" << endl
                        << "Type   : " << potion[i].type << endl
                        << "Heal   : " << potion[i].healEffect << endl;
                    setcolor(7);

                    cout << "ur hp healed from " << dye::red(hero[selected].hp) << " to ";
                    hero[selected].hp = hero[selected].hp + potion[i].healEffect;
                    cout << dye::red(hero[selected].hp) << endl;
                }
                else if (takeOrLeave > 1)
                    setcolor(7);
            }
        }
    }
    return 0;
}
