#include <iostream>
#include <queue>
#include<vector>
#include<stack>
#include <algorithm>

using namespace std;
int m;
vector< pair<int, int> > objetos; // beneficio, peso

vector<int> beneficios;
vector<int> pesos;

bool f(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first) return true;
    if(a.first == b.first){
        if(a.second > b.second) return true;
        return false;
    }
    return false;
}

class Nodo{

    void getBeneficioEstimado(){
        int bacum =0, pacum = 0;
        for(int i = nivel; i < objetos.size(); i++){

            if(pacum + objetos[i].second < m - this->pact){
                pacum += objetos[i].second;
                bacum += objetos[i].first;
            }
        }

        this->be = bacum;
    }

    void getCotaSuperior(){
        if(this->isSolucion()){
            this->cs = 0;
            return;
        }
        queue<Nodo> daughters;
        daughters.push(*this);



        while(!daughters.empty()){
            Nodo y(daughters.front().isUsed, daughters.front().nivel+1, daughters.front().bact, daughters.front().pact);

            daughters.pop();
            for(int i =1; i>=0; i--){

                if(y.pact + i*pesos[y.nivel] <= m){
                    y.pact+= i*pesos[y.nivel];
                    y.bact+=i*beneficios[y.nivel];
                    y.isUsed[y.nivel] = i;
                    if(y.isSolucion()){

                        this-> cs = y.bact;
                        return;
                    }else{
                        daughters.push(y);
                    }
                }
            }

        }

        this-> cs = 0;

    }

public:
    vector<bool> isUsed;
    int nivel;
    int bact, pact;
    int ci = 0, be = 0, cs = 0;
    Nodo(vector<bool> isUsed, int nivel, int bact, int pact){
        this->nivel = nivel;
        this->isUsed = isUsed;
        this->bact = bact;
        this->pact = pact;
        getCotaSuperior();
        getBeneficioEstimado();
        this->ci = bact + be;

    }

    Nodo(const Nodo &c){
        this->nivel = c.nivel;
        this->bact = c.bact;
        this->pact = c.pact;
        this->ci = c.ci;
        this->be = c.be;
        this->cs = c.cs;
        this->isUsed = c.isUsed;
    }

    bool isSolucion(){
        return nivel == isUsed.size();
    }
};





stack<Nodo> LNV;


int main(){
int n;
cout << "Ingrese el numero de elementos: "; cin >> n;





    cout << "Ingrese el peso maximo: "; cin >> m;



    for(int i =0; i < n; i++){

        int temp, temp1;

        cin >> temp >> temp1;
        beneficios.push_back(temp);
        pesos.push_back(temp1);
        objetos.push_back(make_pair(temp, temp1));

    }

    sort(objetos.begin(), objetos.end(), f);

    cout << endl;

    Nodo raiz(vector<bool>(n, false),0,0,0);


    LNV.push(raiz);

    int c = raiz.ci;

    Nodo s(raiz);



    while(!LNV.empty()){


        Nodo x(LNV.top());
        LNV.pop();

        if(x.cs >= c){

            for(int i = 0; i<2;i++){
                 Nodo y(x.isUsed, x.nivel + 1, x.bact,x.pact);
                 y.isUsed[y.nivel-1] = i;
                 y.bact += i*beneficios[y.nivel-1];
                 y.pact += i*pesos[y.nivel-1];

                 if(y.pact <= m){

                    if(y.isSolucion() && y.bact > s.bact){
                        s = y;
                        c = max(c, y.bact);
                    }else if(!y.isSolucion() && y.cs > c){
                        LNV.push(y);
                        c = max(c, y.ci);

                    }
                 }

            }

        }
    }


        cout << "los objetos usados son: ";

        for(int i = 0; i< s.isUsed.size(); i++){

            if(s.isUsed[i])cout << i << " ";
        }

        cout << endl;

        cout << "el beneficio es: "<< s.bact<<endl;
        cout << "el peso es: "<< s.pact<<endl;

return 0;
}
