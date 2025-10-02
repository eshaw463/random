#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <unordered_set>
// #include<bits/stdc++.h>
#define ll long long
// using namespace std;

int main()
{
    std::vector<std::string> names;

    std::ifstream input("input.txt");

    std::string line; // current line
    while (std::getline(input, line))
    {
        names.push_back(line);
    }

    std::vector<int> value(names.size()); // vector of same size as names (index relationship)

    for (int a = 0; a < names.size(); a++)
    {
        for (int b = 0; b < names.size(); b++)
        {
            if (names[a] != names[b])
            {
                std::cout << "1. " << names[a] << " or " << "2. " << names[b] << std::endl;

                int choice;
                std::cin >> choice;

                if (choice == 1)
                {
                    value[a]++;
                }
                else
                {
                    value[b]++;
                }
            }
        }
    }



    input.close();


    std::ofstream outFile("output.txt"); 

    for(int c = 0; c < names.size(); c++){
        outFile << names[c] << "  -  " << value[c] << std::endl;
    }

    outFile.close();
    return 0;
}