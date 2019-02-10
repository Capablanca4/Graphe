#include "MatriceAdjacence.h"
#include <iostream>
#include <utility>

namespace Graphe{

MatriceAdjacence::MatriceAdjacence(std::vector<std::vector<int>> matrice,int nbNoeud,int nbArc):
    d_matrice{matrice},
    d_nbNoeud{nbNoeud},
    d_nbArc{nbArc} {}

MatriceAdjacence::MatriceAdjacence():
    d_matrice{},
    d_nbNoeud{0},
    d_nbArc{0} {}

MatriceAdjacence::MatriceAdjacence(int nbNoeud):
    d_matrice{},
    d_nbNoeud{nbNoeud},
    d_nbArc{0}
{
    for(int i=0;i<nbNoeud;i++){
        std::vector<int>* ptr = new std::vector<int>{};
        for(int j=0;j<nbNoeud;j++)  ptr->push_back(0);
        d_matrice.push_back(*ptr);
    }
}

MatriceAdjacence::~MatriceAdjacence(){
    for(unsigned int i=0;i<d_matrice.size();i++){
        while(d_matrice[i].size()!=0){
            d_matrice[i].pop_back();
        }
    }
}

int MatriceAdjacence::nbNoeud(){
    return d_nbNoeud;
}

int MatriceAdjacence::nbArc(){
    return d_nbArc;
}

std::vector<int> MatriceAdjacence::noeud(int noeud){
    return d_matrice[noeud-1];
}

void MatriceAdjacence::ajouteElement(int noeudDep,int noeudArr){
    if(!d_matrice[noeudDep-1][noeudArr-1]){
        d_matrice[noeudDep-1][noeudArr-1]=1;
        d_nbArc++;
    }
}

void MatriceAdjacence::ajouteNoeud(){
    for(unsigned int i=0;i<d_matrice.size();i++)  d_matrice[i].push_back(0);
    d_nbNoeud++;
    std::vector<int>* ptr = new std::vector<int>{};
    for(int i=0;i<d_nbNoeud;i++)  ptr->push_back(0);
    d_matrice.push_back(*ptr);
}

void MatriceAdjacence::supprimeNoeud(int noeud){
    for(int i=noeud-1;i<d_nbNoeud-1;i++){
        d_matrice[i]=d_matrice[i+1];
    }
    d_matrice.pop_back();
    for(int i=0;i<d_nbNoeud-1;i++){
        for(int j=noeud-1;j<d_nbNoeud-1;j++){
            d_matrice[i][j]=d_matrice[i][j+1];
        }
        d_matrice[i].pop_back();
    }
    d_nbNoeud--;
}

void MatriceAdjacence::inverseAdj(){
    std::vector<std::vector<int>> M{};
    for(int i=0;i<d_nbNoeud;i++){
        M.push_back(std::vector<int>{});
        for(int j=0;j<d_nbNoeud;j++){
            M[i].push_back(d_matrice[j][i]);
        }
    }
    d_matrice=M;
}

void MatriceAdjacence::afficheMat(){
    for(int i=1;i<=d_nbNoeud;i++){
        for(int j=0;j<d_nbNoeud;j++) {
            std::cout<<d_matrice[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

}
