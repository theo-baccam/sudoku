#include <iostream>
#include <vector>

using namespace std;

const int GRID_SIZE = 9;

// Fonction pour afficher la grille
void afficherGrille(const vector<vector<int>>& grille) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << grille[i][j] << " ";
        }
        cout << endl;
    }
}

// Fonction pour vérifier si un chiffre peut être placé à une position donnée
bool estValide(const vector<vector<int>>& grille, int ligne, int colonne, int chiffre) {
    // Vérifie la ligne et la colonne
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (grille[ligne][i] == chiffre || grille[i][colonne] == chiffre) {
            return false;
        }
    }
    // Vérifie le bloc 3x3
    int blocLigne = ligne - ligne % 3;
    int blocColonne = colonne - colonne % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grille[i + blocLigne][j + blocColonne] == chiffre) {
                return false;
            }
        }
    }
    return true;
}

// Fonction pour résoudre la grille (utilisation de la récursion)
bool resoudreGrille(vector<vector<int>>& grille) {
    for (int ligne = 0; ligne < GRID_SIZE; ++ligne) {
        for (int colonne = 0; colonne < GRID_SIZE; ++colonne) {
            if (grille[ligne][colonne] == 0) {
                for (int chiffre = 1; chiffre <= 9; ++chiffre) {
                    if (estValide(grille, ligne, colonne, chiffre)) {
                        grille[ligne][colonne] = chiffre;
                        if (resoudreGrille(grille)) {
                            return true;
                        }
                        grille[ligne][colonne] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialisation de la grille avec quelques chiffres préremplis
    vector<vector<int>> grille = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Grille de Sudoku avant resolution : " << endl;
    afficherGrille(grille);
    cout << endl;

    if (resoudreGrille(grille)) {
        cout << "Grille de Sudoku resolue : " << endl;
        afficherGrille(grille);
    } else {
        cout << "Aucune solution n'a ete trouvee pour cette grille." << endl;
    }

    return 0;
}
