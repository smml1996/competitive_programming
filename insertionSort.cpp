#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void insertionSort(vector<int> &elements){

    for(int i =1; i<elements.size(); i++){
        for(int j = i; j>=0 ; j--){
            if(elements[j] < elements[j-1]){
                swap(elements[j], elements[j-1]);
            }
        }
    }

}


int main(){



    vector<int> elements;
    srand (time(NULL));


    for(int i =0; i< 10; i++){
        elements.push_back(rand()%41+1);
    }


    insertionSort(elements);


    for (int j = 0; j < elements.size(); ++j) {
        cout << elements[j] << endl;
    }



}
