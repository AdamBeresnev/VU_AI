#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

struct zirgoKoordinates {
    int x;
    int y;
    int l;
};

class lentosKlase {
    private:
    bool inicializuota;
    vector<int> lentosMasyvas;

    void inicializacija(){
        if (n == 0) { cout << "n negali buti lygus 0"; return; }
        
        lentosMasyvas.resize(n * n);

        inicializuota = true;
    }
    public:
    int n = 0;
    int ejimas = 1;

    lentosKlase()
    {
        inicializuota = false;
    }

    int gautiReiksme(int x, int y){
        if (!inicializuota) { inicializacija(); }
        return lentosMasyvas[(x - 1) * n + (y - 1)];
    }

    void padarytEjima(int x, int y){
        if (!inicializuota) { inicializacija(); }
        lentosMasyvas[(x - 1) * n + (y - 1)] = ejimas++;
    }

    void grizti(int naujasEjimas){
        for(int i = 0; i < n*n; i++){
            if (lentosMasyvas[i] >= naujasEjimas) {
                lentosMasyvas[i] = 0;
            }
        }
    }
};

lentosKlase lenta;
struct zirgoKoordinates zirgas;

ofstream outShort;
ofstream outLong;

int eilutesSkaiciausIlgis = 8;
int eilute = 1;

zirgoKoordinates taisykles[8] = {{  2,  1, 1},
                                 {  1,  2, 1},
                                 { -1,  2, 1},
                                 { -2,  1, 1},
                                 { -2, -1, 1},
                                 { -1, -2, 1},
                                 {  1, -2, 1},
                                 {  2, -1, 1}};

void argumentuGavimas();
void isvestis1();
void isvestis2(int, zirgoKoordinates, int);
void isvestis3();

string formuoti(int, int);

int taisykliuTikrinimas();
//int taisykliuTikrinimas(int);

int tinkamaPozicija(zirgoKoordinates, zirgoKoordinates);

int main()
{
    argumentuGavimas();
    outLong.open("out-long.txt");
    outShort.open("out-short.txt");

    isvestis1();
    isvestis3();

    outShort.close();
    outLong.close();
}

void argumentuGavimas(){
    lenta.n = 5;
    zirgas = {1, 1, 1};
}

void pagrindinisCiklas(){
    while(zirgas.l < lenta.n * lenta.n){
        
    }
}

void isvestis1(){
    cout << "PART 1. Data\n";
    cout << "  1) Board: " << lenta.n << "x" << lenta.n << ".\n";
    cout << "  2) Initial position: X=" << zirgas.x << ", Y=" << zirgas.y << ". L=" << zirgas.l << ".\n\n";

    outShort << "PART 1. Data\n";
    outShort << "  1) Board: " << lenta.n << "x" << lenta.n << ".\n";
    outShort << "  2) Initial position: X=" << zirgas.x << ", Y=" << zirgas.y << ". L=" << zirgas.l << ".\n\n";

    outLong << "PART 1. Data\n";
    outLong << "  1) Board: " << lenta.n << "x" << lenta.n << ".\n";
    outLong << "  2) Initial position: X=" << zirgas.x << ", Y=" << zirgas.y << ". L=" << zirgas.l << ".\n\n";
}

void isvestis2(int taisykle, zirgoKoordinates pozicija, int busena){
    outLong << formuoti(eilute, eilutesSkaiciausIlgis) << ") ";

    for (int i = 1; i < pozicija.l - 1; i++){
        outLong << '-';
    }

    outLong << "R" << taisykle << ". U=" << pozicija.x << ", V=" << pozicija.y << ". L=" << pozicija.l << ". ";

    switch (busena){
        case 0: 
            outLong << "Free. BOARD[" << pozicija.x << ',' << pozicija.y << "]:=" << pozicija.l << ".\n";
            break;
        case 1:
            outLong << "Thread.\n";
            break;
        case 2:
            outLong << "Out.\n";
            break;
    }
}

void isvestis3(){
    ofstream tempOut ("out-temp-3.txt");
    tempOut << "PART 3. Results\n";

    //result

    tempOut << "  2) Path graphically:\n\n";
    tempOut << "  Y, V ^\n";

    for (int i = lenta.n; i > 0; i--){
        tempOut << "     ";
        tempOut << i << " |";
        
        for (int o = 1; o <= lenta.n; o++){
            tempOut << formuoti(lenta.gautiReiksme(i, o), 3);
        }

        tempOut << endl;
    }

    tempOut << "       ------------------> X, U\n";
    tempOut << "        ";
    for (int i = 1; i <= lenta.n; i++){
        tempOut << formuoti(i, 3);
    }

    tempOut.close();
    ifstream tempIn ("out-temp-3.txt");
    string eilute;
    while (getline(tempIn, eilute)){
        cout << eilute << endl;
        outShort << eilute << endl;
        outLong << eilute << endl;
    }
    tempIn.close();
    remove("out-temp-3.txt");
}

string formuoti(int skaicius, int ilgis){
    string rezultatas = "";
    for (int i = ilgis - to_string(skaicius).length(); i > 0; i--) {
        rezultatas += ' ';
    }
    rezultatas += to_string(skaicius);
    return rezultatas;
}

// int taisykliuTikrinimas() { return taisykliuTikrinimas(1); }

// int taisykliuTikrinimas(int cikloPradzia){
//     for (int i = cikloPradzia; i <= 8; i++){
//         switch (i){
//             case 1:
//                 if (!tinkamaPozicija(taisykle1())){
//                     zirgas = taisykle1();
//                     return 1;
//                 } 
//                 break;
//             case 2:
//                 if (!tinkamaPozicija(taisykle2())){
//                     zirgas = taisykle2();
//                     return 2;
//                 }
//                 break;
//             case 3:
//                 if (!tinkamaPozicija(taisykle3())){
//                     zirgas = taisykle3();
//                     return 3;
//                 }
//                 break;
//             case 4:
//                 if (!tinkamaPozicija(taisykle4())){
//                     zirgas = taisykle4();
//                     return 4;
//                 }
//                 break;
//             case 5:
//                 if (!tinkamaPozicija(taisykle5())){
//                     zirgas = taisykle5();
//                     return 5;
//                 }
//                 break;
//             case 6:
//                 if (!tinkamaPozicija(taisykle6())){
//                     zirgas = taisykle6();
//                     return 6;
//                 }
//                 break;
//             case 7:
//                 if (!tinkamaPozicija(taisykle7())){
//                     zirgas = taisykle7();
//                     return 7;
//                 }
//                 break;
//             case 8:
//                 if (!tinkamaPozicija(taisykle8())){
//                     zirgas = taisykle8();
//                     return 8;
//                 }
//                 break;
//         }
//     }

//     return 0;
// }

int tinkamaPozicija(zirgoKoordinates pozicija, zirgoKoordinates taisykle){
    pozicija.x += taisykle.x;
    pozicija.y += taisykle.y;
    pozicija.l += taisykle.l;
    if (pozicija.x < 1 || pozicija.y < 1 || pozicija.x > lenta.n || pozicija.y > lenta.n){
        return 2;   //2 reiskia kad pozicija uz lentos ribu
    }
    if (lenta.gautiReiksme(pozicija.x, pozicija.y) != 0){
        return 1;   //1 reiskia kad pozicija jau buvo pasiekta
    }
    return 0;   //0 reiskia kad pozicija tinkama
}

