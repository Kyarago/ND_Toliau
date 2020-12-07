#include"struktura.h"

void sRusVector(vector<struktura>& grupe) {
    sort(grupe.begin(), grupe.end(), sTvarkymasGal);
};

bool sTvarkymasGal(const struktura& pirmas, const struktura& antras) {
    return pirmas.Galutinis < antras.Galutinis;
};

void stiknuskaitymui(vector<struktura>& grupe, int eil, int nd) {
    struktura stud;
    string pav = "";
    auto start = std::chrono::high_resolution_clock::now();
    pav = "Studentai" + std::to_string(eil) + ".txt";
    grupe.reserve(eil + 10);
    std::ifstream file(pav);
    if (file.good()) {
        int ndpaz;
        string line;
        std::getline(file, line);
        for (int j = 0; j < eil; j++) {
            file >> stud.Vardas >> stud.Pavarde;
            for (int i = 0; i < nd; i++) {
                file >> ndpaz;
                stud.Namu.push_back(ndpaz);
            }
            file >> stud.Egzaminas;
            std::sort(stud.Namu.begin(), stud.Namu.end());
            int c;
            c = stud.Namu.size();
            if (c != 0) {
                if (c % 2 == 1)
                    stud.mediana = stud.Namu[c / 2];
                else
                    stud.mediana = (stud.Namu[c / 2 - 1] + stud.Namu[c / 2]) / 2;
            }
            if (c == 0) {
                stud.Galutinis = stud.Egzaminas * 0.6;
            }
            else {
                float bendras = 0;
                bendras = accumulate(stud.Namu.begin(), stud.Namu.end(), 0);
                stud.Galutinis = bendras / c;
                stud.Galutinis = stud.Galutinis * 0.4 + 0.6 * stud.Egzaminas;
            }
            grupe.push_back(stud);
            stud.Namu.clear();
        }
    }
    else cout << "Ivestas failas nebuvo rastas" << endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << eil << " eiluciu failo nuskaitymas uztruko: " << diff.count() << " s\n";
    file.close();
}

void svskaidymas(vector<struktura>& grupe, int eil) {
    auto start = std::chrono::high_resolution_clock::now();
    struktura stud;
    vector<struktura> Vargseliai;
    vector<struktura> Galvociai;
    int q = grupe.size();
    for (auto& t : grupe) {
        if (t.Galutinis < 5.0)
            Vargseliai.push_back(t);
        else Galvociai.push_back(t);
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas isvedant i 2 naujus vektorius laikas: " << diff.count() << " s" << endl;

    //start = std::chrono::high_resolution_clock::now();
    std::ofstream vargsai("VectorVargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    std::ofstream kieti("VectorGalvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Galvociai) {
        kieti << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    //diff = std::chrono::high_resolution_clock::now() - start;
    //cout << eil << " eiluciu failo kietu ir vargsu failu sukurimo laikas: " << diff.count() << " s" << endl;
    vargsai.close();
    kieti.close();
    Vargseliai.clear(); Galvociai.clear();
}

void svskaidymas2(vector<struktura>& grupe, int eil) {
    sRusVector(grupe);
    auto start = std::chrono::high_resolution_clock::now();
    struktura stud;
    int q = grupe.size();
    int n = 0;
    int m = 0;
    vector<struktura> Vargseliai;
    for (auto& t : grupe) {
        if (t.Galutinis < 5.0)
            Vargseliai.push_back(t);
    }
    while (grupe[m].Galutinis < 5.0) {
        n++;
        m++;
    }
    grupe.erase(grupe.begin(), grupe.begin() + n);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas isvedant 1 nauja vektoriu laikas: " << diff.count() << " s" << endl;

    //std::sort(Vargseliai.begin(), Vargseliai.end(), Tvarkymas);
    //std::sort(grupe.begin(), grupe.end(), Tvarkymas);
    std::ofstream vargsai("Vector2Vargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    std::ofstream kieti("VectorGalvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : grupe) {
        kieti << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    vargsai.close();
    kieti.close();
    Vargseliai.clear();
}

void slaikas(vector<struktura>& grupe, int eil, int nd) {
    cout << "Programa dirba su vektoriais --------- :\n";
    stiknuskaitymui(grupe, eil, nd);
    svskaidymas(grupe, eil);
    svskaidymas2(grupe, eil);
    grupe.clear();
}