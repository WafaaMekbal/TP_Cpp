#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>



using namespace std;

vector <string> rendreVect(string NomFich) {
    vector<string> fich ;

    FILE* fichier = fopen(NomFich.c_str(),"r");
    if(fichier != nullptr){
    int Asc;
    char c;
    string mot;

    while((Asc= fgetc(fichier))!= EOF){
        c = static_cast<char>(Asc);
        if(c!=' '){
            mot+=c;
        }
        else{
            fich.push_back(mot);
            mot = "";
        }
    }

        fclose(fichier);
    }
    else{
         fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
    }
    return fich;
}

int ProdScal(const vector<int>& A, const vector<int>& B){
    int prod=0;
    size_t minV = min(A.size(), B.size());

    for(size_t i=0 ; i< minV; i++){
        prod += A[i]*B[i];
    }

    return prod;
}

float norm (const vector<int>& A){
    float norm = 0;
    for(size_t i=0 ; i<A.size(); i++){
        norm += A[i]*A[i];
    }
    norm = sqrt(norm);
    return norm;
}

float similsrite(const vector<int>& A, const vector<int>& B){
    float similarite = 0;
    int Prod = ProdScal(A,B);
    float normA = norm(A);
    float normB = norm(B);

    if(normA == 0 || normB ==0){
        return 0;
    }
    else{

    similarite = (Prod/(normA*normB));

    return similarite *100;}
}

vector<int> bin(const vector<string>& phrase, const vector<string>& all) {
    vector<int> bine;

    for (size_t j = 0; j < all.size(); j++) {
        bool motPresent = false;

        for (size_t i = 0; i < phrase.size(); i++) {
            if (all[j] == phrase[i]) {
                motPresent = true;
                break;
            }
        }

        bine.push_back(motPresent ? 1 : 0);
    }

    return bine;
}


int main() {
    string fichA = "C:\\Users\\Dell\\OneDrive\\Bureau\\2.txt";
    string fichB = "C:\\Users\\Dell\\OneDrive\\Bureau\\1.txt";
    vector<int> binA, binB;
    vector<string> A, B, all;

    A = rendreVect(fichA);
    B = rendreVect(fichB);

    all.insert(all.end(),A.begin(),A.end());
    all.insert(all.end(),B.begin(),B.end());

    binA = bin(A, all);
    binB = bin(B, all);
    cout << "Similarité cosinus entre A et B : " << similsrite(binA, binB)<< "%" << endl;


    return 0;
}
