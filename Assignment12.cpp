#include <iostream>
#include <fstream> // file reading
#include <sstream> // string stream to parse csv
#include <vector> // to store list of matches
using namespace std;

// Class to hold sport match data
class Match {
public:
    string matchID; // unique ID for the match
    string date;    // Date for the match
    string sport;   // Type of sport( e,g,, Football, Basketball)
    string homeTeam; // Name of the home team
    string actualWinner; // actual winner of match

// Constructor to initialize a match object with data
    Match(string id, string d, string s, string h, string w) {
        matchID = id;
        date = d;
        sport = s;
        homeTeam = h;
        actualWinner = w;
    }
// Display function to print match information
    void display() const {
        cout << "Match ID: " << matchID
             << ", Date: " << date
             << ", Sport: " << sport
             << ", Home Team: " << homeTeam
             << ", Winner: " << (actualWinner.empty() ? "N/A" : actualWinner)
             << endl;
    }
};

int main() {
    ifstream file("matches.csv"); // open the CSV file
    string line; // String to hold each line
    vector<Match> matches; // Vector to store Match objects
// check if the file is opened successfully 
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;  // Exist with error code 
    }

    // Skip header
    getline(file, line);

    while (getline(file, line) && matches.size() < 10) {
        stringstream ss(line);
        string fields[10];

        // Extract up to 10 fields
        for (int i = 0; i < 10; ++i) {
            if (!getline(ss, fields[i], ',')) {
                fields[i] = ""; // fill missing with empty string
            }
        }

        //create a Match object using chosen fields
        Match m(fields[0], fields[1], fields[2], fields[3], fields[9]); // Match_ID, Date, Sport, Home_Team, Actual_Winner
        matches.push_back(m);
    }

    // Display all matches information 
    for (const Match& m : matches) {
        m.display();
    }

    return 0;
}