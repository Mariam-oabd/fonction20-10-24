#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Fonction qui accepte un nombre variable de paramètres
template<typename... Args>
void testFunction(Args... args) {
    // Afficher le nombre d'arguments
    cout << "Nombre d'arguments : " << sizeof...(args) << endl;
}

int main() {
    int max_args = 0;
    try {
        while (true) {
            // Créer un vecteur avec un nombre croissant d'éléments
            vector<int> args(max_args, 0);
            
            // Appeler la fonction avec les éléments du vecteur
            testFunction(args.data(), args.data() + args.size());

            // Afficher le nombre d'arguments traités
            cout << "Nombre d'arguments : " << max_args << endl;

            // Augmenter le nombre d'arguments pour la prochaine itération
            ++max_args;
        }
    } catch (const exception& e) {
        cerr << "Erreur capturée après " << max_args << " arguments : " << e.what() << endl;
    } catch (...) {
        cerr << "Erreur inconnue capturée après " << max_args << " arguments." << endl;
    }

    return 0;
}
