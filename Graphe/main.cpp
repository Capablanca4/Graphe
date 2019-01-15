#include <iostream>
#include <vector>
#include <climits>

/// fs = liste des liens entre les différents sommet
/// aps = liste des indices indiquant dans fs l'indice où commence un nouveau sommet

void determiner_aps(std::vector<int> fs , int nbsommet , std::vector<int>& aps){
    aps.push_back(nbsommet);
    aps.push_back(1);
    for(int i=1;i<fs.size()-1;i++){
        if(fs[i]==0) {
            aps.push_back(i+1);
        }
    }
}

void cdeterminer_aps(int *fs,int nbsommet,int *&aps){
    int k=2;
    aps = new int[nbsommet+1];
    *aps=nbsommet;
    *(aps+1)=1;
    for(int i=1;i<fs[0]+1;i++){
        if(fs[i]==0){
            aps[k]=i+1;
            k++;
        }
    }
}

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

void dist(const std::vector<int>& fs,const std::vector<int>& aps,int sommet,std::vector<int>& dst){
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
    }*/
}

int main()
{
    std::vector<int> aps{7,1,5,7,10,13,15,16};
    std::vector<int> fs{18,2,3,5,0,3,0,3,4,0,6,5,0,3,0,0,4,6,0};
    std::vector<int> dst{};
    /*for(int i=0;i<aps[0];i++){
        dst.push_back(INT_MAX);
    }
    dist(fs,aps,1,dst);
    for(int i=0;i<dst.size();i++){
        std::cout << dst[i] << std::endl;
    }*/

    int fs2[19] = {18,2,3,5,0,3,0,3,4,0,6,5,0,3,0,0,4,6,0};
    int *pfs;
    // La référence sur un pointeur doit être initialisée ! On crée un int * pour staisfaire lecompilateur
    int *&aps2 = pfs;
    pfs=fs2;
    cdeterminer_aps(fs2,7,aps2);
    for(int i=0;i<aps2[0];i++){
        std::cout << aps2[i] << std::endl;
    }

    return 0;
}
