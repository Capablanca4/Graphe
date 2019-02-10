<<<<<<< HEAD
#include "PileChainee.h"

namespace Graphe{

PileChainee::PileChainee(int nbElement):d_pile{}
{
    d_pile = new int[nbElement];
    d_pile[0]=0;
}

PileChainee::~PileChainee()
{
    delete[] d_pile;
}

int PileChainee::pile(int indice){
    return d_pile[indice];
}

bool PileChainee::vide(){
    return d_pile[0]==0;
}

void PileChainee::ajoute(int val){
    d_pile[val]=d_pile[0];
    d_pile[0]=val;
}

int PileChainee::enleve(){
    int tamp=d_pile[0];
    d_pile[0]=d_pile[d_pile[0]];
    return tamp;
}

}
=======
#include "PileChainee.h"

namespace Graphe{

PileChainee::PileChainee(int nbElement):d_pile{}
{
    d_pile = new int[nbElement];
    d_pile[0]=0;
}

PileChainee::~PileChainee()
{
    delete[] d_pile;
}

int PileChainee::pile(int indice){
    return d_pile[indice];
}

bool PileChainee::vide(){
    return d_pile[0]==0;
}

void PileChainee::ajoute(int val){
    d_pile[val]=d_pile[0];
    d_pile[0]=val;
}

int PileChainee::enleve(){
    int tamp=d_pile[0];
    d_pile[0]=d_pile[d_pile[0]];
    return tamp;
}

}
>>>>>>> d434ec828a08d278348a1958d3e0e88a78f46394
