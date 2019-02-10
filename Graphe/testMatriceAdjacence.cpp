#include "doctest.h"
#include "MatriceAdjacence.h"
#include <iostream>

TEST_CASE("Test des methodes de MatriceAdjacence"){
    int nbNoeud=7;
    int nbArc=18;
    std::vector<std::vector<int>> M{ {0,1,1,0,1,0,0},
                                     {0,0,1,0,0,0,0},
                                     {0,0,1,1,0,0,0},
                                     {0,0,0,0,1,1,0},
                                     {0,0,1,0,0,0,0},
                                     {0,0,0,0,0,0,0},
                                     {0,0,0,1,0,1,0} };

    std::vector<std::vector<int>> inv_M{ {0,0,0,0,0,0,0},
                                         {1,0,0,0,0,0,0},
                                         {1,1,1,0,1,0,0},
                                         {0,0,1,0,0,0,1},
                                         {1,0,0,1,0,0,0},
                                         {0,0,0,1,0,0,1},
                                         {0,0,0,0,0,0,0} };
    SUBCASE("Les methodes constructeurs sont correctes"){

        SUBCASE("La methode MatriceAdjacence(); est correcte"){
            Graphe::MatriceAdjacence Mat{};
            REQUIRE_EQ(Mat.nbNoeud(),0);
            REQUIRE_EQ(Mat.nbArc(),0);
        }

        SUBCASE("La methode MatriceAdjacence(int nbNoeud) est correcte"){
            Graphe::MatriceAdjacence Mat{nbNoeud};
            REQUIRE_EQ(Mat.nbNoeud(),nbNoeud);
            REQUIRE_EQ(Mat.nbArc(),0);
            std::vector<int>* ptr = new std::vector<int>{};
            for(int j=0;j<nbNoeud;j++)  ptr->push_back(0);
            for(int i=1;i<=nbNoeud;i++){
               REQUIRE_EQ(Mat.noeud(i),*ptr);
            }
        }

        SUBCASE("La methode MatriceAdjacence(vector<vector<int>> matrice,int nbNoeud,int nbArc) est correcte"){
            Graphe::MatriceAdjacence Mat{M,nbNoeud,nbArc};
            REQUIRE_EQ(Mat.nbNoeud(),nbNoeud);
            REQUIRE_EQ(Mat.nbArc(),nbArc);
            for(int i =1;i<=nbNoeud;i++){
                REQUIRE_EQ(M[i-1],Mat.noeud(i));
            }
        }
    }

    SUBCASE("La methode ajouteElement() est correcte"){

        SUBCASE("La methode ajouteElement() est correcte dans le cas general"){
            Graphe::MatriceAdjacence Mat{M,nbNoeud,nbArc};
            Mat.ajouteElement(1,1);
            REQUIRE_EQ(Mat.noeud(1)[0],1);
        }

        SUBCASE("La methode ajouteElement() est correcte dans le cas ou l'element est deja present"){
            Graphe::MatriceAdjacence Mat{M,nbNoeud,nbArc};
            Mat.ajouteElement(1,2);
            REQUIRE_EQ(Mat.noeud(1)[1],1);
        }
    }

    SUBCASE("La methode ajouteNoeud() est correcte"){
        Graphe::MatriceAdjacence Mat{M,nbNoeud,nbArc};
        Mat.ajouteNoeud();
        std::vector<int>* ptr = new std::vector<int>{0};
        for(int i=0;i<nbNoeud;i++){
            ptr->push_back(0);
            M[i].push_back(0);
            REQUIRE_EQ(M[i],Mat.noeud(i+1));
        }
        REQUIRE_EQ(Mat.noeud(nbNoeud+1),*ptr);
    }

    SUBCASE("La methode supprimeNoeud() est correcte"){
        Graphe::MatriceAdjacence Mat{M,nbNoeud,nbArc};
        std::vector<std::vector<int>> rep{ {0,1,1,0,0,0}, /// Matrice M sans le Noeud 5
                                           {0,0,1,0,0,0},
                                           {0,0,1,1,0,0},
                                           {0,0,0,0,1,0},
                                           {0,0,0,0,0,0},
                                           {0,0,0,1,1,0} };
        Mat.supprimeNoeud(5);
        for(int i =1;i<nbNoeud;i++){
            REQUIRE_EQ(rep[i-1],Mat.noeud(i));
        }
    }

    SUBCASE("La methode inverseAdj() est correcte"){
        Graphe::MatriceAdjacence Mat{M,nbNoeud,nbArc};
        Mat.inverseAdj();
        REQUIRE_EQ(Mat.nbNoeud(),nbNoeud);
        REQUIRE_EQ(Mat.nbArc(),nbArc);
        for(int i =1;i<=nbNoeud;i++){
            REQUIRE_EQ(inv_M[i-1],Mat.noeud(i));
        }
    }
}
