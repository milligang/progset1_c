#include <stdio.h>
#include <stdlib.h>

//gcc -Wall randmst.c -o randmst
//input to command line: ./randmst 0 numpoints numtrials dimension

int main(int argc, char *argv[]){
    // argc = number of command line args
    int flag = atoi(argv[1]);
    int numpoints = atoi(argv[2]);
    int numtrials = atoi(argv[2]);
    int dimension = atoi(argv[2]);
    printf("%d", 1);
    return 0;
}
/*
def avg_weight(dim, n, trials):
    type_graph = graph_fxns[dim]
    avg = 0
    for _ in range(trials):
    w = type_graph(n)
    mstweight = algs.kruskals_no_g(n,w)
    avg += mstweight
    return (avg / trials)

avg = avg_weight(alg_flag, dimension, numpoints, numtrials)
print(avg, numpoints, numtrials, dimension)
*/