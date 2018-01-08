#include <iostream>
#include <vector>

#define modulus 1000000007

using namespace std;

/*
 * We saw the little game Marmot made for Mole's lunch. Now it's Marmot's dinner time and, as we all know, Marmot eats flowers. At every dinner he eats some red and white flowers. Therefore a dinner can be represented as a sequence of several flowers, some of them white and some of them red.

But, for a dinner to be tasty, there is a rule: Marmot wants to eat white flowers only in groups of size k.

Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could be very large, print it modulo 1000000007 (109 + 7).

Input
Input contains several test cases.

The first line contains two integers t and k (1 ≤ t, k ≤ 105), where t represents the number of test cases.

The next t lines contain two integers ai and bi (1 ≤ ai ≤ bi ≤ 105), describing the i-th test.

Output
Print t lines to the standard output. The i-th line should contain the number of ways in which Marmot can eat between ai and bi flowers at dinner modulo 1000000007 (109 + 7).
 */

vector<long long>ways(100002, -1);

vector<long long> sumas(100002, -1);

long long t, k;
long long a, b;

long long getResto(long long D, long long d){

    long long q = D/d;

    long long resto = D%d;
    if(resto >=0) return resto;

    return D - (q-1)*d;
}

void getWays(long long h){
    if(ways[h-1]==-1){
        getWays(h-1);
    }
    ways[h]= ways[h-1] + ways[h-k];

    ways[h] %= modulus;
    sumas[h] = ways[h] + sumas[h-1];
}


int main(){
    cin >> t>>k;

    ways[0]=0;
    sumas[0] = 0;

    for(int i =1; i<k; i++){

        ways[i]= 1;
        sumas[i] = 1 + sumas[i-1];
    }

    ways[k] = 2;
    sumas[k] = 2 + sumas[k-1];

    while(t--){

        cin>>a>>b;

        if(ways[a] == -1 || ways[b] == -1){
            getWays(b);
        }

        cout << getResto(sumas[b] - sumas[a-1], modulus) << endl;


    }


    return 0;
}
