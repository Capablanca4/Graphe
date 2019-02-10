#ifndef PILECHAINEE_H
#define PILECHAINEE_H

namespace Graphe{

class PileChainee
{
    public:
        PileChainee(int nbElement);
        ~PileChainee();

        ///Getter
        int pile(int indice);

        void ajoute(int val);
        int enleve();
        bool vide();

    private:
        int *d_pile;
};

}

#endif // PILECHAINEE_H
