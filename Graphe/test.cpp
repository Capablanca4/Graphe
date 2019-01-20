#include "doctest.h"
#include "Graphe_algo.h"
#include <iostream>

TEST_CASE("Les fonctions fonctionnent correctement"){

    std::vector<int> aps{7,1,5,7,10,13,15,16};
    std::vector<int> fs{18,2,3,5,0,3,0,3,4,0,5,6,0,3,0,0,4,6,0};
    std::vector<int> inv_fs{18,0,1,0,1,2,3,5,0,3,7,0,1,4,0,4,7,0,0};
    std::vector<std::vector<int>> M{ {7,18},
                                   {0,0,1,1,0,1,0,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,1,1,0,0,0},
                                   {0,0,0,0,0,1,1,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,0,0,0,0,0},
                                   {0,0,0,0,1,0,1,0} };
    std::vector<std::vector<int>> inv_M{ {7,18},
                                         {0,0,0,0,0,0,0,0},
                                         {0,1,0,0,0,0,0,0},
                                         {0,1,1,1,0,1,0,0},
                                         {0,0,0,1,0,0,0,1},
                                         {0,1,0,0,1,0,0,0},
                                         {0,0,0,0,1,0,0,1},
                                         {0,0,0,0,0,0,0,0} };

    SUBCASE("La fonction determiner_aps() est correcte"){
        std::vector<int> aps2{};///futur aps
        determiner_aps(fs,7,aps2);
        REQUIRE_EQ(aps,aps2);
    }

    SUBCASE("La fonction adjVersFs_Aps() est correcte"){
        std::vector<int> aps2{};///futur aps
        std::vector<int> fs2{};///futur fs
        adjVersFs_Aps(M,fs2,aps2);
        REQUIRE_EQ(fs,fs2);
        REQUIRE_EQ(aps,aps2);
    }

    SUBCASE("La fonction fs_apsVersAdj() est correcte"){
        std::vector<std::vector<int>> M2{}; /// futur M
        fs_apsVersAdj(fs,aps,M2);
        REQUIRE_EQ(M,M2);
    }

    SUBCASE("La fonction inverseFs() est correcte"){
        inverseFs(fs,aps[0]);
        REQUIRE_EQ(fs,inv_fs);
    }

    SUBCASE("La fonction inverseAdj() est correcte"){
    std::vector<std::vector<int>> new_M;
    inverseAdj(M,new_M);
    REQUIRE_EQ(new_M,inv_M);
    }

}
