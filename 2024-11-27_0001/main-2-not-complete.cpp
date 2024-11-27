#include <cctype>  // Äëÿ std::ispunct è std::isspace
#include <utility>  // Äëÿ std::pair
#include <vector>
#include <iostream>
using std::cout;
using std::pair;
using std::vector;
using std::string;


class Sentence
{
public:
    Sentence(const string &text = "")
        : _text{ text }
        , _wordBoundaries{}
    {
        SetupWordBoundaries();
    }

    string::size_type GetWordCount() const
    {
        return _wordBoundaries.size();
    }

    //@TODO

private:
    string _text;
    vector<pair<string::size_type, string::size_type>> _wordBoundaries;

    void SetupWordBoundaries()
    {
        //@TODO
    }
};


int main()
{
    return 0;
}