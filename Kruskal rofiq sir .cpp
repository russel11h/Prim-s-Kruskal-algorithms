#include <iostream>
using namespace std;

struct ES {
    int u;    // vertex u
    int v;    // vertex v
    int val;  // edge value
};

int parent[10]; // For union-find

// Find function for union-find
int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

// Union function for union-find
int uni(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        parent[b] = a;  // Union
        return 1;
    }
    return 0;
}

int main() {
    int m[8][8] = {
        {0,3,0,5,2,0,0,0},
        {3,0,7,8,0,0,0,0},
        {0,7,0,10,2,0,0,0},
        {5,8,10,0,3,0,2,0},
        {2,0,2,3,0,7,5,5},
        {0,0,0,0,7,0,0,6},
        {0,0,0,2,5,0,0,4},
        {0,0,0,0,5,6,4,0}
    };

    ES EL[40]; // List of edges
    int k = 0;

    // Step 1: Store non-zero edges into EL
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (m[i][j] != 0 && m[i][j] == m[j][i] && i < j) {
                EL[k].u = i;
                EL[k].v = j;
                EL[k].val = m[i][j];
                k++;
            }
        }
    }

    // Step 2: Sort EL using insertion sort (ascending order)
    for (int i = 1; i < k; ++i) {
        ES temp = EL[i];
        int j = i - 1;
        while (j >= 0 && EL[j].val > temp.val) {
            EL[j + 1] = EL[j];
            --j;
        }
        EL[j + 1] = temp;
    }

    // Step 3: Initialize parent array
    for (int i = 0; i < 8; ++i) {
        parent[i] = i;
    }

    // Step 4: Kruskal’s Algorithm
    cout << "Selected edges for tree are:\n";
    int sum;
    for (int i = 0; i < k; ++i) {
        int u = find(EL[i].u);
        int v = find(EL[i].v);
        if (uni(u, v)) {
            cout << "(" << EL[i].u + 1 << "," << EL[i].v + 1 << ") = " << EL[i].val << endl;
            sum= sum+EL[i].val;
        }
    }
    cout<<"Total cost :"<<sum<<endl;

    return 0;
}

