#include <bits/stdc++.h>
using namespace std;

#define V 6

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[6][6] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 5},
        {0, 0, 0, 6, 5, 0}};

    primMST(graph);

    return 0;
}

// #include <limits.h>

// #include <stdbool.h>

// #include <stdio.h>

// #define V 5

// int minKey(int key[], int mstSet[])
// {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++){

//         if (mstSet[v] == 0 && key[v] < min){

//             min = key[v]; min_index = v;
// 	 }	

//      }

//     return min_index;

// }

// int printMST(int parent[], int graph[V][V])
// {
//     int sum = 0;

//     printf("Edge \tWeight\n");
//     for (int i = 1; i < V; i++){
//         printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
//     }
// }
// void primMST(int graph[V][V])
// {

//    int parent[V];
//    int key[V];

//    int mstSet[V];

//    for (int i = 0; i < V; i++){
//        key[i] = INT_MAX; 
// 	mstSet[i] = 0;
//    }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int count = 0; count < V - 1; count++) {

//         int u = minKey(key, mstSet);
//         mstSet[u] = 1;

//         for (int v = 0; v < V; v++)
//            if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v])
// 		{parent[v] = u; key[v] = graph[u][v];}

//     }
//     printMST(parent, graph);

// }

// int main()
// {

//     /*int graph[V][V] = { { 0, 9, 5, 2, 0 },
//                         { 9, 0, 0, 6, 5 },
//                         { 5, 0, 0, 4, 5 },
//                         { 2, 6, 4, 0, 4 },
//                         { 0, 5, 5, 4, 0 } };

//      */
//       int graph[V][V] = { { 0, 2, 0, 6, 0 },
//                           { 2, 0, 3, 8, 5 },
//                           { 0, 3, 0, 0, 7 },
//                           { 6, 8, 0, 0, 9 },
//                           { 0, 5, 7, 9, 0 } };
 	
		


//     primMST(graph);
//     return 0;
// }