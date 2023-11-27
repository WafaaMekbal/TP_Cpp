#include <iostream>
#include <string>

using namespace std;

string crypt(string A) {
    int l = A.length();
    string c = A;

    for (int i = 0; i < l; i++) {
        if (A[i] >= 'a' && A[i] <= 'z') {
            c[i] = ((A[i] - 'a' + 3) % 26) + 'a';
        } else if (A[i] >= 'A' && A[i] <= 'Z') {
            c[i] = ((A[i] - 'A' + 3) % 26) + 'A';
        }
    }

    return c;
}

string decrypt(string A) {
    int l = A.length();
    string c = A;

    for (int i = 0; i < l; i++) {
        if (A[i] >= 'a' && A[i] <= 'z') {
            c[i] = ((A[i] - 'a' - 3 + 26) % 26) + 'a';
        } else if (A[i] >= 'A' && A[i] <= 'Z') {
            c[i] = ((A[i] - 'A' - 3 + 26) % 26) + 'A';
        }
    }

    return c;
}

int main() {
    std::string A;
    int choice;

    std::cout << "Veuillez entrer le message : ";
    std::getline(std::cin, A);
    std::cout << "Choisissez : "<< std::endl;
    std::cout << "(1) Crypter "<< std::endl;
    std::cout << "(2) Décrypter"<< std::endl;
    std::cin >> choice;

    if (choice == 1) {
        A = crypt(A);
        std::cout << "Le message crypté est : " << A << std::endl;
    } else if (choice == 2) {
        A = decrypt(A);
        std::cout << "Le message décrypté est : " << A << std::endl;
    } else {
        std::cout << "Choix invalide." << std::endl;
    }

    return 0;
}
