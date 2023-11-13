#include <iostream>

using namespace std;

struct zirgoKoordinates {
    int x;
    int y;
};

class lentosKlase {
    private:
    bool inicializuota;
    int* lentosMasyvas;

    void inicializacija(){
        if (n == 0) { cout << "n negali buti lygus 0"; return; }
        int laikinaLenta[n*n];
        for(int i = 0; i < n*n; i++){
            laikinaLenta[i] = 0;
        }
        lentosMasyvas = laikinaLenta;
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
        lentosMasyvas[(x - 1) * n + (y - 1)] = ejimas;
        ejimas++;
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
int taisykliuTikrinimas(int);

bool tinkamaPozicija(zirgoKoordinates);

int main()
{
    argumentuGavimas();
    lenta.padarytEjima(1, 1);
    lenta.padarytEjima(1, 2);
    cout << lenta.gautiReiksme(1, 2);
}

void argumentuGavimas(){
    lenta.n = 5;
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
    if (ateitiesPozicija.x < 1 || ateitiesPozicija.y < 1 || ateitiesPozicija.x > lenta.n || ateitiesPozicija.y > lenta.n){
        return false;
    }
    //reikia patikrint ar neuzejo ant liestos vietos
    return true;
}