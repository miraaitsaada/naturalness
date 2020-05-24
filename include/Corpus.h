#ifndef CORPUS_H
#define CORPUS_H

#include <vector>
#include <map>
#include <iostream>

#include "Ngram.h"

/*struct NgramCompare
{
   bool operator() (const Ngram& ng1, const Ngram& ng2) const
   {
       return ng1.getNgram()[0] < ng2.getNgram()[0];
   }
};*/

class Corpus
{
    public:
        Corpus(std::vector<std::vector<std::string>> & corpus);
        virtual ~Corpus();
        std::vector<std::vector<std::string>> getCorpus();
        std::map<Ngram, int> getNgrams(int n);

    private:
        std::vector<std::vector<std::string>> corpus;
};

#endif // CORPUS_H
