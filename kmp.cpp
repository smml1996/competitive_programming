#include <iostream>
#include <vector>
#include <string>

using namespace std;
template <class T>
class KMP
{
    vector<int> preprocess(const vector<T> &pattern)
    {
        vector<int> result( pattern.size(), 0 );

        for( int i = 1; i < pattern.size(); i++ )
        {
            if(pattern.at(result[i-1]) == pattern.at(i))
            {
                result[i] = result[i-1] + 1;
            }
        }

        return result;
    }
public:

    int operator()(const vector<T> &text, const vector<T> &pattern)
    {
        vector<int> preprocessTable = preprocess(pattern);
        int match_length;
        for(int i = 0; i < text.size() - pattern.size() + 1 ;)
        {
            match_length = 0;

            if(text.at(i) == pattern.at(0))
            {
                match_length++;

                while( match_length < pattern.size() && pattern.at( match_length ) == text.at( i + match_length ) )
                    match_length++;

                if(match_length == pattern.size())
                    return i;
                i += match_length - preprocessTable[match_length -1];
            }else
                i++;
        }

        return -1;
    }

};

template <class T>
int naiveStringMatching(vector<T> text, vector<T> pattern)
{
    for(int i = 0; i < text.size() - pattern.size() + 1; i++)
    {
        for(int j = 0; j < pattern.size() && pattern.at(j) == text.at(i+j); j++ )
            if(j+1 == pattern.size()) return i;
    }

    return -1;
}

int main()
{
    /*
    vector<int> r = preprocess("abababca");


    for( int i = 0; i < r.size(); i++ )
        cout << r[i] <<  " ";

    cout << endl;
    */

    vector<char> text , pattern;

    text.push_back('c');
    text.push_back('b');
    text.push_back('a');
    text.push_back('b');
    text.push_back('c');
    text.push_back('a');
    text.push_back('b');
    text.push_back('a');

    pattern.push_back('a');
    pattern.push_back('b');
    pattern.push_back('a');
    KMP<char> kmp;
    cout << kmp(text, pattern) << endl;

    cout << naiveStringMatching(text, pattern) << endl;


    return 0;
}
