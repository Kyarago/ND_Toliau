#include "Klase.h"
#include "Fun.h"

void tiknuskaitymui(vector<duomenys> &grupe, int eil, int nd) {
    string pav = "";
    auto start = std::chrono::high_resolution_clock::now();
    pav = "Studentai" + std::to_string(eil) + ".txt";
    grupe.reserve(eil + 10);
    std::ifstream file(pav);
    if (file.good()) {
        int ndpaz;
        string line, vard, pavar;
        std::getline(file, line);
        for (int j = 0; j < eil; j++) {
            file >> vard >> pavar;
            vector<int> ndd;
            for (int i = 0; i < nd; i++) {
                file >> ndpaz;
                ndd.push_back(ndpaz);
            }
            int eee;
            file >> eee;

            duomenys stud (vard, pavar, ndd, eee);
            stud.Viduk();
            stud.Madi();
            stud.Galut();
            grupe.push_back(stud);
            ndd.clear();
            stud.clearNamu();
        }
    }
    else cout << "Ivestas failas nebuvo rastas" << endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << eil << " eiluciu failo nuskaitymas uztruko: " << diff.count() << " s\n";
    file.close();
}

void vskaidymas(vector<duomenys> &grupe, int eil) {
    auto start = std::chrono::high_resolution_clock::now();
    duomenys stud;
    vector<duomenys> Vargseliai;
    vector<duomenys> Galvociai;
    for (auto& t : grupe) {
        //cout << t.getGalutinis() << endl;
        if (t.getGalutinis() < 5.0)
            Vargseliai.push_back(t);
        else Galvociai.push_back(t);
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas isvedant i 2 naujus vektorius laikas: " << diff.count() << " s" << endl;

    std::ofstream vargsai("VectorVargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    std::ofstream kieti("VectorGalvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Galvociai) {
        kieti << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    vargsai.close();
    kieti.close();
    Vargseliai.clear(); Galvociai.clear();
}

bool TvarkymasGal(const duomenys& pirmas, const duomenys& antras) {
    return pirmas.getGalutinis() < antras.getGalutinis();
};

void RusVector(vector<duomenys>& grupe) {
    sort(grupe.begin(), grupe.end(), TvarkymasGal);
};

void vskaidymas2(vector<duomenys>& grupe, int eil) {
    RusVector(grupe);
    auto start = std::chrono::high_resolution_clock::now();
    duomenys stud;
    int q = grupe.size();
    int n = 0;
    int m = 0;
    vector<duomenys> Vargseliai;
    for (auto& t : grupe) {
        if (t.getGalutinis() < 5.0)
            Vargseliai.push_back(t);
    }
    while (grupe[m].getGalutinis() < 5.0) {
        n++;
        m++;
    }
    grupe.erase(grupe.begin(), grupe.begin() + n);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas isvedant 1 nauja vektoriu laikas: " << diff.count() << " s" << endl;

    std::ofstream vargsai("Vector2Vargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    std::ofstream kieti("Vector2Galvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : grupe) {
        kieti << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    vargsai.close();
    kieti.close();
    Vargseliai.clear();
}

void laikas(vector<duomenys>& grupe, int eil, int nd) {
    cout << "Programa dirba su vektoriais --------- :\n";
    tiknuskaitymui(grupe, eil, nd);
    vskaidymas(grupe, eil);
    vskaidymas2(grupe, eil);
    grupe.clear();
}

void listnuskaitymui(list<duomenys>& lgrupe, int eil, int nd) {
    string pav = "";
    auto start = std::chrono::high_resolution_clock::now();
    pav = "Studentai" + std::to_string(eil) + ".txt";
    std::ifstream file(pav);
    if (file.good()) {
        int ndpaz;
        string line, vard, pavar;
        std::getline(file, line);
        for (int j = 0; j < eil; j++) {
            file >> vard >> pavar;
            vector<int> ndd;
            for (int i = 0; i < nd; i++) {
                file >> ndpaz;
                ndd.push_back(ndpaz);
            }
            int eee;
            file >> eee;

            duomenys stud(vard, pavar, ndd, eee);
            stud.Viduk();
            stud.Madi();
            stud.Galut();
            lgrupe.push_back(stud);
            ndd.clear();
            stud.clearNamu();
        }
    }
    else cout << "Ivestas failas nebuvo rastas" << endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << eil << " eiluciu failo nuskaitymas uztruko: " << diff.count() << " s\n";
    file.close();
}

void lskaidymas(list<duomenys>& lgrupe, int eil) {
    auto start = std::chrono::high_resolution_clock::now();
    duomenys lstud;
    list<duomenys> Vargseliai;
    list<duomenys> Galvociai;
    int q = lgrupe.size();
    for (auto& t : lgrupe) {
        if (t.getGalutinis() < 5.0)
            Vargseliai.push_back(t);
        else Galvociai.push_back(t);
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas isvedant i 2 naujus listus laikas: " << diff.count() << " s" << endl;

    //start = std::chrono::high_resolution_clock::now();
    std::ofstream vargsai("ListVargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    std::ofstream kieti("ListGalvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Galvociai) {
        kieti << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    //diff = std::chrono::high_resolution_clock::now() - start;
    //cout << eil << " eiluciu failo kietu ir vargsu failu sukurimo laikas: " << diff.count() << " s" << endl;
    vargsai.close();
    kieti.close();
    Vargseliai.clear(); Galvociai.clear();
}

void RusList(list<duomenys>& lgrupe) {
    lgrupe.sort([](const duomenys& pirmas, const duomenys& antras) {
        return (pirmas.getGalutinis() < antras.getGalutinis());
        });
};

void lskaidymas2(list<duomenys>& lgrupe, int eil) {
    RusList(lgrupe);
    auto start = std::chrono::high_resolution_clock::now();
    duomenys lstud;
    list<duomenys> Vargseliai;
    list<duomenys>::iterator it;
    it = lgrupe.begin();
    for (auto& t : lgrupe) {
        if (t.getGalutinis() < 5.0)
            it++;
    }
    Vargseliai.splice(Vargseliai.begin(), lgrupe, lgrupe.begin(), it);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas isvedant i 1 nauja lista laikas: " << diff.count() << " s" << endl;
    std::ofstream vargsai("List2Vargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    std::ofstream kieti("List2Galvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : lgrupe) {
        kieti << std::left << std::setw(15) << t.getVardas() << std::setw(16) << t.getPavarde() << std::setw(12) << t.getEgzaminas() << std::setw(9) << t.getGalutinis() << endl;
    }
    vargsai.close();
    kieti.close();
    Vargseliai.clear();
}

void llaikas(list<duomenys>& lgrupe, int eil, int nd) {
    cout << "Programa dirba su listais --------- :\n";
    listnuskaitymui(lgrupe, eil, nd);
    lskaidymas(lgrupe, eil);
    lskaidymas2(lgrupe, eil);
    lgrupe.clear();
}