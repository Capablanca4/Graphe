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
            k[aps]=i+1;
            k++;
        }
    }
}
/// On suppose que les vecteur fs et aps sont initialement vide
void adjVersFs_Aps(const std::vector<std::vector<int>>& M , std::vector<int>& fs, std::vector<int>& aps){
    int n=M[0][0];
    int m=M[0][1];
    fs.push_back(n+m);
    aps.push_back(n);

    int k=1;
    for(int i=1;i<n+1;i++){
        aps.push_back(k);
        for(int j=1;j<n+1;j++){
            if(M[i][j]!=0){
                fs.push_back(j);
                k++;
            }
        }
    fs.push_back(0);
    k++;
    }
}

/// On suppose la matrice M initialement vide
void fs_apsVersAdj(const std::vector<int>& fs,const std::vector<int>& aps, std::vector<std::vector<int>>& M){
    int n = aps[0];
    int m=fs[0];
    std::vector<int> A;
    A.push_back(n);
    A.push_back(m);
    M.push_back(A);
    for(int i=1;i<n+1;i++){
        std::vector<int> B;
        for(int j=0;j<n+1;j++){
            B.push_back(0);
        }
        if(i==n){
            for(int j=aps[n];j<fs[0]-1;j++){
                B[fs[j]]=1;
            }
        }
        else{
            for(int j=aps[i];j<aps[i+1]-1;j++){
                B[fs[j]]=1;
            }
        }
        M.push_back(B);
    }
}

void inverseFs_aps(std::vector<int>& fs,int nbsommet){
    std::vector<std::vector<int>> mat{std::vector<int>{nbsommet}};
    for(int i=1;i<nbsommet;i++){
        mat.push_back(std::vector<int>{});
    }
    int indicemat=1;
    int indice=1;
    while(indice<=fs[0]){
        if(fs[indice]==0){
            indicemat++;
        }
        else{
            mat[fs[indice]].push_back(indicemat);
        }
        indice++;
    }
    indice=1;
    for(int i=1;i<mat.size();i++){
        mat[i].push_back(0);
        for(int j=0;j<mat[i].size();j++){
            fs[indice++]=mat[i][j];
        }
    }
}

void inverseAdj(std::vector<std::vector<int>>& M){
    int n=M[0][0];
    int m=M[0][1];
    std::vector<std::vector<int>> new_M;
    new_M.push_back(std::vector<int>{n,m});
    for(int i=1;i<n+1;i++){
        new_M.push_back(std::vector<int>{0});
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            new_M[j].push_back(M[i][j]);
        }
    }
    M=new_M;
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
    std::vector<int> fs{18,2,3,5,0,3,0,3,4,0,5,6,0,3,0,0,4,6,0};
    std::vector<int> aps2{};
    std::vector<int> fs2{};
    const std::vector<std::vector<int>> M{ {7,11},
                                   {0,0,1,1,0,1,0,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,1,1,0,0,0},
                                   {0,0,0,0,0,1,1,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,0,0,0,0,0},
                                   {0,0,0,0,1,0,1,0} };
    /*determiner_aps(fs,7,aps2); /// test du fonctionnement de determiner_aps()
    for(int i=0;i<aps2.size();i++){
        std::cout<<aps2[i]<<std::endl;
    }*/

/*    adjVersFs_Aps(M,fs2,aps2); /// test du fonctionnement de adjVersFs_Aps()
    std::cout<<"fs : ";
    for(int i=0;i<fs2.size();i++){
        std::cout<< fs2[i] << ";";
    }
    std::cout<<std::endl;
    std::cout<<"aps : ";
    for(int i=0;i<aps2.size();i++){
        std::cout<< aps2[i] << ";";
    }
    std::cout<<std::endl;*/

    /*std::vector<std::vector<int>> M2{}; /// test du fonctionnement de fs_apsVersAdj
    fs_apsVersAdj(fs,aps,M2);
    for(int i=0;i<M2.size();i++){
        for(int j=0;j<M2[i].size();j++){
            std::cout << M2[i][j] << " ";
        }
        std::cout <<std::endl;
    }*/

    /*std::vector<int> fs3{10,2,3,0,4,0,4,0,0,4,0}; /// Test du fonctionnement de inverseFs_aps
    inverseFs_aps(fs3,5);
    for(int i=0;i<fs3.size();i++){
        std::cout << fs3[i] << std::endl;
    }*/

    /*std::vector<std::vector<int>> M2{ {7,11},
                                   {0,0,1,1,0,1,0,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,1,1,0,0,0},
                                   {0,0,0,0,0,1,1,0},
                                   {0,0,0,1,0,0,0,0},
                                   {0,0,0,0,0,0,0,0},
                                   {0,0,0,0,1,0,1,0} };

    inverseAdj(M2); /// Test du fonctionnement de inverseAdj
    for(int i=0;i<M2.size();i++){
        for(int j=0;j<M2[i].size();j++){
            std::cout << M2[i][j] << " ";
        }
        std::cout <<std::endl;
    }*/

    /*int fs2[19] = {18,2,3,5,0,3,0,3,4,0,6,5,0,3,0,0,4,6,0};/// programme
    int *pfs;
    // La référence sur un pointeur doit être initialisée ! On crée un int * pour staisfaire lecompilateur
    int *&aps2 = pfs;
    pfs=fs2;
    cdeterminer_aps(fs2,7,aps2);
    for(int i=0;i<aps2[0];i++){
        std::cout << aps2[i] << std::endl;
    }*/

    return 0;
}
