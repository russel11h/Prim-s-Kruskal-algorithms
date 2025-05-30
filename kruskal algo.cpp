  #include <iostream>
#include <algorithm>
using namespace std;


struct Edge {
    int u, v, weight;
};


bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}


int parent[100];
int rankSet[100];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankSet[i] = 1;
    }
}

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unite(int x, int y) {
    int s1 = find(x);
    int s2 = find(y);

    if (s1 != s2) {
        if (rankSet[s1] < rankSet[s2]) {
            parent[s1] = s2;
        } else if (rankSet[s1] > rankSet[s2]) {
            parent[s2] = s1;
        } else {
            parent[s2] = s1;
            rankSet[s1]++;
        }
    }
}

int kruskalsMST(Edge edges[], int V, int E) {
    sort(edges, edges + E, compare);

    makeSet(V);

    int cost = 0;
    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            unite(u, v);
            cost += w;
            count++;
        }
    }

    return cost;
}

int main() {
    int V = 4;
    int E = 5;

    Edge edges[E] = {
        {0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
    };

    cout << "Minimum cost of MST = " << kruskalsMST(edges, V, E) << endl;

    return 0;
}
