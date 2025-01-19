#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool checkable(string line){
    int quotes = 0;
    int colons = 0;

    for(int i = 0; i < line.length(); i++){
        if (line[i] == '"'){
            quotes++;
        }
        if (line[i] == ':'){
            colons++;
        }

        if (quotes > 2 || colons > 1) return true;
    }

    return false;
}


int main() {
    ofstream outFile("output.txt");
    ifstream file("example.txt"); 

    
        string line;
        while (getline(file, line)) {

            string beginning = "";
            string changed = "";
            char end = '"';
            int whichQuote = 2; // if this mod 2 is 0, opening quote

        if (line.length() > 0 && checkable(line)){

            int i = 0;
            while(line[i] != '"'){
                i++;
            }
            beginning = line.substr(0, i+1); // collects: eventName_0:"  part of the text 

            changed = line.substr(i+1);
            changed = changed.substr(0, changed.length()-1);

            for (int j = 0; j < changed.length(); j++){
                

                if (changed[j] == '"'){
                    if (whichQuote%2 == 0) {
                        changed[j] = '{';
                        whichQuote++;
                    } else if (whichQuote%2 != 0) {
                        changed[j] = '}';
                        whichQuote++;
                    }
                } else if (changed[j] == ':'){
                    changed[j] = '^';
                }
            }


            outFile << beginning << changed << end << endl;
        } else {
            outFile << line << endl;
        }
        }

        // replace with a never used character
        // “ - begin q                  {   or   <
        // ” - end q                    }   or   >
        // ：- different :              ^
        // ’ - different '

        // then, in vscode or github, select & replace these with the correct characters (bc C++ doesn't like them)
        cout << "Program Finished!" << endl;
        file.close();
        outFile.close();

    return 0;
}