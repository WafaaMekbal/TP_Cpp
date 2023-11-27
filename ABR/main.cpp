#include <iostream>

using namespace std;

struct Noeud {
    int c;
    Noeud* gauch;
    Noeud* droit;
};

Noeud* createNode(int k) {
    Noeud* noeud1 = new Noeud;
    noeud1 ->c = k;
    noeud1 ->gauch = nullptr;
    noeud1 ->droit = nullptr;
    return noeud1 ;
}

Noeud* insertion(Noeud* racine, int k) {
    if (racine == nullptr) {
        return createNode(k);
    }

    if (k < racine->c) {
        racine->gauch = insertion(racine->gauch, k);
    } else if (k > racine->c) {
        racine->droit = insertion(racine->droit, k);
    }

    return racine;
}


void inorder(Noeud* racine) {
    if (racine != nullptr) {
        inorder(racine->gauch);
        cout << racine->c << " ";
        inorder(racine->droit);
    }
}

int main() {
    Noeud* racine = nullptr;


    racine = insertion(racine, 50);
    insertion(racine, 30);
    insertion(racine, 20);
    insertion(racine, 40);
    insertion(racine, 70);
    insertion(racine, 60);
    insertion(racine, 80);


    cout << "Elements de l'arbre en ordre croissant : ";
    inorder(racine);
    cout << endl;

    return 0;
}
