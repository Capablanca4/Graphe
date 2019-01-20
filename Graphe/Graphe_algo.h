#include <vector>

void determiner_aps(std::vector<int> fs , int nbsommet , std::vector<int>& aps);

void cdeterminer_aps(int *fs,int nbsommet,int *&aps);

void adjVersFs_Aps(const std::vector<std::vector<int>>& M , std::vector<int>& fs, std::vector<int>& aps);

void fs_apsVersAdj(const std::vector<int>& fs,const std::vector<int>& aps, std::vector<std::vector<int>>& M);

void inverseFs(std::vector<int>& fs,int nbsommet);

void inverseAdj(std::vector<std::vector<int>> M,std::vector<std::vector<int>>& new_M);
