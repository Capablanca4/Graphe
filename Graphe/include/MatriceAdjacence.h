#ifndef MATRICEADJACENCE_H
#define MATRICEADJACENCE_H
#include <vector>

namespace Graphe{

class MatriceAdjacence
{
    public:
        /// Construteur et destructeur
        MatriceAdjacence();
        MatriceAdjacence(std::vector<std::vector<int>> matrice,int nbNoeud,int nbArc);
        MatriceAdjacence(int nbNoeud);
        ~MatriceAdjacence();

        /// Getteur
        int nbNoeud();
        int nbArc();
        std::vector<int> noeud(int noeud);

        /// Setteur
        void ajouteElement(int noeudDep,int noeudArr);
        void ajouteNoeud();
        void supprimeNoeud(int noeud);

        /// Methode
        void inverseAdj();
        void afficheMat();

    private:
        std::vector<std::vector<int>> d_matrice;
        int d_nbNoeud;
        int d_nbArc;
};

}
#endif // MATRICEADJACENCE_H
