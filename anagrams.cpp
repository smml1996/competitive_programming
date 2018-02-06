#include <iostream>
#include <vector>
#include <string>

using namespace std;


string ss1, ss2;

int main(){

    int tt;

    cin >> tt;

    while(tt--) {
        cin >> ss1 >> ss2;
        vector<int> s1(26*2, 0);
        vector<int> s2(26*2, 0);


        int temp;
        for (int i = 0; i < ss1.size(); i++) {
            if (ss1.at(i) >= 97) {
                temp = ss1.at(i) - 97;
                s1[temp]++;
            } else {
                s1[ss1.at(i) - 65]++;
            }
        }

        for (int i = 0; i < ss2.size(); i++) {
            if (ss2.at(i) >= 97) {
                temp = ss2.at(i) - 97;
                s2[temp]++;
            } else {
                s2[ss2.at(i) - 65]++;
            }

        }

        int answer = 0;

        for (int i = 0; i < s1.size(); i++) {

            answer += s1[i] > s2[i] ? s1[i] - s2[i] : s2[i] - s1[i];
        }

        cout << answer << endl;
    }

    return 0;
}
