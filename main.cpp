#include <iostream>
#include "Ngram.h"
#include "Model.h"
#include "Corpus.h"

int main(int argc, char* argv[])
{
    std::vector<std::string>::iterator ngramIterator;
    Ngram* ngram = nullptr;
    std::vector<std::string> seq;
    seq.push_back("je");
    seq.push_back("suis");
    seq.push_back("malade");

    ngram = new Ngram(3, seq);
    std::cout << *ngram << std::endl;

    delete(ngram);

    //////////////////////////
    Model* model = nullptr;
    model = new Model(5);
    std::cout << model->getN() << std::endl;

    delete(model);

    //////////////////////////
    std::vector<std::vector<std::string>> documents;
    std::vector<std::string> doc;
    doc.push_back("a");
    doc.push_back("b");
    doc.push_back("c");
    doc.push_back("a");
    doc.push_back("b");
    doc.push_back("c");
    documents.push_back(doc);

    doc.clear();
    doc.push_back("z");
    doc.push_back("y");
    doc.push_back("w");
    documents.push_back(doc);

    Corpus* corpus = nullptr;
    corpus = new Corpus(documents);
    std::cout << corpus->getCorpus().size() << std::endl;

    std::cout << " " << std::endl;

    std::map<Ngram, int> ngrams = corpus->getNgrams(3);

    for (auto ngram_it = ngrams.begin(); ngram_it != ngrams.end(); ++ngram_it)
    {
        std::cout << ngram_it->first << " - " << ngram_it->second << std::endl;
    }

    delete(corpus);

    return 0;
}
