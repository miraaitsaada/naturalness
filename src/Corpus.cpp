#include "Corpus.h"

namespace std
{
    template<> struct less<Ngram>
    {
       bool operator() (const Ngram& ng1, const Ngram& ng2) const
       {
           return ng1.getNgram().front() < ng2.getNgram().front();
       }
    };
}

Corpus::Corpus(std::vector<std::vector<std::string>>& corpus)
{
    this->corpus = corpus;
}

std::vector<std::vector<std::string>> Corpus::getCorpus()
{
    return this->corpus;
}

std::map<Ngram, int> Corpus::getNgrams(int n)
{
    std::map<Ngram, int> ngrams;
    std::map<Ngram, int>::iterator ngram_it = ngrams.begin();

    for(auto document_it = this->corpus.begin(); document_it != this->corpus.end(); ++document_it)
    {
        for (auto token_it = document_it->begin(); token_it != document_it->end() - n + 1; ++token_it)
        {
            std::vector<std::string> tmp_ngram;
            for (auto it = token_it; it != token_it + n; ++it)
            {
                tmp_ngram.push_back(*it);
            }

            /*for (auto it = tmp_ngram.begin();  it != tmp_ngram.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;*/


            Ngram ngram (n, tmp_ngram);
            /*std::map<Ngram, int, NgramCompare>::iterator it = ngrams.find(ngram);

            if (it != ngrams.end())
            {
                it->second++;
            }
            else {
                ngrams.insert(std::make_pair(ngram, 1));
            }*/

            //if (ngrams.find(ngram) != ngrams.end())
            if (ngrams.count(ngram))
            {
                ngrams[ngram]++;
            }
            else
            {
                ngrams.insert(ngram_it, std::pair<Ngram, int>(ngram, 1));
            }
        }
    }
    return ngrams;
}

Corpus::~Corpus()
{
    //dtor
}
