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
    fs.push_back(m);
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
            for(int j=aps[n];j<fs[0];j++){
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
