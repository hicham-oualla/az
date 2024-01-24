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

    printf("Entrez le numéro du produit à retirer : ");
    scanf("%d", &produit_a_retirer);

    // Vérifier que le numéro de produit est valide
    if (produit_a_retirer >= 1 && produit_a_retirer <= 50) {
        printf("Entrez la quantité à retirer pour le produit %d : ", produit_a_retirer);
        scanf("%d", &quantite_a_retirer);

        // Vérifier que la quantité à retirer est inférieure ou égale à la quantité actuelle
        if (quantite_a_retirer <= tableau[produit_a_retirer - 1]) {
            tableau[produit_a_retirer - 1] -= quantite_a_retirer;
            printf("Quantité retirée avec succès.\n");
        } else {
            printf("Quantité à retirer supérieure à la quantité actuelle.\n");
        }
    } else {
        printf("Numéro de produit invalide.\n");
    }
}

// Fonction pour ajouter un nouveau produit au stock avec une quantité spécifiée
void ajouter_produit(int tableau[]) {
    int p_ajouter;
    int q_ajouter;

    printf("Entrez le numéro du nouveau produit à ajouter : ");
    scanf("%d", &p_ajouter);

    // Vérifier que le numéro de produit est valide
    if (p_ajouter >= 1 && p_ajouter <= 50) {
        // Vérifier que le produit n'existe pas déjà (vous pouvez ajuster cette condition selon vos besoins)
        if (tableau[p_ajouter - 1] == 0) {
            printf("Entrez la quantité du nouveau produit à ajouter : ");
            scanf("%d", &q_ajouter);

            // Vérifier que la quantité à ajouter est positive
            if (q_ajouter > 0) {
                tableau[p_ajouter - 1] = q_ajouter;
                printf("Nouveau produit ajouté avec succès.\n");
            } else {
                printf("La quantité du nouveau produit doit être positive.\n");
            }
        } else {
            printf("Le produit avec le numéro %d existe déjà.\n", p_ajouter);
        }
    } else {
        printf("Numéro de produit invalide.\n");
    }
}

int main(int argc, char *argv[]) {
    int choix;
    int tableau[50] = {}; // Exemple initial de quantités de produits

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
            printf("Programme terminé.\n");
            exit(0);
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}

