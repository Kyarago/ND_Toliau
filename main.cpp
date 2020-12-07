#include "Klase.h"
#include "generavimas.h"
#include "Fun.h"
#include "struktura.h"

int main() {
	vector<duomenys> grupe;
	list<duomenys> lgrupe;
    vector<struktura> sgrupe;
	kurt();
    string o = "";
    int n;
    cout << "Norite palyginti strukturas su klasem(p) ar ivykdyti bendra programos analize(b)? (p / b)? : ";
    cin >> o;
    while (o != "p" && o != "b" && o != "B" && o != "P") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> o;
    }
    if (o == "b" || o == "B") {
        cout << "Kiek namu darbu pazymiu failuose? : ";
        cin >> n;
        do {
            try {
                if (cin.fail()) {
                    throw std::runtime_error("Vesti reikia skaiciu!!!\n");
                }
            }
            catch (const std::runtime_error& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Iveskite skaiciu: ";
                cin >> n;
            }
        } while (cin.fail() == true);
        laikas(grupe, 1000, n);
        llaikas(lgrupe, 1000, n);
        cout << "------------------------------------------------------------------------- \n" << endl;
        laikas(grupe, 10000, n);
        llaikas(lgrupe, 10000, n);
        cout << "------------------------------------------------------------------------- \n" << endl;
        laikas(grupe, 100000, n);
        llaikas(lgrupe, 100000, n);
        cout << "------------------------------------------------------------------------- \n" << endl;
        laikas(grupe, 1000000, n);
        llaikas(lgrupe, 1000000, n);
        cout << "------------------------------------------------------------------------- \n" << endl;
        /*laikas(grupe, 10000000, n);
        llaikas(lgrupe, 10000000, n);
        cout << "------------------------------------------------------------------------- \n" << endl;*/
        grupe.clear(); lgrupe.clear();
    }
    else {
        cout << "Klases ir strukturos lyginimas ------------------- :" << endl;
        cout << "STRUKTURA (su vector) ------------------- :" << endl;
        slaikas(sgrupe, 100000, 5);
        slaikas(sgrupe, 1000000, 5);
        cout << endl;
        cout << "KLASE (su vector) ------------------- :" << endl;
        laikas(grupe, 100000, 5);
        laikas(grupe, 1000000, 5);
        cout << endl;
        grupe.clear(); lgrupe.clear();
    }
    system("pause");
}

