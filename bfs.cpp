#include <iostream>
#include <queue>

using namespace std;

void bfs(vector< vector<int> > adjacencyList, int startNode){

    vector<bool> isVisited(adjacencyList.size(), false);
    queue<int> order;
    order.push(startNode);

    while(!order.empty()){

        cout << order.front() << endl;
        isVisited[order.front()] = true;

        for(int i = 0; i < adjacencyList[order.front()].size(); i++){
            if(!isVisited[adjacencyList[order.front()][i]]) order.push(adjacencyList[order.front()][i]);
        }

        order.pop();
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

    bfs(nodes,3);
    return 0;
}
