#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

// GRAPH implementation
// using adjacency matrix

// https://www.w3schools.com/dsa/dsa_data_graphs_implementation.php

// make something that works
// implement with ints and then comparable generics


struct node{
        int data;
        string name = ""; // not needed but an extra identifier for user to use
        int key = 0; // init without key, key set by graph
};

class graph {
    vector<node> nodes; //list of all nodes
    vector<vector<int>> gr;

    public:
        graph(node ROOT){
            ROOT.key = 0; // ensure key is 0 even if someone tried to override
            nodes.push_back(ROOT); //add root to data

            vector<int> inner(1);
            inner.push_back(0); // expand adj matrix. consider 0 to be no connection
            gr.push_back(inner);

            // vector.resize() would be helpful if we had an initial size for the 2D vector

        };

        /*
        ADDING NODES
        */

        void add_node(node* newNode){ // add nodes with ptr to be able to use them in other functions
            newNode->key = nodes.size(); // will always be the end
            nodes.push_back(*newNode);
            
            // resize adj matrix
            vector<int> inner(gr.size()); // new vector (0 initialized added to the end)
            gr.push_back(inner);
            for(int i = 0; i < gr.size(); i++){
                gr[i].push_back(0); // add 0 to the end of every vector
            }

        };


        /*
        ADDING EDGES BY NODE
        */

        void add_edge(node y, node x){ // from y to x ??? (or is this backwards)
            gr[y.key][x.key] = 1;
        }
        void add_edge(node y, node x, int cost){ // from y to x ??? (or is this backwards)
            gr[y.key][x.key] = cost;
        }

        void add_dbl_edge(node y, node x){ // no cost, assumed 1
            gr[y.key][x.key] = 1;
            gr[x.key][y.key] = 1;
        }
        void add_dbl_edge(node y, node x, int cost){ // both directions same cost
            gr[y.key][x.key] = cost;
            gr[x.key][y.key] = cost;
        }


        /*
        ADDING EDGES BY NODE NAME
        */

        void add_edge_by_name(string x, string y){
            int xKey = -1;
            int yKey = -1;

            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == x) xKey = nodes[i].key;
            }
            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == y) yKey = nodes[i].key;
            }
            gr[yKey][xKey] = 1;
        }
        void add_edge_by_name(string x, string y, int cost){
            int xKey = -1;
            int yKey = -1;

            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == x) xKey = nodes[i].key;
            }
            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == y) yKey = nodes[i].key;
            }
            gr[yKey][xKey] = cost;
        }
        void add_dbl_edge_by_name(string x, string y){
            int xKey = -1;
            int yKey = -1;

            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == x) xKey = nodes[i].key;
            }
            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == y) yKey = nodes[i].key;
            }
            gr[yKey][xKey] = 1;
            gr[xKey][yKey] = 1;
        }
        void add_dbl_edge_by_name(string x, string y, int cost){
            int xKey = -1;
            int yKey = -1;

            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == x) xKey = nodes[i].key;
            }
            for(int i = 0; i < nodes.size(); i++){
                if (nodes[i].name == y) yKey = nodes[i].key;
            }
            gr[yKey][xKey] = cost;
            gr[xKey][yKey] = cost;
        }


        /*
        CHECKING INFO
        */
        bool is_edge(node y, node x){
           return !(gr[y.key][x.key] == 0);
        }
        int edge_cost(node y, node x){
            return gr[y.key][x.key];
        }

        /*
        PRINTING
        */

        void printData(){
            int size = nodes.size();

            for(int i = 0; i < size; i++){
                if (i != (size - 1)) cout<< nodes[i].data << ", ";
                else cout<< nodes[i].data;
            }
            cout<< "\n";
        }

        void printMatrix(){
            int size = nodes.size();

            for(int y = 0; y < size; y++){
                for(int x = 0; x < size; x++){
                    cout << gr[y][x] <<", ";
                }
                cout << "\n";
            }
        }

        void printStatus(){
            std::cout<< "DATA:" << std::endl;
            printData();
            std::cout<< "ADJACENCY MATRIX:" << std::endl;
            printMatrix();
        }
    };


    // any algos I use should take in graph ptrs