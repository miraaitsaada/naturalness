#include "Model.h"

Model::Model(int n)
{
    if (n >= 0)
    {
        this->n = n;
        return;
    }
    std::cerr << "wrong ngram size 2" << std::endl;
}

int Model::getN()
{
    return this->n;
}

void Model::train(Corpus& corpus)
{

}

Model::~Model()
{
    //dtor
}
