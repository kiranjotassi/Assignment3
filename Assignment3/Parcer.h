#include<iostream>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;

class Parser
{

public:
    array<int> ParseIn();
};

array<int> Parser::ParseIn() {
    ifstream inputFileStream("jump.txt");
    string line;
    Athlete* a;

    if (inputFileStream.is_open()) {

        while (getline(inputFileStream, line)) {

            std::istringstream lineStream(line);
            string fName;
            string lName;
            string nationality;
            string distance;

            getline(lineStream, fName, ' ');
            if (fName == "FirstName") { continue; }
            getline(lineStream, lName, ' ');
            getline(lineStream, nationality, ' ');
            getline(lineStream, distance);
            replace(nationality.begin(), nationality.end(), '_', ' ');
            a = new Athlete(fName, lName, nationality, stod(distance));
            v->push_back(a);

        }

        inputFileStream.close();
        cout << "\nThe data loaded successfully.\n";

    }

    else { cout << "\nUnable to open file\n"; }
    return myArray;
}