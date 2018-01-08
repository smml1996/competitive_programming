#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*

 Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked and even Obelix had no luck opening them.

A little later they found a string s, carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s.

Prefix supposed that the substring t is the beginning of the string s; Suffix supposed that the substring t should be the end of the string s; and Obelix supposed that t should be located somewhere inside the string s, that is, t is neither its beginning, nor its end.

Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened.

You know the string s. Find the substring t or determine that such substring does not exist and all that's been written above is just a nice legend.

Input
You are given the string s whose length can vary from 1 to 106 (inclusive), consisting of small Latin letters.

Output
Print the string t. If a suitable t string does not exist, then print "Just a legend" without the quotes.
 */
string input;

vector<int> bordes;

int t = -1;


void getBordes(){

    bordes.push_back(0);
    int i =1,j=0;
    while(i<input.size()){
        while(j>0 && input.at(i)!= input.at(j)){
            j = bordes[j-1];
        }

        if(input.at(i)==input.at(j)){
            j++;
        }

        bordes.push_back(j);
        i++;

    }
}





int main() {

    cin >> input;

    getBordes();

    for(int i = 0; i< bordes.size()-1; i++){

        if(bordes[i]!= 0 && input.at(i) == input.at(input.size()-1) && bordes[i]<= bordes[bordes.size()-1]) {
            t =  max(t, bordes[i]);
        }

    }

    if(t!=-1){
        if(input.substr(0,t) == input.substr(input.size()-t)){
            cout<<input.substr(0,t)<<endl;
            return 0;
        }
    }

    cout << "Just a legend" << endl;


    return 0;
}
