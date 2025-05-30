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
   Edge tree[n - 1];  // edge koyta hte pare
   int visited[n] = {0}; // initialy 0 dore nisi
   visited[0] = 1;  // 1st node k starting nodr dore suru korlam
   int k = 0;       //koyta edge akn porjonto select hoise
   while (k < n - 1) {
       int min = 99;
       int u = -1, v = -1; //This means we haven't found any valid edge yet./If a better edge is found, we update u and v/If no valid edge is found, u and v stay -1.
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
               if (visited[i] && m[i][j] < min) {  //visited[i]: Check if node i is already in the MST./m[i][j] < min: Check if this edge has a smaller cost than what we’ve found so far.
                   if (visited[j] == 0) {          //Check if node j is NOT yet in the MST./We don’t want to form cycles, so we only connect to unvisited nodes.
                       min = m[i][j];
                       u = i;
                       v = j;
                   }
               }
           }
       }
       if (u != -1 && v != -1) {  //Only valid edges are added to the tree.
           tree[k].u = u;
           tree[k].v = v;
           tree[k].val = min;
           visited[v] = 1;        //Mark node v as visited, since it's now part of the MST.
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
