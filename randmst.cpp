#include <tuple>
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

//clang++ -std=c++11 -Wall randmst.cpp -o randmst
//input to command line: ./randmst 0 numpoints numtrials dimension

using dict = vector<tuple<float, int, int> >;

// weights = pointer to 'dictionary' of edges in graph and corresponding weight
dict *weights = new dict;

// ********** disjoint union set class for kruskals **********
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
         int x_temp = x;
         x = y;
         y = x_temp;
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

// ********** implementation of graph algorithms **********

// we will need to make random numbers
float random_float(){
    // generate random float between 0 and 1, uniform
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

void dim_0(float n){
    // prune edges with weight above cut_off
    float cut_off = 20.0*(1.0/(n-1.0)-1.0/(exp2(n)));
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            float w = random_float();
            if (w < cut_off){
                weights->push_back(make_tuple(w,i,j));
            }
        }
    }
}

void dim_1(float n){
    float cut_off = 0.45 + pow(n, -0.25);
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
                float w = random_float();
                if (w < cut_off){
                    float num = log2(abs(i-2));
                    if ((num - round(num)) == 0){
                        weights->push_back(make_tuple(w, i, j));
                    }
                }
        }
    }
}

void dim_2(float n){
    int n_int = (int)n;
    float points[n_int][n_int];
    float cut_off = 3*pow(n, -0.5);
    for (int i = 0; i < n; i++){
        float x = random_float();
        float y = random_float();
        points[i][0] = x;
        points[i][1] = y;
    }
    for (int i = 0; i < n; i++){
        float x1 = points[i][0];
        float y1 = points[i][1];
        for (int j = 0; j < n; j++){
            float x2 = points[j][0];
            float y2 = points[j][1];
            float dist = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
            if (dist < cut_off){
                weights->push_back(make_tuple(dist, i, j));
            }
        }
    }
}

// ********** implementation of kruskals algorithm **********

float kruskals(int n){
    float mstweight = 0;
    set<pair<int,int> > x;
    // create set for each vertex; assuming vertices are numbered 0 to n-1
    DisjointUnionSets dus(n);
    // sort edges by weight
    sort(weights->begin(), weights->end());
    int edge_count = weights->size();
    // iterate through the edges
    for (int index = 0; index < edge_count; index++){
        tuple<float, int, int> edge = weights->at(index);
        float weight = get<0>(edge);
        int i = get<1>(edge);
        int j = get<2>(edge);
        if (dus.find(i) != dus.find(j)){
            x.insert(make_pair(i,j));
            dus.unite(i,j);
            mstweight += weight;
        }
    }
    return mstweight;
}

int timer(int n, int (*f)(int)){
    clock_t start = clock();
    int k = f(n);
    clock_t end = clock();
    double total_time = double(end - start) / CLOCKS_PER_SEC; // Convert to seconds
    cout << "Execution time:" << total_time << " seconds" << endl;
    cout << k << std::endl;
    return 0;
}

// ********** now find the mst! **********

int main(int argc, char *argv[]){
    // argc = number of command line args
    int flag = atoi(argv[1]); (void)flag;
    float numpoints = atof(argv[2]);
    int numtrials = atoi(argv[3]);
    int dimension = atoi(argv[4]);

    float total = 0;
    for (int i = 0; i < numtrials; i++){
        // select dimension (not sure how to make a variable a function in cpp)
        if (dimension == 0){
            dim_0(numpoints);
        }
        else if (dimension == 1){
            dim_1(numpoints);
        }
        else if (dimension == 2){
            dim_1(numpoints);
        }
        /*
        else if (dimension == 3){
            weights = dim_1(numpoints);
        }
        else if (dimension == 4){
            weights = dim_1(numpoints);
        }
        else { return -1; }
        */
       float mstweight = kruskals(numpoints);
       total += mstweight;
    }
    delete weights;
    float avg = total / numtrials;
    int points = floor(numpoints);
    printf("%f %d %d %d", avg, points, numtrials, dimension);
    return 0;
}