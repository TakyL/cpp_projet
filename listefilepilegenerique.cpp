#include <iostream>
#include <vector>
/// LEDUC Thomas
using namespace std;

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
class Pile // Possibilité de déplier en fin(suppression) , ajout en tête => LIFO
{
public:
    // Constructeur
    Pile()
    {
        debutpointeur = NULL;
        precedpointeur = NULL;
    }

    ~Pile() {}

    ELCH1<T> *creerelch(T valeur)
    {
        ELCH1<T> *tempo = new ELCH1<T>();
        tempo->donnee = valeur;
        tempo->setsuivant(nullptr);
        // tempo->setpreced(null);
        return tempo;
    }

    ELCH1<T> *getdebutpointeur() { return debutpointeur; }

    void Empiler(T valeur) //<=> En tête
    {

        if (debutpointeur == NULL) // Cas vide
        {
            Pile<T> *nouveau = new ELCH1<T>(valeur);
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

    void Deplier(T valeur)
    {
        ELCH1<T> *del = debutpointeur;
        while (debutpointeur)
        {
            debutpointeur = debutpointeur->getsuivant(); // getpreced()
            delete del;
            del = debutpointeur;
        }
    }

    //
    void Afficher()
    {
        if (debutpointeur == NULL) // Cas vide
        {
            cout << "Pile vide" << endl;
        }
        else
        {
            cout << "Affichage PILE\n"
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

// File Generique
template <typename T1> // Insérer à la fin, suppression au debut File => LIFO
class File
{
public:
    // Constructeur
    File()
    {
        debutpointeur = NULL;
        precedpointeur = NULL;
    }

    ~File() {}

    ELCH1<T1> *creerelch(T1 valeur)
    {
        ELCH1<T1> *tempo = new ELCH1<T1>();
        tempo->donnee = valeur;
        tempo->setsuivant(nullptr);
        // tempo->setpreced(null);
        return tempo;
    }

    ELCH1<T1> *getdebutpointeur() { return debutpointeur; }

    void Enfiler(T1 valeur)
    {
        {

            if (debutpointeur == NULL) // Cas liste vide
            {
                ELCH1<T1> *nouveau = new ELCH1<T1>(valeur);
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

                ELCH1<T1> *nouveau = new ELCH1<T1>(valeur);
                nouveau->setdonnee(valeur);
                nouveau->setsuivant(nullptr);
                nouveau->setpreced(debutpointeur);
                debutpointeur = nouveau;

                cout << "Ajout 2:" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl;

                cout << "Sortie" << endl;
            }
        }
    }

    void Defiler(T1 valeur)
    {
        ELCH1<T1> *del = debutpointeur;
        while (debutpointeur)
        {
            debutpointeur = debutpointeur->getpreced(); // getpreced()
            delete del;
            del = debutpointeur;
        }
    }

    //
    void Afficher()
    {
        if (debutpointeur == NULL) // Cas file vide
        {
            cout << "File vide" << endl;
        }
        else
        {
            cout << "Affichage FILE\n"
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
    ELCH1<T1> *debutpointeur;
    ELCH1<T1> *precedpointeur;
};

// Liste Générique

template <typename T2>
class Liste
{
public:
    // Constructeur
    Liste()
    {
        debutpointeur = NULL;
        precedpointeur = NULL;
    }

    ~Liste() {}

    ELCH1<T2> *creerelch(T2 valeur)
    {
        ELCH1<T2> *tempo = new ELCH1<T2>();
        tempo->donnee = valeur;
        tempo->setsuivant(nullptr);
        // tempo->setpreced(null);
        return tempo;
    }

    ELCH1<T2> *getdebutpointeur() { return debutpointeur; }

    void AjouterAuDebut(T2 valeur)
    {

        if (debutpointeur == NULL) // Cas liste vide
        {
            ELCH1<T2> *nouveau = new ELCH1<T2>(valeur);
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

            ELCH1<T2> *nouveau = new ELCH1<T2>(valeur);
            nouveau->setdonnee(valeur);
            nouveau->setsuivant(debutpointeur);
            nouveau->setpreced(nullptr);
            debutpointeur = nouveau;

            cout << "Ajout 2:" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl;

            cout << "Sortie" << endl;
        }
    }

    void AjouterAlaFin(T2 valeur)
    {
        {

            if (debutpointeur == NULL) // Cas liste vide
            {
                ELCH1<T2> *nouveau = new ELCH1<T2>(valeur);
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

                ELCH1<T2> *nouveau = new ELCH1<T2>(valeur);
                nouveau->setdonnee(valeur);
                nouveau->setsuivant(nullptr);
                nouveau->setpreced(debutpointeur);
                debutpointeur = nouveau;

                cout << "Ajout 2:" << debutpointeur->getdonnee() << debutpointeur->getsuivant() << debutpointeur->getpreced() << endl;

                cout << "Sortie" << endl;
            }
        }
    }

    void SupprimerAuDebut(T2 valeur)
    {
        ELCH1<T2> *del = debutpointeur;
        while (debutpointeur)
        {
            debutpointeur = debutpointeur->getsuivant(); // getpreced()
            delete del;
            del = debutpointeur;
        }
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
            cout << "Affichage LISTE\n"
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
    ELCH1<T2> *debutpointeur;
    ELCH1<T2> *precedpointeur;
};

int main()
{
    ELCH1<int> essai(3);
    ELCH1<double> essai2(2.4, 0);
    Liste<double> liste;
    essai.donnee = 1.5;

    cout << essai.getdonnee() << endl;
    cout << essai.getsuivant() << endl;

    cout << "Fin de test  \n"
         << endl;
    cout << "Cas \n"
         << endl;

    liste.AjouterAuDebut(3.2);
    // liste.Afficher();
    liste.AjouterAuDebut(4.56);
    // liste.AjouterAuDebut(6.56);
    liste.Afficher();
    // liste.AjouterAlaFin(3.2);
    // liste.AjouterAlaFin(4.56);
    return 0;
}

// Extends en cpp: class A extends class B => class A {} ; class B : public A {}
// Heritage pile -> File -> Liste ?