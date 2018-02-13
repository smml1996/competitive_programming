#include <iostream>
#include <vector>


using namespace std;

int log2(int n){

    int answer = 0;

    while(n > 0){
        answer++;
        n = n >> 1;
    }

    answer--;
    return answer;
}

int power2(int p){
    int base = 2;
    int answer = 1;

    while(p > 0){

        if(p % 2){
            answer*=base;
        }
        base*=base;
        p = p >> 1;
    }

    return answer;

}

int getArraySize(const int &n){

    return power2(log2(n)+2);

}

void initializeTree(int node, vector<int> &m , const vector<int> &n, int lim1, int lim2 ){


    if(lim1 == lim2){
        m[node] = lim1;
        return;
    }

    initializeTree(2*node, m, n, lim1, (lim1+lim2)/2);
    initializeTree(2*node + 1, m, n, (lim1+lim2)/2 + 1, lim2);

    if(n[ m[2*node]] <= n[m[2*node+1]])
        m[node] = m[2*node];
    else
        m[node] = m[2*node+1];


}


int query(int node, vector<int> m, vector<int> n, int lim1, int lim2, int q1, int q2){

    int ans1, ans2;

    if(q1 > lim2 || q2 < lim1) return -1;

    if(q1<= lim1 && q2 >= lim2)
        return m[node];

    ans1 = query(node*2, m, n, lim1, (lim1 + lim2) /2 , q1, q2);
    ans2 = query(2*node +1, m, n, (lim1 + lim2)/2 +1, lim2, q1, q2);

    if(ans1 == -1)
        return m[node] = ans2;
    if(ans2 == -1)
        return m[node] = ans1;
    if(n[ans1] <= n[ans2])
        return m[node] = ans1;
    return m[node] = ans2;

}

int main(){



    vector<int> n;

    n.push_back(2);
    n.push_back(4);
    n.push_back(3);
    n.push_back(1);
    n.push_back(6);
    n.push_back(7);
    n.push_back(8);
    n.push_back(9);
    n.push_back(1);
    n.push_back(7);

    vector<int> m(getArraySize(n.size()),-1);


    initializeTree(1, m, n, 0, n.size()-1);


    cout << query(1, m, n, 0, n.size()-1, 0,1) << endl;



    return 0;
}
