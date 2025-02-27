#include <map>
#include <cmath>
#include <random>
#include <iostream>
#include "graphs.h"

using namespace std;
//clang++ -std=c++11 -Wall graphs.cpp -o graphs

// dict = sorted dictionary-like type
using dict = map<float, pair<int, int> >;

float random_float(){
    // generate random float between 0 and 1, uniform
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

dict dim_0(float n){
    // weights = dictionary of edges in graph, and corresponding weight
    dict weights;
    // prune edges with weight above cut_off
    float cut_off = 20.0*(1.0/(n-1.0)-1.0/(exp2(n)));
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            float w = random_float();
            if (w<cut_off || n <3){
                weights[w] = make_pair(i,j);
            }
        }
    }
    return weights;
}
/*
def hypercube_no_g(n):
    # output: number of vertices and weights dict
    weight = {}
    cut_off = 0.45 + 1/(n**(1/4))
    for i in range(n):
        for j in range(i+1,n):
            #print(abs(i - j))
                w = np.random.uniform(0, 1)
                if w < cut_off:
                    if math.log(abs(i - j), 2).is_integer():
                        weight[(i,j)] = w
    return weight

def uniformly_no_g(n):
    # output: number of vertices and weights dict
    weight = {}
    points = np.zeros((n,2))
    # remove large edges
    cut_off = 3/(n**(1/2))
    for i in range(n):
        x = np.random.uniform(0, 1)
        y = np.random.uniform(0, 1)
        points[i] = x,y
    for i in range(n):
        (x1,y1) = points[i]
        for j in range(i+1, n):
            x2,y2 = points[j]
            dist = np.sqrt((x2-x1)**2+(y2-y1)**2)
            if dist < cut_off:
                weight[(i,j)] = dist
    return weight
                                
def graph_cube3_no_g(n):
    # output: number of vertices and weights dict
    weight = {}
    points = np.zeros((n,3))
    # decide edges to delete
    cut_off = 2.2/(2**(math.log(n,8)))
    # np.sqrt(3)/math.log(n,5)
    #3/(2**(math.log(n,4)))
    for i in range(n):
        x = np.random.uniform(0, 1)
        y = np.random.uniform(0, 1)
        z = np.random.uniform(0, 1)
        points[i] = (x,y,z)
    for i in range(n):
        (x1,y1,z1) = points[i]
        for j in range(i+1,n):
            (x2,y2,z2) = points[j]
            dist = np.sqrt((x2-x1)**2+(y2-y1)**2+(z2-z1)**2)
            if dist < cut_off:
                weight[(i,j)] = dist
    return weight

def graph_cube4_no_g(n):
    # output: number of vertices and weights dict
    weight = {}
    points = np.zeros((n,4))
    cut_off = 1.7/(n**(1/4))
    # make graph
    w1 = np.random.uniform(0, 1)
    x1 = np.random.uniform(0, 1)
    y1 = np.random.uniform(0, 1)
    z1 = np.random.uniform(0, 1)
    points[0] = (w1,x1,y1,z1)
    for j in range(1, n):
        w2 = np.random.uniform(0, 1)
        x2 = np.random.uniform(0, 1)
        y2 = np.random.uniform(0, 1)
        z2 = np.random.uniform(0, 1)
        points[j] = (w2,x2,y2,z2)
        dist = np.sqrt((w2-w1)**2+(x2-x1)**2+(y2-y1)**2+(z2-z1)**2)
        if dist < cut_off:
            weight[(0,j)] = dist
    for i in range(1,n):
        (w1,x1,y1,z1) = points[i]
        for j in range(i+1, n):
            (w2,x2,y2,z2) = points[j]
            dist = np.sqrt((w2-w1)**2+(x2-x1)**2+(y2-y1)**2+(z2-z1)**2)
            if dist < cut_off:
                weight[(i,j)] = dist
    return weight
*/