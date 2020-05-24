#ifndef NGRAM_H
#define NGRAM_H
#include <vector>
#include <iostream>

class Ngram
{
    public:
        Ngram(int n, std::vector<std::string>& ngram);
        virtual ~Ngram();
        std::vector<std::string> getNgram() const;
        friend std::ostream& operator<<(std::ostream& os, const Ngram& obj);

    private:
        int n;
        std::vector<std::string> ngram;
};

#endif // NGRAM_H
