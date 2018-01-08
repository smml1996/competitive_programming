#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void selectionSort(vector<int> &elements){

    int unsortedPos;
    int temp;

    for(int i =0; i<elements.size()-1; i++){

        unsortedPos = i;
        temp = i;
        for(int j = i+1  ; j< elements.size(); j++){
            temp = min(elements[j], elements[temp]) == elements[j] ? j : temp;
        }
        swap(elements[unsortedPos], elements[temp]);
    }

}


int main(){



    vector<int> elements;
    srand (time(NULL));


    for(int i =0; i< 10; i++){
        elements.push_back(rand()%41+1);
    }


    selectionSort(elements);


    for (int j = 0; j < elements.size(); ++j) {
        cout << elements[j] << endl;
    }



}
