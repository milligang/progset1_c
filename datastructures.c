/*
class DisjointUnionSets:
   def __init__ (self, n):
      self.rank = np.zeros(n)
      self.parent = np.arange(0,n)
   
   def find(self, x):
      p = self.parent[x]
      if p == x:
         return x
      else:
         return self.find(p)
   
   def link(self, x, y):
      rank_x = self.rank[x]
      rank_y = self.rank[y]
      if rank_x > rank_y:
         x, y = y, x
      if rank_x == rank_y:
         self.rank[y] += 1
      self.parent[x] = y
   
   def union(self, x, y):
      self.link(self.find(x), self.find(y))
*/