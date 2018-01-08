/*
You are given a tetrahedron. Let's mark its vertices with letters A, B, C and D correspondingly.
An ant is standing in the vertex D of the tetrahedron. The ant is quite active and he wouldn't stay idle. At each moment of time he makes a step from one vertex to another one along some edge of the tetrahedron. The ant just can't stand on one place.

You do not have to do much to solve the problem: your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should print it modulo 1000000007 (109 + 7).

Input
The first line contains the only integer n (1 ≤ n ≤ 107) — the required length of the cyclic path.

Output
Print the only integer — the required number of ways modulo 1000000007 (109 + 7).

*/

#include<iostream>

using namespace std;


long long ramas[10000002];
long long notValid[10000002];

int n;

long long getResto(long long D, long long d){

    long long q = D/d;

    long long resto = D%d;
    if(resto >=0) return resto;

    return D - (q-1)*d;
}
int main(){

    ramas[1] = 0;
    ramas[2] =3;

    ramas[3] = 9;

    notValid[1] = 0;
    notValid[2] = 0;
    notValid[3] =3;


    cin>>n;

    if(n<=3)
    {
        cout << ramas[n] - notValid[n]<<endl;
        return 0;
    }


    for(int i = 4; i <=n ; i++){
        ramas[i]= (ramas[i-1] +ramas[i-1]) % 1000000007 + ramas[i-1];
        ramas[i]%= 1000000007;
        notValid[i] = ramas[i-1] - notValid[i-1];
        notValid[i] %= 1000000007;
    }


    cout << getResto(ramas[n]-notValid[n] ,1000000007) << endl;

    return 0;
}
