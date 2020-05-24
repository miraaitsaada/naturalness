#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
#include <map>

#include "Ngram.h"
#include "Corpus.h"

class Model
{
    public:
        Model(int n);
        virtual ~Model();
        int getN();
        void train(Corpus& corpus);
        float eval(Corpus& corpus);

    private:
        int n;
        std::map<Ngram, int> nGramFreq;
};

#endif // MODEL_H
