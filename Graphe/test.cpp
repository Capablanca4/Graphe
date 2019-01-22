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

    SUBCASE("La fonction dist() est correcte"){
        std::vector<int> rep{aps[0],0,1,1,2,1,3,-1};
        std::vector<int> tdist{};
        dist(fs,aps,1,tdist);
        REQUIRE_EQ(rep,tdist);
    }

    SUBCASE("La fonction distance() est correcte"){
        std::vector<std::vector<int>> rep{{aps[0],fs[0]},
                                          {aps[0], 0, 1, 1, 2, 1, 3,-1},
                                          {aps[0],-1, 0, 1, 2, 3, 3,-1},
                                          {aps[0],-1,-1, 0, 1, 2, 2,-1},
                                          {aps[0],-1,-1, 2, 0, 1, 1,-1},
                                          {aps[0],-1,-1, 1, 2, 0, 3,-1},
                                          {aps[0],-1,-1,-1,-1,-1, 0,-1},
                                          {aps[0],-1,-1, 3, 1, 2, 1, 0}};


        std::vector<std::vector<int>> mdist{};
        distance(fs,aps,mdist);
        for(int i=0;i<mdist.size();i++){
            std::cout << "Size i= " << i << ", " << mdist[i].size() << std::endl;
            for(int j=0;j<mdist[i].size();j++){
                std::cout<<mdist[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        if ( rep.size() == mdist.size() )
             std::cout<< "EQUAL SIZE" << std::endl;
        else
            std::cout<< "rep SIZE= " << rep.size() << " mdist SIZE= " << mdist.size() <<std::endl;

        for(int i=0;i<rep.size();i++){
            for(int j=0;j<rep[i].size();j++){
                std::cout<<rep[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        REQUIRE_EQ(rep,mdist);
    }

}
