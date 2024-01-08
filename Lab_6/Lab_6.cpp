#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int vertices = 6;

// ????? ??????? ??????????
void printAdjacencyMatrix(vector<vector<int>>& adjacencyMatrix) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ????? ??????? ????????????? ??? ??????????????? ?????
void printIncidenceMatrix(vector<vector<int>>& incidenceMatrix) {
    cout << "\nIncidence Matrix:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < incidenceMatrix[0].size(); ++j) {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ????? ????? ??????? ?????
void printEdgeList(vector<pair<char, char>>& edges) {
    cout << "Edge List:" << endl;
    for (const auto& edge : edges) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }
}

// ????? ????? ??????? ??????????
void printAdjacencyList(vector<vector<int>>& adjacencyMatrix) {
    cout << "\nAdjacency List:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << char('A' + i) << ": ";
        unordered_set<int> neighbors;
        for (int j = 0; j < vertices; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                neighbors.insert(j);
            }
        }
        for (int neighbor : neighbors) {
            cout << char('A' + neighbor) << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

    vector<pair<char, char>> edges = {{'A', 'B'}, {'A', 'D'}, {'B', 'D'},
                                      {'B', 'E'}, {'B', 'F'}, {'C', 'F'}, {'C', 'E'},
                                      {'C', 'D'}};

    for (const auto& edge : edges) {
        int from = edge.first - 'A';
        int to = edge.second - 'A';
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1;  // ??? ??????????????? ????? ??????? ???????? ?????
    }

    printAdjacencyMatrix(adjacencyMatrix);

    // ????????? ??????? ?????????????
    vector<vector<int>> incidenceMatrix(vertices, vector<int>(edges.size(), 0));

    for (int i = 0; i < edges.size(); ++i) {
        int from = edges[i].first - 'A';
        int to = edges[i].second - 'A';

        incidenceMatrix[from][i] = 1;
        incidenceMatrix[to][i] = 1;
    }

    printIncidenceMatrix(incidenceMatrix);

    printEdgeList(edges);

    printAdjacencyList(adjacencyMatrix);

    return 0;
}

