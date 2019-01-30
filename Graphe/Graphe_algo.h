#include <vector>
#include "PileChainee.h"

void determiner_aps(std::vector<int> fs , int nbsommet , std::vector<int>& aps);

void cdeterminer_aps(int *fs,int nbsommet,int *&aps);

void adjVersFs_Aps(const std::vector<std::vector<int>>& M , std::vector<int>& fs, std::vector<int>& aps);

void fs_apsVersAdj(const std::vector<int>& fs,const std::vector<int>& aps, std::vector<std::vector<int>>& M);

void cfs_apsVersAdj(int *fs,int *aps,int **&A);

void inverseFsAps(std::vector<int>& fs,std::vector<int>& aps,int nbsommet);

void inverseAdj(std::vector<std::vector<int>> M,std::vector<std::vector<int>>& inv_M);

void dist(std::vector<int>& fs, std::vector<int>& aps, int Sommet,std::vector<int>& tdist);

void cdist(int *fs,int *aps, int Sommet, int *&tdist);

void distance(std::vector<int>& fs, std::vector<int>& aps,std::vector<std::vector<int>>& mdist);

void cdet_ddi(int *fs,int *aps, int *&ddi);

void det_ddi(const std::vector<int>& fs,int nbSommet, std::vector<int>& ddi);

void cdet_app(int *ddi,int *&app);

void det_app(const std::vector<int>& ddi,std::vector<int>& app);

void fs_apsVersfpp_app(int *fs,int *aps,int *&app);

void det_CFC(const std::vector<std::vector<int>> tdist,std::vector<int> prem,Graphe::PileChainee pilch,std::vector<int> cfc);
