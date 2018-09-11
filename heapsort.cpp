#include <iostream>
#include <vector>

using namespace std;

vector<int> elements;
int numElements;


void heapify(int i, int tam){
    int left, right, maximo;


    left = i*2 +1;
    right = i*2 +2;

    maximo = i;

    if(left < tam && elements[left] > elements[maximo])
        maximo = left;

    if(right < tam && elements[right] > elements[maximo])
        maximo = right;

    if(i!=maximo) {
        swap(elements[i], elements[maximo]);
        heapify(maximo, tam);
    }

}

void heapsort(){

    for(int i = elements.size()/2 +1; i >=0; i--)
        heapify(i, elements.size());

    for(int i = elements.size()-1; i>=0; i --){
        swap(elements[0], elements[i]);
        heapify(0, i);
    }

}

int main(){

    cin >> numElements;

    int temp;


    for(int i =0; i < numElements; i++){
        cin >> temp;
        elements.push_back(temp);
    }

    heapsort();

    for(int i =0; i < elements.size(); i++){
        cout << elements[i] << " ";
    }

    cout << endl;




    return 0;
}
