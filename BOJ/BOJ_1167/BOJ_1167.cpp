// #include<bits/stdc++.h>
// using namespace std;
// #define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

// int visited[100004];

// int main(){
//     fastio;

//     int n;
//     cin>>n;

//     vector<pair<int, int> > adj[n+1];

//     for(int i = 0; i < n; i++){
//         int node; 
//         cin>>node;

//         while(node!=-1){
//             int child, weight;
//             cin>>child;

//             if(child == -1) break;

//             cin>>weight;

//             adj[node].push_back({child, weight});
//             adj[child].push_back({node, weight});
//         }
//     }

//     queue<pair<int, int> > q;
//     q.push({1, 0});
//     visited[1] = true;

//     int ans = 0;
//     int totalTreeSum = 0;
//     int subMax = 0;
    
//     while(!q.empty()){
//         int now = q.front().first;
//         int cost = q.front().second;
//         q.pop();

//         cout<<"now : "<<now<<"\n";
        
//         int subtreeSum = 0;
//         int weight = 0;

//         for(int i = 0; i < adj[now].size(); i++){            
//             int next = adj[now][i].first;
//             weight = adj[now][i].second;
            
//             if(visited[next]) continue;
//             cout<<"next : "<<next<<"\n";

//             q.push({next, cost+weight});
//             visited[next] = true;
            
//             subtreeSum += weight;
//             subMax = max(subMax, weight);
//         }

//         if(subtreeSum <= 0) continue;

//         cout<<subtreeSum<<", "<<cost+subMax<<"\n";
//         ans = max(subtreeSum, cost+subMax);
//         subMax = 0; 
//     }
    
//     // cout<<"answer ; ";
//     cout<<ans<<"\n";

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge in the tree
struct Edge {
    int to;
    int weight;
};

// Function to find the diameter of the tree using BFS
int findTreeDiameter(vector<vector<Edge>>& adjList, int startNode) {
    int diameter = 0;

    // First BFS to find the farthest node from the starting node
    vector<bool> visited(adjList.size(), false);
    queue<pair<int, int> > q;
    q.push({startNode, 0});
    visited[startNode] = true;

    int farthestNode = startNode;
    int farthestDist = 0;

    while (!q.empty()) {
        int curNode = q.front().first;
        int curWeight = q.front().second;
        q.pop();

        if(curWeight > farthestDist){
            farthestDist = curWeight;
            farthestNode = curNode;
        }

        for(auto &edge : adjList[curNode]){
            int nextNode = edge.to;
            int nextWeight = edge.weight;

            if(!visited[nextNode]){
                q.push({nextNode, curWeight + nextWeight});
                visited[nextNode] = true;
            }
        }
    }

    // Second BFS to find the diameter using the farthest node
    visited.assign(adjList.size(), false);
    q.push({farthestNode, 0});
    visited[farthestNode] = true;

    
    while (!q.empty()) {
        int curNode = q.front().first;
        int curWeight = q.front().second;
        q.pop();

        diameter = max(diameter, curWeight);

        for(auto &edge : adjList[curNode]){
            int nextNode = edge.to;
            int nextWeight = edge.weight;
            
            if(!visited[nextNode]){
                q.push({nextNode, curWeight + nextWeight});
                visited[nextNode] = true;
            }
        }
    }

    return diameter;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int V;
    cin >> V;

    // Create an adjacency list to represent the tree
    vector<vector<Edge>> adjList(V + 1);

    // Read edge information and build the adjacency list
    for (int i = 1; i <= V; ++i) {
        int vertex;
        cin >> vertex;

        while (true) {
            int neighbor, weight;
            cin >> neighbor;
            if (neighbor == -1) break;
            cin >> weight;

            adjList[vertex].push_back({neighbor, weight});
            adjList[neighbor].push_back({vertex, weight});
        }
    }

    int diameter = findTreeDiameter(adjList, 1);
    cout << diameter << endl;

    return 0;
}


// 7
// 1 2 1 3 1 4 1 5 1 -1
// 2 1 1 6 5 7 5 -1
// 3 1 1 -1
// 4 1 1 -1
// 5 1 1 -1
// 6 2 5 -1
// 7 2 5 -1
// 정답: 10

// 출력: 7

// 12
// 1 2 1 3 1 -1
// 2 1 1 4 3 5 5 -1
// 3 1 1 6 1 -1
// 4 7 2 2 3 -1
// 5 2 5 8 4 9 2 -1
// 6 3 1 10 1 11 1 -1
// 7 4 2 -1
// 8 5 4 12 5 -1
// 9 5 2 -1
// 10 6 1 -1
// 11 6 1 -1
// 12 8 5 -1

// 결과:

// 24

// 답:

// 19

// 2

// 1 2 1 -1

// 2 1 1 -1

// 답: 1



// 5

// 1 5 1 -1

// 5 1 1 4 10 -1

// 4 3 10 5 10 -1

// 3 2 10 4 10 -1

// 2 3 10 -1



// answer: 31