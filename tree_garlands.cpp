#include <iostream>
#include <vector>

#define yes "YES"
#define no "NO"
using namespace std;


/*
 * Mishka is decorating the Christmas tree. He has got three garlands, and all of them will be put on the tree.
 * After that Mishka will switch these garlands on.

When a garland is switched on, it periodically changes its state — sometimes it is lit, sometimes not. Formally,
 if i-th garland is switched on during x-th second, then it is lit only during seconds x, x + ki, x + 2ki, x + 3ki and so on.

Mishka wants to switch on the garlands in such a way that during each second after switching the garlands on there
 would be at least one lit garland. Formally, Mishka wants to choose three integers x1, x2 and x3 (not necessarily
 distinct) so that he will switch on the first garland during x1-th second, the second one — during x2-th second, and
 the third one — during x3-th second, respectively, and during each second starting from max(x1, x2, x3) at least
 one garland will be lit.

Help Mishka by telling him if it is possible to do this!

Input
The first line contains three integers k1, k2 and k3 (1 ≤ ki ≤ 1500) — time intervals of the garlands.

Output
If Mishka can choose moments of time to switch on the garlands in such a way that each second after switching the
 garlands on at least one garland will be lit, print YES.

Otherwise, print NO.


 */
int getSecond(int k, int offset, int multiplier){

    return offset + k*multiplier;
}

bool isEverythingFilled(vector<bool> lights){

    for(int i = 0; i< lights.size(); i++){

        if(!lights[i])return false;
    }

    cout << yes <<endl;

    return true;
}

int getNextOffset(vector<bool> lights){

    for(int i =0; i<lights.size(); i++){
        if(!lights[i])return i;
    }
}




void turnOnLights(int k, vector<bool> &lights){
    int offset = getNextOffset(lights);
    int temp;
    for(int i =0; ; i++){

        temp = getSecond(k, offset, i);
        if(temp > lights.size())break;

        lights[temp] = true;
    }

}

int main(){

    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    int maximo = max(k1, max(k2,k3));
    int minimo = min(k1, min(k2, k3));
    int middle = k1+k2+k3 - maximo - minimo;
    vector<bool> series(2*maximo+1, false);

    turnOnLights(maximo, series);

    turnOnLights(middle, series);

    turnOnLights(minimo, series);


    if(isEverythingFilled(series))
        return 0;


    series = vector<bool>(2*maximo+1, false);

    turnOnLights(maximo, series);

    turnOnLights(minimo, series);

    turnOnLights(middle, series);

    if(isEverythingFilled(series))
        return 0;

    cout << no <<endl;

    return 0;
}
