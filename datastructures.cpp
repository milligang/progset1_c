#include <iostream>
#include <vector>
using namespace std;

class DisjointUnionSets{
   vector<int> rank, parent;
public:
   DisjointUnionSets(int n) {
      // create vector for rank and parent
      rank.resize(n, 0);
      parent.resize(n);
      // everything is its own parent to begin with
      for (int i = 0; i < n; i++) {
         parent[i] = i;
      }
   }
   int find(int x){
      // return the parent of x
      int p = parent[x];
      if (p == x){
         return p;
      }
      // if x is not its own parent, recursion
      return find(parent[p]);
   }
   void link(int x, int y){
      int rank_x = rank[x];
      int rank_y = rank[y];
      if (rank_x > rank_y){
         // swap x and y
         x, y = y, x;
      }
      if (rank_x == rank_y){
         rank[y]++;
      }
      parent[x] = y;
   }
   void unite(int x, int y){
      link(find(x), find(y));
   }
};