#include <iostream>
#include <vector>


using namespace std;


vector<int> elements;

void add(int index, const int &value){

    while( index < elements.size()){

        elements[index] +=value;
        index += (index & (-index));
    }

}

int sum(int index){

    int answer = 0;
    while( index > 0){
        answer += elements[index];
        index-= (index & (-index));
    }
    return answer;
}

void printElements(){

    for(int i =1; i < elements.size(); i++){
        cout << elements[i] << " ";
    }

    cout << endl;
}

int main(){
    int numElements;

    cin >> numElements;

    elements = vector<int>(numElements+1, 0);

    int temp;
    for(int i =0; i < numElements; i++){
        cin >> temp;
        add(i+1, temp );
    }

    printElements();

    cout << sum(13) << endl; // debe ser 43

    add(5,2);

    printElements();

    return 0;
}
