#include <iostream>
#include <vector>
#include "Graphe_algo.h"

int main()
{
    std::vector<int> aps{7,1,5,7,10,13,15,16};
    std::vector<int> fs{18,2,3,5,0,3,0,3,4,0,5,6,0,3,0,0,4,6,0};
    std::vector<int> aps2{};
    std::vector<int> fs2{};
    std::vector<int> la_dist{};
    std::vector<int>&pdist = la_dist;
    const std::vector<std::vector<int>> M{ {7,18},
                                   {0,0,1,1,0,1,0,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,1,1,0,0,0},
                                   {0,0,0,0,0,1,1,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,0,0,0,0,0},
                                   {0,0,0,0,1,0,1,0} };
    dist(fs,aps,1,pdist);
    for(int i=0;i<pdist.size();i++)
        std::cout << pdist[i] << std::endl;
    return 0;
}
