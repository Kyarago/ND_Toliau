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

struct struktura {
    string Vardas = "";
    string Pavarde = "";
    vector<int> Namu;
    int Egzaminas;
    float Galutinis = 0;
    float mediana;
    string kategorija;
    list<string> Vargseliai;
    list<string> Galvociai;


};

void sRusVector(vector<struktura>& grupe);
bool sTvarkymasGal(const struktura& pirmas, const struktura& antras);
void stiknuskaitymui(vector<struktura>& grupe, int eil, int nd);
void slaikas(vector<struktura>& grupe, int eil, int nd);
void svskaidymas(vector<struktura>& lgrupe, int eil);
void svskaidymas2(vector<struktura>& grupe, int eil);