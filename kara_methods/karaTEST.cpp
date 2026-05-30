#include <iostream>
#include <string>
#include <cmath>
#include <vector>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include<bits/stdc++.h>
#define ll long long
//using namespace std;
#include "karaG.cpp"


int main(){
    node root = {1};
    graph g(root);

    node b = {5};
    g.add_node(&b); // add nodes by address

    g.add_dbl_edge(root, b);
    g.add_edge(root,b, 80);

    // std::cout<< g.edge_cost(root,b) << std::endl;
    // std::cout<< g.is_edge(root,b) << std::endl;

    g.printStatus();

    return 0;
}