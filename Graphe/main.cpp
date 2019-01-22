#include <iostream>
#include <vector>
#include "Graphe_algo.h"

struct ensemble{
    int debut;
    int fin;
    std::vector<int> vec;
};

void appendSansDoublon(const int& x,std::vector<int>& vec){
    bool test=true;
    for(int i=0;i<vec.size();i++){
        if(vec[i]==x){
            test=false;
            break;
        }
    }
    if(test){
        vec.push_back(x);
    }
}

/*void dist(const std::vector<int>& fs,const std::vector<int>& aps,int sommet,std::vector<int>& dst){
    int d=0;
    ensemble X{0,1,std::vector<int>{sommet}};
    std::vector<int> vecY{};

    while(X.debut!=X.fin){
        int tamp=X.vec.size();
        std::cout<<"X.debut:"<<X.debut<< ","<<"X.fin:"<< X.fin<<std::endl;
        for(int i=X.debut;i<X.fin;i++){ /// on marque les différents sommets dans dst et on ajoute à Y les sommets de X qui n'y était pas déja
            if(dst[X.vec[i]]>d){
                dst[X.vec[i]]=d;
                appendSansDoublon(X.vec[i],vecY);
            }
            if(X.vec[i]!=aps[0]){
                for(int j=aps[X.vec[i]];j<aps[X.vec[i]+1]-2;j++){
                    appendSansDoublon(fs[j+1],X.vec);
                }
            }
            else {
                for(int j=aps[X.vec[i]];j<aps[0]-2;j++){
                    appendSansDoublon(fs[j+1],X.vec);
                }
            }
        }
        d++;
        X.debut=tamp;
        X.fin=X.vec.size();
    }
    /*for(int i=0;i<aps[0];i++){
        if(dst[i]==-1){
            dst[i]=INT_MAX;
        }
    }
}*/

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

    /*int fs2[19] = {18,2,3,5,0,3,0,3,4,0,6,5,0,3,0,0,4,6,0};/// programme
    int *pfs;
    // La référence sur un pointeur doit être initialisée ! On crée un int * pour staisfaire lecompilateur
    int *&aps2 = pfs;
    pfs=fs2;
    cdeterminer_aps(fs2,7,aps2);
    for(int i=0;i<aps2[0];i++){
        std::cout << aps2[i] << std::endl;
    }*/
    dist(fs,aps,1,pdist);
    for(int i=0;i<pdist.size();i++)
        std::cout << pdist[i] << std::endl;
    return 0;
}
