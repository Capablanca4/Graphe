#include "FsAps.h"

namespace Graphe{

FsAps::FsAps(int nbNoeud):
    d_tailleAps{nbNoeud},
    d_tailleFs{nbNoeud},
    d_fs{},
    d_aps{}
{
    for(int i=0;i<nbNoeud;i++){
        d_fs.push_back(0);
        d_aps.push_back(i);
    }
}

FsAps::FsAps(int nbNoeud,const std::vector<int>& fs):
    d_tailleAps{nbNoeud},
    d_tailleFs{0},
    d_fs{fs},
    d_aps{}
{
    determiner_aps();
}

FsAps::~FsAps(){
while(d_fs.size()!=0) d_fs.pop_back();
while(d_aps.size()!=0) d_aps.pop_back();
}

int FsAps::NbNoeud(){
    return d_tailleAps;
}

int FsAps::NbArc(){
    return d_tailleFs;
}

int FsAps::Fs(int i){
    return d_fs[i];
}

int FsAps::Aps(int i){
    return d_aps[i];
}

void FsAps::determiner_aps(){
    d_aps.push_back(0);
    d_tailleFs=d_fs.size();
    for(unsigned int i=1;i<d_fs.size()-1;i++){
        if(d_fs[i]==0) {
            d_aps.push_back(i+1);
        }
    }
}

}
