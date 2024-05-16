#include "raylib.h"
#include <vector>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int CELL_SIZE = SCREEN_WIDTH / 9;

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

int selectedRow = -1;
int selectedCol = -1;

// Fonction pour afficher la grille dans la fenêtre graphique
void afficherGrille() {
    for (int i = 0; i < grille.size(); ++i) {
        for (int j = 0; j < grille[i].size(); ++j) {
            int nombre = grille[i][j];
            if (nombre != 0) {
                DrawText(FormatText("%d", nombre), j * CELL_SIZE + 10, i * CELL_SIZE + 10, 40, BLACK);
            }
        }
    }
}

// Fonction pour gérer les entrées de l'utilisateur
void gererEntrees() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        selectedRow = mouseY / CELL_SIZE;
        selectedCol = mouseX / CELL_SIZE;
    }

    if (IsKeyDown(KEY_ONE) || IsKeyDown(KEY_KP_ONE)) {
        if (selectedRow != -1 && selectedCol != -1) {
            grille[selectedRow][selectedCol] = 1;
        }
    }

    // Ajouter des conditions pour les autres chiffres (deux jusqu'à neuf)
}

int main() {
    // Initialisation de la fenêtre graphique
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sudoku avec Raylib");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        // Gestion des entrées de l'utilisateur
        gererEntrees();

        // Affichage de la grille
        afficherGrille();

        // Dessiner une surbrillance sur la case sélectionnée
        if (selectedRow != -1 && selectedCol != -1) {
            DrawRectangleLines(selectedCol * CELL_SIZE, selectedRow * CELL_SIZE, CELL_SIZE, CELL_SIZE, RED);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

