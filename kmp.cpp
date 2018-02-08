#include <iostream>
#include<string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


string pattern;

vector<int> preprocess(const string &pattern) {
    vector<int> result( pattern.size(), 0 );

    for( int i = 1; i < pattern.size(); i++ ) {

        if(pattern.at(result[i-1]) == pattern.at(i)){
            result[i] = result[i-1] + 1;
        }
    }

    return result;
}

int kmp(const string &text, const string &pattern)
{
    vector<int> preprocessTable = preprocess(pattern);
    int match_length;
    for(int i = 0; i < text.size() - pattern.size() + 1 ;)
    {
        match_length = 0;

        if(text.at(i) == pattern.at(0)) {
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

int naiveStringMatching(string text, string pattern)
{
    for(int i = 0; i < text.size() - pattern.size() + 1; i++)
    {
        for(int j = 0; j < pattern.size() && pattern.at(j) == text.at(i+j); j++ )
            if(j+1 == pattern.size()) return i;
    }

    return -1;
}

int main(){

    ofstream kmpFile;
    kmpFile.open("kmp.txt");

    ofstream naiveFile;
    naiveFile.open("naive.txt");
    clock_t t;

    for(int i =0; i< 1000; i++){

        pattern+='a';

    }



    for(int i =10000; i <= 1000000; i+=10000){

        string text = "";
        for(int j =0; j < i -pattern.size(); j++){

            if( (text.size() + 1) % pattern.size()== 0){
                text+='b';
            }else{
                text+='a';
            }
        }

        text+=pattern;

        t = clock();
        kmp(text, pattern);
        t = clock() - t;
        kmpFile << ( ( ( float ) t ) / CLOCKS_PER_SEC );
        kmpFile << endl;

        t = clock();
        naiveStringMatching(text, pattern);
        t = clock() - t;
        naiveFile << ( ( ( float ) t ) / CLOCKS_PER_SEC );
        naiveFile << endl;


    }

    kmpFile.close();
    naiveFile.close();


    return 0;
}

