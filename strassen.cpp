#include <iostream>
#include <vector>

using namespace std;


void rellenarMatrix(vector< vector<int> > A, vector< vector<int> > &a11,vector< vector<int> > &a22,vector< vector<int> > &a21,vector< vector<int> > &a12, int n){

    int temp;
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            temp = A[i][j];
            if ( i < (n/2)){
                if(j  < (n/2)){
                    a11[i][j] = temp;
                }else{
                    a12[i][j - (n/2)] = temp;

                }
            }else if(j < (n/2)){
                a21[i - (n/2)][j] = temp;
            }else{
                a22[i - (n/2)][j- (n/2)] = temp;
            }
        }

    }
}

void imprimir(vector< vector<int> > t){

    for(int i = 0; i< t.size(); i++){

        for(int j = 0; j< t.size(); j++){
            cout << t[i][j] << " ";
        }

        cout << endl;
    }

}

vector< vector<int> > sumar(vector< vector<int> > A, vector< vector<int> > B){
    vector< vector<int> > answer(A.size(), vector<int>(A.size()));

    for(int i = 0; i< A.size(); i++){

        for(int j =0; j < A.size(); j++){

            answer[i][j] = A[i][j] + B[i][j];
        }
    }

    return answer;

}

vector< vector<int> > restar(vector< vector<int> > A, vector< vector<int> > B){
    vector< vector<int> > answer(A.size(), vector<int>(A.size()));

    for(int i = 0; i< A.size(); i++){

        for(int j =0; j < A.size(); j++){

            answer[i][j] = A[i][j] - B[i][j];
        }
    }

    return answer;

}

int getCelda(vector< vector<int> >  A, vector< vector<int> > B, int i, int j){
    int answer = 0;
    for( int h =0; h < A.size(); h++){
        answer+= A[i][h]*B[h][j];
    }

    return answer;
}

vector< vector<int> > multiplicar(vector< vector<int> > A, vector< vector<int> > B){
    vector< vector<int> > answer(A.size(), vector<int>(B[0].size()));
    for(int i = 0; i < A.size(); i++){

        for(int j = 0; j < B[0].size(); j++){
            answer[i][j] = getCelda(A, B, i, j);
        }

    }

    return answer;
}




vector< vector<int> > strassen(vector< vector<int> > a, vector< vector<int> > b, int n){

    if(a.size() <=2){
        vector< vector<int> >t =  multiplicar(a,b);
        return t;
    }

    vector< vector<int> > a11( n/2, vector<int>(n/2) ) , a22(n/2, vector<int>(n/2)), a21(n/2, vector<int>(n/2)),a12(n/2, vector<int>(n/2));
    vector< vector<int> > b11( n/2, vector<int>(n/2) ), b22(n/2, vector<int>(n/2)), b21(n/2, vector<int>(n/2)) , b12(n/2, vector<int>(n/2));

    rellenarMatrix(a, a11, a22, a21, a12,n);

    rellenarMatrix(b, b11, b22, b21, b12,n);


    vector< vector<int> > p = strassen(sumar(a11, a22), sumar(b11, b22), n/2);
    vector< vector<int> > q = strassen(sumar(a21, a22),b11, n/2);
    vector< vector<int> > r = strassen(a11, restar(b12, b22), n/2);

    vector< vector<int> > s = strassen(a22, restar(b21, b11), n/2);

    vector< vector<int> > t = strassen(sumar(a11, a12), b22, n/2);
    vector< vector<int> > u = strassen(restar(a21, a11), sumar(b11,b12),n/2);
    vector< vector<int> > v = strassen(restar(a12, a22), sumar(b21,b22), n/2);


    vector< vector<int> > c11 = sumar(restar(sumar(p,s), t), v);
    vector< vector<int> > c12 = sumar(r,t);
    vector< vector<int> > c21 = sumar(q,s);
    vector< vector<int> > c22 = sumar(restar(sumar(p,r), q), u);

    vector< vector<int> > answer( n, vector<int>(n) );

    int temp;
    for(int i = 0; i < n ; i++){

        for(int j = 0; j < n; j++){
            if(i < (n/2)){

                if(j < (n/2))
                    temp = c11[i][j];
                else
                    temp = c12[i][j - (n/2)];
            }else if( j < (n/2)){
                temp = c21[i - (n/2)][j];
            }else{
                temp = c22[i -(n/2)][j - (n/2)];
            }

            answer[i][j] = temp;
        }
    }

    return answer;
}


int main(){
    int n; // tamaño de las matrices



    cout << "ingrese n: " << endl;

    cin >> n;

    vector< vector<int> > a(n, vector<int>(n));
    vector< vector<int> > b(n, vector<int>(n));

    cout << "ingrese a: " << endl;

    int temp;
    for(int i =0; i< n; i++){

        for(int j =0; j< n; j++){
            cin >> temp;
            a[i][j] = temp;
        }
    }

    cout << "ingrese b: " << endl;

    for(int i =0; i< n; i++){

        for(int j =0; j< n; j++){
            cin >> temp;
            b[i][j] = temp;
        }
    }

    vector< vector<int> > s = strassen(a,b,n);

    cout << endl << "RESPUESTA: " << endl;
    for(int i =0; i< s.size(); i++){

        for(int j =0; j< s.size(); j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
