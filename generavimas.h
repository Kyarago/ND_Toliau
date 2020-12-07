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

void tgeneravimas(int nd, int eil) {
    int egz;
    string pav = "Studentai" + std::to_string(eil) + ".txt";
    cout << "Naujo failo pavadinimas: " << pav << endl;;

    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream out(pav);
    out << std::left << std::setw(15) << "Vardas" << std::setw(16) << "Pavarde";
    for (int i = 0; i < nd; i++) {
        out << std::setw(6) << "nd" + std::to_string(i + 1);
    }
    out << std::setw(9) << "Egzaminas" << endl;

    for (int i = 0; i < eil; i++) {
        out << std::left << std::setw(15) << "Vardas" + std::to_string(i + 1) << std::setw(16) << "Pavarde" + std::to_string(i + 1);
        for (int k = 0; k < nd; k++) {
            out << std::setw(6) << 1 + rand() % 10;
        }
        out << std::setw(9) << 1 + rand() % 10 << endl;
    }
    out.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu su " << nd << " namu darbais failo sukurimo laikas: " << diff.count() << endl;
}

void kurt() {
    string ar = "";
    int m;
    cout << "Ar norite sukurti laiko analizei reikalingus tekstinius failus? (t / n)? : ";
    cin >> ar;
    while (ar != "t" && ar != "n" && ar != "N" && ar != "T") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> ar;
    }
    if (ar == "t" || ar == "T") {
        cout << "Kiek namu darbu pazymiu norite sukurti? : ";
        cin >> m;
        tgeneravimas(m, 1000);
        tgeneravimas(m, 10000);
        tgeneravimas(m, 100000);
        tgeneravimas(m, 1000000);
        tgeneravimas(m, 10000000);
    }
}
