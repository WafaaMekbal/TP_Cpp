#include <iostream>
#include <string>

using namespace std;

string chiffrement(string message, string k) {
    string c = "";
    for (int i = 0, j = 0; i < message.length(); i++) {
        char l = message[i];
        if ((l>= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')) {
            char decalage = (l >= 'A' && l<= 'Z') ? 'A' : 'a';
            char l1 = (l+ k[j] -2*decalage) % 26 + decalage;// char l1 = (l+ k[j] -2*decalage) % 26 + decalage;
            c += l1;
            j = (j + 1) % k.length();
        } else {
            c += l;
        }
    }
    return c;
}

string dechiffrement(string messageChiffre, string k) {
    string d = "";
    for (int i = 0, j = 0; i < messageChiffre.length(); i++) {
        char l = messageChiffre[i];
        if ((l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')) {
            char decalage = (l >= 'A' && l <= 'Z') ? 'A' : 'a';
            char l1 = (l - k[j]+26) % 26 + decalage;
            d += l1;
            j = (j + 1) % k.length();
        } else {
            d += l;
        }
    }
    return d;
}

int main() {

    string message;
    string k;
    int choice;

    cout << "Veuillez entrer le message : ";
    getline(cin,message);

    cout << "Veuillez entrer la cle : ";
    getline(cin,k);

    cout << "Choisissez : "<< endl;
    cout << "(1) Crypter "<< endl;
    cout << "(2) Decrypter"<< endl;
    cin >> choice;



      if (choice == 1) {
       string c = chiffrement(message, k);
       cout << "Message chiffré : " << c << endl;
    } else if (choice == 2) {
        string d = dechiffrement(message,k);
        cout << "Message déchiffré : " << d << endl;
    } else {
        std::cout << "Choix invalide." << std::endl;
    }







    return 0;
}
