#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void mergesort(vector<int> &elements, int left, int right){

    if(left >= right) return;

    if(left+1 == right){
        if(elements[left] > elements[right]) swap(elements[left], elements[right]);
        return;
    }

    int middle = (left + right) /2;

    mergesort(elements, left, middle);
    mergesort(elements, middle+1, right);

    vector<int>temp;

    int i= left, j = middle+1;

    while(i<middle+1 && j<=right){
        if(elements[i]< elements[j]){
            temp.push_back(elements[i]);
            i++;
        }else{
            temp.push_back(elements[j]);
            j++;
        }
    }

    while(i<middle+1){
        temp.push_back(elements[i]);
        i++;
    }

    while(j<=right){
        temp.push_back(elements[j]);
        j++;
    }

    for(int k =left; k<=right; k++){

        elements[k]= temp[k-left];
    }
}


int main(){



    vector<int> elements;
    srand (time(NULL));


    for(int i =0; i< 10; i++){
        elements.push_back(rand()%41+1);
    }


    mergesort(elements, 0, elements.size()-1);


    for (int j = 0; j < elements.size(); ++j) {
        cout << elements[j] << endl;
    }



}
