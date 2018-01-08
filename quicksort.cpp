#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quicksort(vector<int> &elements, int left, int right){

    if(left >= right) return;

    if(left+1 == right){
        if(elements[left]> elements[right]) swap(elements[left], elements[right]);
        return;
    }

    int pivote = rand() % (right-left);


    int leftLimit = left;
    for(int i =left; i <=right; i++){

        if(elements[i]<elements[pivote]){
            swap(elements[i], elements[leftLimit]);

            if(leftLimit == pivote){
                pivote =i;
            }
            leftLimit++;
        }
    }

    quicksort(elements, left, pivote);
    quicksort(elements, pivote, right);

}


int main(){



    vector<int> elements;
    srand (time(NULL));


    for(int i =0; i< 10; i++){
        elements.push_back(rand()%41+1);
    }


    quicksort(elements, 0, elements.size()-1);


    for (int j = 0; j < elements.size(); ++j) {
        cout << elements[j] << endl;
    }



}
