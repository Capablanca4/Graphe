#include "FsAps.h"

namespace Graphe{

FsAps::FsAps(int nbNoeud):
    d_nbNoeud{nbNoeud},
    d_nbArc{0},
    d_fs{},
    d_aps{}
{
    for(int i=0;i<nbNoeud;i++){
        d_fs.push_back(0);
        d_aps.push_back(i);
    }
}

FsAps::FsAps(int nbNoeud,const std::vector<int>& fs):
    d_nbNoeud{nbNoeud},
    d_nbArc{0},
    d_fs{fs},
    d_aps{}
{
    determiner_aps();
}

FsAps::~FsAps(){
while(d_fs.size()!=0) d_fs.pop_back();
while(d_aps.size()!=0) d_aps.pop_back();
}

void FsAps::determiner_aps(){
    d_aps.push_back(0);
    for(unsigned int i=1;i<d_fs.size()-1;i++){
        if(d_fs[i]==0) {
            d_aps.push_back(i);
        }
        else{
            d_nbArc++;
        }
    }
}



}
