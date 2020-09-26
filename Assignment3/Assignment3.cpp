// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "BinaryTree.h"

using namespace std; 

int main()
{
    int myArray[100];
    ifstream inputFileStream("integers1.txt");
    string line;

    if (inputFileStream.is_open()) {
        int i = 0;
        while (getline(inputFileStream, line)) {

            std::istringstream lineStream(line);
            string data;
            getline(lineStream, data, '\n');
            myArray[i] = stoi(data);
            i++;
        }
        inputFileStream.close();
        cout << "\nThe data loaded successfully.\n\n";
    }
    else { cout << "\nUnable to open file\n\n"; }

    BinaryTree bTree;
    bTree.CreateTree(myArray);
    bTree.Search(175, myArray);
    bTree.Search(93, myArray);
    bTree.Search(195, myArray);
    bTree.Search(55, myArray);
    bTree.Search(145, myArray);
    bTree.Search(153, myArray);
    bTree.Search(45, myArray);
    bTree.Search(5, myArray);
    bTree.Search(25, myArray);
    bTree.Search(105, myArray);
    bTree.DestroyTree();
}
