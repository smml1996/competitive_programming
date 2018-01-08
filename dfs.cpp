#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector< vector<int> > adjacencyList, int startNode){

    vector<bool> isVisited(adjacencyList.size(), false);
    stack<int> order;
    order.push(startNode);

    int temp;

    while(!order.empty()){
        temp = order.top();
        cout << temp << endl;
        order.pop();
        isVisited[temp] = true;

        for(int i = 0; i < adjacencyList[temp].size(); i++){
            if(!isVisited[adjacencyList[temp][i]]) order.push(adjacencyList[temp][i]);
        }

    }

}



int main(){

    vector< vector<int> > nodes;

    nodes.push_back(vector<int>());
    nodes.push_back(vector<int>());
    nodes.push_back(vector<int>());
    nodes.push_back(vector<int>());
    nodes.push_back(vector<int>());


    nodes[0].push_back(1);
    nodes[1].push_back(0);

    nodes[1].push_back(2);
    nodes[2].push_back(1);

    nodes[3].push_back(2);
    nodes[2].push_back(3);

    nodes[4].push_back(2);
    nodes[2].push_back(4);

    dfs(nodes,3);
    return 0;
}
