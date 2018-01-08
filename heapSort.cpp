#include <iostream>
#include <vector>

using namespace std;

int n;

void heapify(vector<int> &elements, int index){

    int maximo;

    int left = 2*index+1;
    int right = 2*index+2;

    maximo = index;

    if(left < n && elements[left] > elements[index]) maximo = left;
    if(right < n && elements[right] > elements[maximo]) maximo = right;

    if(maximo != index){
        swap(elements[maximo], elements[index]);
        heapify(elements, maximo);
    }
}

void buildMaxHeap(vector<int> &elements){

    int i = (elements.size()-1) % 2 == 0 ? (elements.size()-3)/2 : (elements.size()-2)/2;

    for(; i >=0; i--){
        heapify(elements, i);
    }
}

void heapSort(vector<int> &elements){
    n = elements.size()-1;
    buildMaxHeap(elements);

    int i = elements.size()-1;
    for(; i >=0; i--){
        swap(elements[i], elements[0]);
        n-=1;
        heapify(elements, 0);
    }
}

int main(){

    vector<int> elements;
    srand (time(NULL));


    for(int i =0; i< 10; i++){
        elements.push_back(rand()%41+1);
    }

    heapSort(elements);


    for(int i =0; i<elements.size(); i++){
        cout << elements[i] << endl;
    }


    return 0;
}
