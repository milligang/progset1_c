int kruskals(int a){
    return a;
}
/*
def kruskals_no_g(n,w):
  # nill = useless variable, so matches input/output of prim
  # w = dictionary
  # n = number of vertices
  X = set()
  mstweight = 0
  # create set for each vertex; assuming vertices are numbered 0 to n-1
  dus = ds.DisjointUnionSets(n)
  # sort edges by weight
  sort_w = {k: v for k, v in sorted(w.items(), key=lambda item: item[1])}
  for (i,j) in sort_w:
    if dus.find(i) != dus.find(j):
      X.add((i,j))
      dus.union(i,j)
      mstweight += sort_w[(i,j)]
      last_edge = (i,j)
  return mstweight
*/