#include "doctest.h"
#include "PileChainee.h"

TEST_CASE("les fonctions de PileChainee sont correcte"){
    int nbElement=13;
    Graphe::PileChainee pile{nbElement};

    SUBCASE("La methode vide() est correcte"){
        REQUIRE_FALSE(!pile.vide());
    }

    SUBCASE("La methode ajoute() est correcte"){
        int val=5;
        pile.ajoute(val);
        REQUIRE_EQ(pile.pile(0),val);
        REQUIRE_EQ(pile.pile(val),0);
    }
    SUBCASE("La methode enleve() est correcte"){
        int val=5;
        pile.ajoute(val);
        REQUIRE_EQ(pile.enleve(),val);
        REQUIRE_FALSE(!pile.vide());
    }
}
