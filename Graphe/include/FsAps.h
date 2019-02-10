#ifndef FSAPS_H
#define FSAPS_H
#include <vector>

namespace Graphe{

class FsAps
{
    public:
        /// Constructeur
        FsAps(int nbNoeud);
        FsAps(int nbNoeud,const std::vector<int>& fs);
        ~FsAps();

        ///Accesseur
        int NbNoeud();
        int NbArc();
        int Fs(int i);
        int Aps(int i);


    private:
        int d_tailleFs;
        int d_tailleAps;
        std::vector<int> d_fs;
        std::vector<int> d_aps;

        /// Methode privee
        void determiner_aps();
};

}

#endif // FSAPS_H
