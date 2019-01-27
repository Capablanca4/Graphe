#include <vector>

/// fs = liste des liens entre les différents sommet
/// aps = liste des indices indiquant dans fs l'indice où commence un nouveau sommet

void determiner_aps(std::vector<int> fs , int nbsommet , std::vector<int>& aps){
    aps.push_back(nbsommet);
    aps.push_back(1);
    for(unsigned int i=1;i<fs.size()-1;i++){
        if(fs[i]==0) {
            aps.push_back(i+1);
        }
    }
}

void cdeterminer_aps(int *fs,int nbsommet,int *&aps){
    aps = new int[nbsommet+1];
    *aps=nbsommet;
    *(aps+1)=1;
    int empl_elem=2;
    for(int i=1;i<=fs[0];i++){
        if(fs[i]==0){
            aps[empl_elem]=i+1;
            empl_elem++;
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
    for(int i=1;i<=n;i++){
        aps.push_back(k);
        for(int j=1;j<=n;j++){
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
    int n=aps[0],m=fs[0];
    M.push_back(std::vector<int>{n,m});
    for(int i=1;i<=n;i++){
        std::vector<int> B;
        for(int j=0;j<n+1;j++){
            B.push_back(0);
        }
        for(int j=aps[i];j<(i==n ? fs[0]:aps[i+1]-1) ;j++){/// modifiable
            B[fs[j]]=1;
        }
        M.push_back(B);
    }
}

void inverseFs(std::vector<int>& fs,int nbsommet){
    std::vector<std::vector<int>> mat{std::vector<int>{nbsommet}};
    for(int i=1;i<nbsommet;i++){
        mat.push_back(std::vector<int>{});
    }
    int indicemat=1,indice=1;
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
    for(unsigned int i=1;i<mat.size();i++){
        mat[i].push_back(0);
        for(unsigned int j=0;j<mat[i].size();j++){
            fs[indice++]=mat[i][j];
        }
    }
}

///On suppose inv_M initialement vide
void inverseAdj(std::vector<std::vector<int>> M,std::vector<std::vector<int>>& inv_M){
    int n=M[0][0];
    int m=M[0][1];
    inv_M.push_back(std::vector<int>{n,m});
    for(int i=1;i<=n;i++){
        inv_M.push_back(std::vector<int>{0});
        for(int j=1;j<=n;j++){
            inv_M[i].push_back(M[j][i]);
        }
    }
}

///On suppose tdist initialement vide
void dist(std::vector<int>& fs, std::vector<int>& aps, int Sommet,std::vector<int>& tdist){
    int t=0,q=1,p=1,d=0,nbSommet=aps[0];
    std::vector<int> fa{nbSommet,Sommet};
    tdist.push_back(nbSommet);
    for(int i=1;i<=nbSommet;i++){
        tdist.push_back(-1);
    }
    tdist[Sommet]=0;
    while(t<q){
        d++;
        for(int i=t+1;i<q+1;i++){
            int suiv=aps[fa[i]];
            while(fs[suiv]!=0){
                if(tdist[fs[suiv]]==-1){
                    tdist[fs[suiv]]=d;
                    fa[++p]=fs[suiv];
                }
                suiv++;
            }
        }
        t=q;
        q=p;
    }
}

///On suppose tdist initialement vide
void cdist(int *fs,int *aps, int Sommet, int *&tdist){
    int t=0,q=1,p=1,d=0,nbSommet=aps[0];
    int *fa=new int[nbSommet+1];
    fa[1]=Sommet;fa[0]=nbSommet;
    tdist=new int[nbSommet+1];
    tdist[0]=nbSommet;
    for(int i=1;i<=nbSommet;i++){
        tdist[i]=-1;
    }
    tdist[Sommet]=0;
    while(t<q){
        d++;
        for(int i=t+1;i<q+1;i++){
            int suiv=aps[fa[i]];
            while(fs[suiv]!=0){
                if(tdist[fs[suiv]]==-1){
                    tdist[fs[suiv]]=d;
                    fa[++p]=fs[suiv];
                }
                suiv++;
            }
        }
        t=q;
        q=p;
    }
    delete fa;
}

///On suppose mdist initialement vide
void distance(std::vector<int>& fs, std::vector<int>& aps,std::vector<std::vector<int>>& mdist){
    int n=aps[0],m=fs[0];
    mdist.push_back(std::vector<int>{n,m});
    for(int i=1;i<=n;i++){
        std::vector<int> tdist{};
        dist(fs,aps,i,tdist);
        mdist.push_back(tdist);
    }
}
