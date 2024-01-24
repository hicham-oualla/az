#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher le stockage
void afficher_stock(int tableau[]) {
    int i;
	printf("Votre stockage total :\n");
    for (i = 0; i < 50; i++) {
        printf("Produit %d : %d\n", i + 1, tableau[i]);
    }
}

// Fonction pour retirer un produit du stock
void retirer_produit(int tableau[]) {
    int produit_a_retirer;
    int quantite_a_retirer;

    printf("Entrez le num�ro du produit � retirer : ");
    scanf("%d", &produit_a_retirer);

    // V�rifier que le num�ro de produit est valide
    if (produit_a_retirer >= 1 && produit_a_retirer <= 50) {
        printf("Entrez la quantit� � retirer pour le produit %d : ", produit_a_retirer);
        scanf("%d", &quantite_a_retirer);

        // V�rifier que la quantit� � retirer est inf�rieure ou �gale � la quantit� actuelle
        if (quantite_a_retirer <= tableau[produit_a_retirer - 1]) {
            tableau[produit_a_retirer - 1] -= quantite_a_retirer;
            printf("Quantit� retir�e avec succ�s.\n");
        } else {
            printf("Quantit� � retirer sup�rieure � la quantit� actuelle.\n");
        }
    } else {
        printf("Num�ro de produit invalide.\n");
    }
}

// Fonction pour ajouter un nouveau produit au stock avec une quantit� sp�cifi�e
void ajouter_produit(int tableau[]) {
    int p_ajouter;
    int q_ajouter;

    printf("Entrez le num�ro du nouveau produit � ajouter : ");
    scanf("%d", &p_ajouter);

    // V�rifier que le num�ro de produit est valide
    if (p_ajouter >= 1 && p_ajouter <= 50) {
        // V�rifier que le produit n'existe pas d�j� (vous pouvez ajuster cette condition selon vos besoins)
        if (tableau[p_ajouter - 1] == 0) {
            printf("Entrez la quantit� du nouveau produit � ajouter : ");
            scanf("%d", &q_ajouter);

            // V�rifier que la quantit� � ajouter est positive
            if (q_ajouter > 0) {
                tableau[p_ajouter - 1] = q_ajouter;
                printf("Nouveau produit ajout� avec succ�s.\n");
            } else {
                printf("La quantit� du nouveau produit doit �tre positive.\n");
            }
        } else {
            printf("Le produit avec le num�ro %d existe d�j�.\n", p_ajouter);
        }
    } else {
        printf("Num�ro de produit invalide.\n");
    }
}

int main(int argc, char *argv[]) {
    int choix;
    int tableau[50] = {}; // Exemple initial de quantit�s de produits

    printf("Bienvenue dans le centre de gestion de votre stock \n \n");

    while (1) {
        printf("1. pour afficher le stock\n");
        printf("2. pour retirer un produit de stock\n");
        printf("3. pour ajouter un produit au stock\n");
        printf("4. pour quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            afficher_stock(tableau);
            break;
        case 2:
            retirer_produit(tableau);
            afficher_stock(tableau);
            break;
        case 3:
            ajouter_produit(tableau);
            afficher_stock(tableau);
            break;
        case 4:
            printf("Programme termin�.\n");
            exit(0);
        default:
            printf("Choix invalide. Veuillez r�essayer.\n");
        }
    }

    return 0;
}

