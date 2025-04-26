#include <iostream>
#include <string>
#include <cmath>
#include <vector>
// #include<bits/stdc++.h>
#define ll long long
using namespace std;

int game[20][40];
int nextt[20][40];
void display();
void generate();

int main()
{

    // setup lol

        game[10][10] = 1;
        game[11][10] = 1;
        game[12][10] = 1;
        game[12][9] = 1;
        game[11][8] = 1;

        
        display();
        cout << "=====" << endl;
    //

    for(int n = 0; n < 30; n++){
        generate();
        display();
        cout << "=====" << endl;
    }
    

    return 0;
}

void display()
{

    for (int i = 0; i < 20; i++)
    {
        for (int k = 0; k < 40; k++)
        {

            cout << game[i][k];
        }
        cout << "" << endl;
    }
}

void generate()
{
    // dead cell = 0
    // alive cell = 1

    for (int i = 0; i < 20; i++)
    {
        for (int k = 0; k < 40; k++)
        {
            nextt[i][k] = 0;

            int around = 0;

            try
            {
                if (game[i - 1][k - 1] == 1)
                    around++;
                if (game[i - 1][k + 1] == 1)
                    around++;
                if (game[i + 1][k + 1] == 1)
                    around++;
                if (game[i + 1][k - 1] == 1)
                    around++;
                if (game[i][k + 1] == 1)
                    around++;
                if (game[i + 1][k] == 1)
                    around++;
                if (game[i - 1][k] == 1)
                    around++;
                if (game[i][k - 1] == 1)
                    around++;
            }
            catch (int e)
            {
                // dead zone around edges lol
            }

            if (around < 2)
                nextt[i][k] = 0;
            else if (around > 3)
                nextt[i][k] = 0;
            else if (game[i][k] == 0 && around == 3)
                nextt[i][k] = 1;
            else if (game[i][k] == 1)
            nextt[i][k] = 1;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int k = 0; k < 40; k++)
        {

            game[i][k] = nextt[i][k];
        }
    }

}