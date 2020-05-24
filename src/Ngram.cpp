#include "Ngram.h"

Ngram::Ngram(int n, std::vector<std::string>& ngram)
{
    if (ngram.size() == n)
    {
        this->n = n;
        this->ngram = ngram;
        return;
    }
    std::cerr << "wrong ngram size 1" << std::endl;
    }

std::vector<std::string> Ngram::getNgram() const
{
    return this->ngram;
}

std::ostream& operator<<(std::ostream& os, const Ngram& obj)
{
    os << "(" ;
    for (auto it = obj.ngram.begin();  it != obj.ngram.end(); ++it)
    {
        os << *it;
        if (it != obj.ngram.end() - 1)
        {
            os << ", ";
        }
    }
    os << ")" ;
    return os;
}

Ngram::~Ngram()
{
    //dtor
}
