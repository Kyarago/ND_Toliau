#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>
#include <numeric>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::list;

class duomenys {
private:
    string Vardas = "";
    string Pavarde = "";
    vector<int> Namu;
    int Egzaminas = 0;
    float Galutinis = 0;
    float Mediana = 0;
    float Vidurkis;
    string Kategorija;
public:
    duomenys() {}
    duomenys(string vardas, string pavarde, vector<int> namu, int egzaminas) {
        Vardas = vardas;
        Pavarde = pavarde;
        Namu = namu;
        Egzaminas = egzaminas;
        //Galutinis = galutinis;
    };
    void Viduk();
    void Madi();
    void Galut();
    void clearNamu() { Namu.clear(); }
    inline string getVardas() const {return Vardas;}
    inline string getPavarde() const {return Pavarde;}
    inline vector<int> getNamu() const {return Namu;}
    inline int getEgzaminas() const {return Egzaminas;}
    inline float getGalutinis() const {return Galutinis;}
    inline float getMediana() const {return Mediana;}
    inline string getKategorija() const {return Kategorija;}
};
