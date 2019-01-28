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



    private:
        int d_nbNoeud;
        int d_nbArc;
        std::vector<int> d_fs;
        std::vector<int> d_aps;

        /// Methode privee
        void determiner_aps();
};

}

#endif // FSAPS_H
