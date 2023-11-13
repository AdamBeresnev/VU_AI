#include <iostream>

using namespace std;

struct zirgoKoordinates {
    int x;
    int y;
};

int n;
struct zirgoKoordinates zirgas;

zirgoKoordinates taisykle1() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x + 2; ateitiesPozicija.y = zirgas.y + 1; return ateitiesPozicija;};
zirgoKoordinates taisykle2() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x + 1; ateitiesPozicija.y = zirgas.y + 2; return ateitiesPozicija;};
zirgoKoordinates taisykle3() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x - 1; ateitiesPozicija.y = zirgas.y + 2; return ateitiesPozicija;};
zirgoKoordinates taisykle4() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x - 2; ateitiesPozicija.y = zirgas.y + 1; return ateitiesPozicija;};
zirgoKoordinates taisykle5() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x - 2; ateitiesPozicija.y = zirgas.y - 1; return ateitiesPozicija;};
zirgoKoordinates taisykle6() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x - 1; ateitiesPozicija.y = zirgas.y - 2; return ateitiesPozicija;};
zirgoKoordinates taisykle7() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x + 1; ateitiesPozicija.y = zirgas.y - 2; return ateitiesPozicija;};
zirgoKoordinates taisykle8() { struct zirgoKoordinates ateitiesPozicija; ateitiesPozicija.x = zirgas.x + 2; ateitiesPozicija.y = zirgas.y - 1; return ateitiesPozicija;};

void argumentuGavimas();

int taisykliuTikrinimas();
int taisykliuTikrinimas(int cikloPradzia);

bool tinkamaPozicija(zirgoKoordinates ateitiesPozicija);

int main()
{
    argumentuGavimas();
    int cikloPozicija = taisykliuTikrinimas();
    cout << cikloPozicija << zirgas.x << zirgas.y;
}

void argumentuGavimas(){
    n = 5;
    zirgas = {1, 1};
}

int taisykliuTikrinimas() { return taisykliuTikrinimas(1); }

int taisykliuTikrinimas(int cikloPradzia){
    for (int i = cikloPradzia; i <= 8; i++){
        switch (i){
            case 1:
                if (tinkamaPozicija(taisykle1())){
                    zirgas = taisykle1();
                    return 1;
                }
                break;
            case 2:
                if (tinkamaPozicija(taisykle2())){
                    zirgas = taisykle2();
                    return 2;
                }
                break;
            case 3:
                if (tinkamaPozicija(taisykle3())){
                    zirgas = taisykle3();
                    return 3;
                }
                break;
            case 4:
                if (tinkamaPozicija(taisykle4())){
                    zirgas = taisykle4();
                    return 4;
                }
                break;
            case 5:
                if (tinkamaPozicija(taisykle5())){
                    zirgas = taisykle5();
                    return 5;
                }
                break;
            case 6:
                if (tinkamaPozicija(taisykle6())){
                    zirgas = taisykle6();
                    return 6;
                }
                break;
            case 7:
                if (tinkamaPozicija(taisykle7())){
                    zirgas = taisykle7();
                    return 7;
                }
                break;
            case 8:
                if (tinkamaPozicija(taisykle8())){
                    zirgas = taisykle8();
                    return 8;
                }
                break;
        }
    }

    return 0;
}

bool tinkamaPozicija(zirgoKoordinates ateitiesPozicija){
    if (ateitiesPozicija.x < 1 || ateitiesPozicija.y < 1 || ateitiesPozicija.x > n || ateitiesPozicija.y > n){
        return false;
    }
    //reikia patikrint ar neuzejo ant liestos vietos
    return true;
}