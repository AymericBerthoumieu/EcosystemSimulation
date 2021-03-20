#include "Statistics.h"

#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;

mutex logMutex;

bool fileExists(string& fileName) {
    return static_cast<bool>(ifstream(fileName));
}

bool writeCsvFile(string &fileName, map<string,int> data, vector<string> headers) {
    lock_guard<mutex> csvLock(logMutex);
    fstream file;
    file.open (fileName, ios::out | ios::app);

    if (file) {
        for (vector<string>::iterator it = headers.begin(); it != headers.end(); ++it){
            file << data[*it] << ",";
        }
        file <<  std::endl;
        return true;
    }
    else {return false;}
}

bool writeHeadersCsvFile(string &fileName, vector<string> headers) {
    lock_guard<mutex> csvLock(logMutex);
    fstream file;
    file.open (fileName, ios::out | ios::app);

    if (file) {
        for (vector<string>::iterator it = headers.begin(); it != headers.end(); ++it){
            file << *it << ",";
        }
        file <<  std::endl;
        return true;
    }
    else {return false;}
}

Statistics::Statistics(vector<string> behaviorAccessoriesCaptorsNames){
    headers = behaviorAccessoriesCaptorsNames;
    for(vector<string>::iterator it = headers.begin(); it != headers.end(); ++it){
        data.insert(pair<string,int>(*it,0) );
    }

    // creation of the csv file
    time_t now = time(0);
    char* dt = ctime(&now);
    csvFile = strcat(dt, "-statistics.csv");

    if(!fileExists(csvFile)){writeHeadersCsvFile(csvFile, headers);}
    else{cerr << "File " << csvFile << " already exist." << endl;}
}

void Statistics::modifyData(string key, bool increment){
    if (increment){data[key] = data[key] + 1;}
    else{data[key] = data[key] - 1;}
}

void Statistics::saveData(){
    if (!writeCsvFile(csvFile, data, headers)) {
        std::cerr << "Failed to write to file: " << csvFile << "\n";
    }
}
Statistics::~Statistics(){
    cout << "Destruction of Statistics" << endl;
}

