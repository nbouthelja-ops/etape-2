#include <stdio.h>
#include <stdlib.h>

int main() {
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    printf("=== PIERRE - FEUILLE - CISEAUX (5 Manches) ===\n");
    printf("Règles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux\n\n");
    printf("Règles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux, 4 = Lézard, 5 = Spock\n\n");

    while (manche <= 7 && abs(scoreJoueur - scoreOrdi) < 2) {
        printf("--- Manche %d/5 ---\n", manche);

        // Saisie du joueur
        printf("Votre choix (1, 2 ou 3) : ");
        printf("Votre choix (1 à 5) : ");
        scanf("%d", &choixJoueur);

        // Choix aléatoire de l'ordinateur (1, 2 ou 3)
        choixOrdi = (rand() % 3) + 1;
        choixOrdi = (rand() % 5) + 1;
        printf("L'ordinateur a choisi : %d\n", choixOrdi);

        // Détermination du gagnant de la manche
        if (choixJoueur == choixOrdi) {
            printf("Égalité !\n");
        } else if ((choixJoueur == 1 && choixOrdi == 3) ||
                   (choixJoueur == 2 && choixOrdi == 1) ||
                   (choixJoueur == 3 && choixOrdi == 2)) {
        } else if ((choixJoueur == 3 && choixOrdi == 2) ||  // Ciseaux coupent Feuille
           (choixJoueur == 2 && choixOrdi == 1) ||  // Feuille couvre Pierre
           (choixJoueur == 1 && choixOrdi == 4) ||  // Pierre écrase Lézard
           (choixJoueur == 4 && choixOrdi == 5) ||  // Lézard empoisonne Spock
           (choixJoueur == 5 && choixOrdi == 3) ||  // Spock casse Ciseaux
           (choixJoueur == 3 && choixOrdi == 4) ||  // Ciseaux décapitent Lézard
           (choixJoueur == 4 && choixOrdi == 2) ||  // Lézard mange Feuille
           (choixJoueur == 2 && choixOrdi == 5) ||  // Feuille réfute Spock
           (choixJoueur == 5 && choixOrdi == 1) ||  // Spock vaporise Pierre
           (choixJoueur == 1 && choixOrdi == 3)) {  // Pierre écrase Ciseaux
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        } else {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
        manche = manche + 1;
    }

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