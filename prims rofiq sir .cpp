#include <iostream>
using namespace std;
struct Edge {
   int u, v, val;
};
int main() {
   const int n = 8;
   int m[n][n] = {
       {99, 3, 99, 5, 2, 99, 99, 99},
       {3, 99, 5, 2, 99, 99, 99, 99},
       {99, 5, 99, 4, 99, 2, 99, 99},
       {5, 2, 4, 99, 99, 6, 3, 99},
       {2, 99, 99, 99, 99, 3, 99, 4},
       {99, 99, 2, 6, 3, 99, 4, 5},
       {99, 99, 99, 3, 99, 4, 99, 7},
       {99, 99, 99, 99, 4, 5, 7, 99}
   };
   Edge tree[n - 1];
   int visited[n] = {0};
   visited[2] = 1;
   int k = 0;
   while (k < n - 1) {
       int min = 99;
       int u = -1, v = -1;
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
               if (visited[i] && m[i][j] < min) {
                   if (visited[j] == 0) {
                       min = m[i][j];
                       u = i;
                       v = j;
                   }
               }
           }
       }
       if (u != -1 && v != -1) {
           tree[k].u = u;
           tree[k].v = v;
           tree[k].val = min;
           visited[v] = 1;
           m[u][v] = m[v][u] = 99; // mark the edge as used
           k++;
       }
   }
   // Output the result
   cout << "Minimum Spanning Tree Edges:\n";
   for (int i = 0; i < k; ++i) {
       cout << tree[i].u + 1 << " - " << tree[i].v + 1 << " = " << tree[i].val << endl;

   }
   return 0;
}
