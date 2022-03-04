#include <iostream>
#include <vector>
/// LEDUC Thomas
using namespace std;
// ELCH1 et SuiteCh1 en générique
template <typename T>
class ELCH1
{

public:
    T donnee;
    // Methodes
    ~ELCH1() {} // Destructeur
    ELCH1() {}

    ELCH1(T donnee)
    {
        donnee = donnee;
        suivant = NULL;
    }
    ELCH1(T donnee, ELCH1<T> *suivant)
    {
        donnee = donnee;
        suivant = suivant;
    }

    void setdonnee(T d) { donnee = d; }

    void setsuivant(ELCH1<T> *element)
    {
        suivant = element;
    }
    void setpreced(ELCH1<T> *element)
    {
        precedent = element;
    }

    T getdonnee()
    {
        return donnee;
    }

    ELCH1<T> *getsuivant()
    {
        return suivant;
    }

    ELCH1<T> *getpreced()
    {
        return precedent;
    }

    void afficher()
    {
        cout << getdonnee() << getsuivant() << endl;
    }

private:
    ELCH1<T> *suivant;
    ELCH1<T> *precedent;
};

template <typename T>
class SuiteCh1
{
public:
    // Constructeur
    SuiteCh1()
    {
        debutpointeur = NULL;
        precedpointeur = NULL;
    }

    ~SuiteCh1() {}

    ELCH1<T> *creerelch(T valeur)
    {
        ELCH1<T> *tempo = new ELCH1<T>();
        tempo->donnee = valeur;
        tempo->setsuivant(nullptr);
        // tempo->setpreced(null);
        return tempo;
    }

    ELCH1<T> *getdebutpointeur() { return debutpointeur; }

    void AjouterAuDebut(T valeur)
    {

        if (debutpointeur == NULL) // Cas liste vide
        {
            ELCH1<T> *nouveau = new ELCH1<T>(valeur);
            nouveau->setdonnee(valeur);
            nouveau->setsuivant(debutpointeur);
            nouveau->setpreced(nullptr);

            debutpointeur = nouveau;
            cout << "Ajout 1 :" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl; // Verif
        }
        else // Sinon
        {
            cout << "Au moins un element : " << endl;
            while (debutpointeur->getpreced() != NULL) // Parcours jusqu'au debut puis ajout
            {
                debutpointeur = debutpointeur->getpreced();
            }

            ELCH1<T> *nouveau = new ELCH1<T>(valeur);
            nouveau->setdonnee(valeur);
            nouveau->setsuivant(debutpointeur);
            nouveau->setpreced(nullptr);
            debutpointeur = nouveau;

            cout << "Ajout 2:" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl;

            cout << "Sortie" << endl;
        }
    }

    void AjouterAlaFin(T valeur)
    {
        {

            if (debutpointeur == NULL) // Cas liste vide
            {
                ELCH1<T> *nouveau = new ELCH1<T>(valeur);
                nouveau->setdonnee(valeur);
                nouveau->setsuivant(debutpointeur);
                nouveau->setpreced(nullptr);

                debutpointeur = nouveau;
                cout << "Ajout 1 :" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl; // Verif
            }
            else // Sinon
            {
                cout << "Au moins un element : " << endl;
                while (debutpointeur->getsuivant() != NULL) // Parcours jusqu'à la fin puis ajout
                {
                    debutpointeur = debutpointeur->getsuivant();
                }

                ELCH1<T> *nouveau = new ELCH1<T>(valeur);
                nouveau->setdonnee(valeur);
                nouveau->setsuivant(nullptr);
                nouveau->setpreced(debutpointeur);
                debutpointeur = nouveau;

                cout << "Ajout 2:" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl;

                cout << "Sortie" << endl;
            }
        }
    }

    void SupprimerAuDebut(T valeur)
    {
        ELCH1<T> *del = debutpointeur;
        while (debutpointeur)
        {
            debutpointeur = debutpointeur->getsuivant(); // getpreced()
            delete del;
            del = debutpointeur;
        }
        // delete ; //call destructeur
    }

    //
    void Afficher()
    {
        if (debutpointeur == NULL) // Cas liste vide
        {
            cout << "Liste vide" << endl;
        }
        else
        {
            cout << "Affichage \n"
                 << endl;
            while (debutpointeur->getsuivant() != NULL) // Si + de 2 elements
            {
                cout << debutpointeur->getdonnee() << endl;
                cout << debutpointeur->getsuivant() << endl; // Element suivant
                // if(debutpointeur->getsuivant() == NULL) cout <<"La valeur suivante est nulle"<<endl;
                // cout <<precedpointeur->getdonnee() <<endl;

                debutpointeur = debutpointeur->getsuivant();
            }
            cout << debutpointeur->getdonnee() << endl;
        }
    }

private:
    ELCH1<T> *debutpointeur;
    ELCH1<T> *precedpointeur;
};

int main() // Problème affichage : cas ELCH1
{
    ELCH1<double> essai(5.5, 0);
    // ELCH1<double> essai2(2.4,0);
    // ELCH1<int> essai3(1);
    // ELCH1<char> essai4('d');
    SuiteCh1<double> liste;
    //<double>essai.donnee = 1.5;

    cout << essai.getdonnee() << endl;
    cout << essai.getsuivant() << endl;
    cout << essai.getpreced() << endl;
    essai.afficher();
    cout << "Fin de test  \n"
         << endl;

    liste.AjouterAuDebut(3.2);
    // liste.Afficher();
    liste.AjouterAuDebut(4.56);
    // liste.AjouterAuDebut(6.56);
    liste.Afficher();
    liste.SupprimerAuDebut(4.56);
    liste.Afficher();
    // liste.AjouterAlaFin(3.2);
    // liste.AjouterAlaFin(4.56);

    return 0;
}
