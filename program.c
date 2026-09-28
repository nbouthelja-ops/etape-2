#include <stdio.h>#include <stdlib.h>

int main() {
int scoreJoueur = 0;
int scoreOrdi = 0;
int manche = 1;
int choixJoueur;
int choixOrdi;

printf("=== PIERRE - FEUILLE - CISEAUX (5 Manches) ===\n");
printf("Règles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux, 4 = Lézard, 5 = Spock\n\n");
while (manche <= 7 && abs(scoreJoueur - scoreOrdi) < 2) {
printf("--- Manche %d/5 ---\n", manche);
// Saisie du joueur
printf("Votre choix (1 à 5) : ");
scanf("%d", &choixJoueur);

// Vérification du choix du joueur
while (choixJoueur < 1 || choixJoueur > 5) {
printf("Choix invalide ! Veuillez choisir un nombre entre 1 et 5 : ");
scanf("%d", &choixJoueur);
}

// Choix aléatoire de l'ordinateur
choixOrdi = (rand() % 5) + 1;
printf("L'ordinateur a choisi : %d\n", choixOrdi);

// Détermination du gagnant de la manche
if (choixJoueur == choixOrdi) {
printf("Égalité !\n");
} else if ((choixJoueur == 3 && choixOrdi == 2) ||
(choixJoueur == 2 && choixOrdi == 1) ||
(choixJoueur == 1 && choixOrdi == 4) ||
(choixJoueur == 4 && choixOrdi == 5) ||
(choixJoueur == 5 && choixOrdi == 3) ||
(choixJoueur == 3 && choixOrdi == 4) ||
(choixJoueur == 4 && choixOrdi == 2) ||
(choixJoueur == 2 && choixOrdi == 5) ||
(choixJoueur == 5 && choixOrdi == 1) ||
(choixJoueur == 1 && choixOrdi == 3)) {

printf("Vous gagnez cette manche !\n");
scoreJoueur = scoreJoueur + 1;

} else {
printf("L'ordinateur gagne cette manche !\n");
scoreOrdi = scoreOrdi + 1;
}
printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
manche = manche + 1;}

// Bilan de la partie
printf("=== FIN DE LA PARTIE ===\n");
printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);

    if (scoreJoueur > scoreOrdi) {
        printf("Bravo, vous avez gagné la partie !\n");
    } else if (scoreOrdi > scoreJoueur) {
        printf("L'ordinateur remporte la partie...\n");
    } else {
        printf("Match nul parfait !\n");
    }

    return 0;
}