#include "klase.h"
#include "Fun.h"

void duomenys::Viduk() {
    float bbendras = accumulate(Namu.begin(), Namu.end(), 0);
    Vidurkis = bbendras / size(Namu);
}
void duomenys::Madi() {
    std::sort(Namu.begin(), Namu.end());
    int size = Namu.size();
    if (size % 2 == 1)
        Mediana = float(Namu[size / 2]);
    else
        Mediana = (float(Namu[size / 2 - 1]) + float(Namu[size / 2])) / 2;
}
void duomenys::Galut() {
    Galutinis = 0.4 * Vidurkis + 0.6 * Egzaminas;
}
