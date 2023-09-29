#include <iostream>

using namespace std;

int n;
int eilutesSkaicius = 0;
int paskutinisPajudintasDiskas = 0;

int argumentoGavimas(); //tested

bool rezultatoTikrinimas(int n, int* a, int* b, int* c); //tested
bool galimaPajudint(int diskas, int* bokstas);
int gautVirsune(int* bokstas);

void pilnasUzpildymas(int n, int* a); //tested
void tusciasUzpildymas(int n, int* a); //tested

bool arBokstasTuscias(int n, int* a); //tested
bool arBokstasPilnas(int n, int* a); //tested

void diskoJudinimas(char nuo, char ant, int* a, int* b, int* c); //tested
int diskoNuemimas(int* a); //tested
void diskoUzdejimas(int* a, int diskas); //tested

void isvestiesEilute(char nuo, char ant, int diskas, int* a, int* b, int* c); //tested
void aibiuEilute(int* a, int* b, int* c); //testes
string aibesIsvestis(int* a); //tested
void tarpai(int kiekis);

int main()
{
    n = argumentoGavimas();

    if (n < 1 || n > 10){
        cout << "n is out of scope";
        return 0;
    }

    int a[n + 1];
    int b[n + 1];
    int c[n + 1];
    pilnasUzpildymas(n, a);
    tusciasUzpildymas(n, b);
    tusciasUzpildymas(n, c);
    cout << endl << "Initial state ";
    aibiuEilute(a, b, c);
    cout << endl << endl;

    while (!rezultatoTikrinimas(n, a, b, c)){
        int aDiskas = gautVirsune(a);
        int bDiskas = gautVirsune(b);
        int cDiskas = gautVirsune(c);
        
        if (n % 2 == 0) {
            if (aDiskas != paskutinisPajudintasDiskas && aDiskas != 0) {
                if (galimaPajudint(aDiskas, b)){
                    diskoJudinimas('A', 'B', a, b, c);
                    continue;
                }
                if (galimaPajudint(aDiskas, c)){
                    diskoJudinimas('A', 'C', a, b, c);
                    continue;
                }
            }
            if (bDiskas != paskutinisPajudintasDiskas && bDiskas != 0) {
                if (galimaPajudint(bDiskas, c)){
                    diskoJudinimas('B', 'C', a, b, c);
                    continue;
                }
                if (galimaPajudint(bDiskas, a)){
                    diskoJudinimas('B', 'A', a, b, c);
                    continue;
                }

            }
            if (cDiskas != paskutinisPajudintasDiskas && cDiskas != 0) {
                if (galimaPajudint(cDiskas, a)){
                    diskoJudinimas('C', 'A', a, b, c);
                    continue;
                }
                if (galimaPajudint(cDiskas, b)){
                    diskoJudinimas('C', 'B', a, b, c);
                    continue;
                }
            }
        }
        else {
            if (aDiskas != paskutinisPajudintasDiskas && aDiskas != 0) {
                if (galimaPajudint(aDiskas, c)){
                    diskoJudinimas('A', 'C', a, b, c);
                    continue;
                }
                if (galimaPajudint(aDiskas, b)){
                    diskoJudinimas('A', 'B', a, b, c);
                    continue;
                }
            }
            if (bDiskas != paskutinisPajudintasDiskas && bDiskas != 0) {
                if (galimaPajudint(bDiskas, a)){
                    diskoJudinimas('B', 'A', a, b, c);
                    continue;
                }
                if (galimaPajudint(bDiskas, c)){
                    diskoJudinimas('B', 'C', a, b, c);
                    continue;
                }

            }
            if (cDiskas != paskutinisPajudintasDiskas && cDiskas != 0) {
                if (galimaPajudint(cDiskas, b)){
                    diskoJudinimas('C', 'B', a, b, c);
                    continue;
                }
                if (galimaPajudint(cDiskas, a)){
                    diskoJudinimas('C', 'A', a, b, c);
                    continue;
                }
            }
        }
        cout << "end reached";
        break;
    }
    return 0;
}

bool galimaPajudint(int diskas, int* bokstas)
{
    int i = 0;
    while (bokstas[i] != 0) { i++; }
    if (i == 0) { return true; }
    else {
        return diskas < bokstas[i - 1];
    }
}

int gautVirsune(int* a)
{
    int i = 0;
    int rezultatas;
    while (a[i] != 0){
        i++;
    }
    if (i == 0) { i = 1; }
    return a[i - 1];
}

void diskoJudinimas(char nuo, char ant, int* a, int* b, int* c)
{
    int diskas;
    switch (nuo) {
        case 'A':
            diskas = diskoNuemimas(a);
            break;
        case 'B':
            diskas = diskoNuemimas(b);
            break;
        case 'C':
            diskas = diskoNuemimas(c);
            break;
        default:
            cout << "Netiketa klaida";
    }

    switch (ant) {
        case 'A':
            diskoUzdejimas(a, diskas);
            break;
        case 'B':
            diskoUzdejimas(b, diskas);
            break;
        case 'C':
            diskoUzdejimas(c, diskas);
            break;
        default:
            cout << "Netiketa klaida";
    }

    paskutinisPajudintasDiskas = diskas;

    isvestiesEilute(nuo, ant, diskas, a, b, c);
}

int diskoNuemimas(int* a)
{
    int i = 0;
    int rezultatas;
    while (a[i] != 0){
        i++;
    }
    if (i == 0) { i = 1; }
    rezultatas = a[i - 1];
    a[i - 1] = 0;
    return rezultatas;
}

void diskoUzdejimas(int* a, int diskas)
{
    int i = 0;
    while (a[i] != 0){
        i++;
    }
    a[i] = diskas;
}

int argumentoGavimas()
{
    int gautas;
    cout << "Veiksmu seka kai n=";
    cin >> gautas;
    return gautas;
}

bool rezultatoTikrinimas(int n, int* a, int* b, int* c)
{
    return arBokstasTuscias(n, a) && arBokstasTuscias(n, b) && arBokstasPilnas(n, c);
}

void tusciasUzpildymas(int n, int* a)
{
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
    a[n] = 0;
}

void pilnasUzpildymas(int n, int* a)
{
    for (int i = 0; i < n; i++){
        a[i] = n - i;
    }
    a[n] = 0;
}

bool arBokstasTuscias(int n, int* a)
{
    bool rezultatas = true;
    for (int i = 0; i < n; i++){
        rezultatas = rezultatas && (a[i] == 0);
    }
    return rezultatas;
}

bool arBokstasPilnas(int n, int* a)
{
    bool rezultatas = true;
    for (int i = 0; i < n; i++){
        rezultatas = rezultatas && (a[i] == n - i);
    }
    return rezultatas;
}

void isvestiesEilute(char nuo, char ant, int diskas, int* a, int* b, int* c)
{
    eilutesSkaicius++;
    string skaicius = to_string(eilutesSkaicius);
    cout << string(4 - skaicius.length(), ' ') << skaicius << ". Move disk " << to_string(diskas) << " from " << nuo << " to " << ant << ". ";
    aibiuEilute(a, b, c);
    cout << endl;
}

void aibiuEilute(int* a, int* b, int* c)
{
    string aAibe = aibesIsvestis(a);
    string bAibe = aibesIsvestis(b);
    string cAibe = aibesIsvestis(c);

    cout << "A=" << aAibe << ",";
    tarpai((2 * n + 1) - aAibe.length());
    cout << "B=" << bAibe << ",";
    tarpai((2 * n + 1) - bAibe.length());
    cout << "C=" << cAibe << ".";
}


string aibesIsvestis(int* a)
{
    string rezultatas = "";
    int i = 0;
    while (a[i] != 0){
        if (i != 0) { rezultatas += ","; }

        rezultatas += to_string(a[i]);
        i++;
    }
    return "(" + rezultatas + ")";
}

void tarpai(int kiekis)
{
    for(int i = 0; i < kiekis; i++){
        cout << ' ';
    }
}