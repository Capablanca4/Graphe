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
    SUBCASE("La methode MatriceAdjacence() est correcte"){

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
               REQUIRE_EQ(Mat.Noeud(i),*ptr);
            }
        }
    }


}
