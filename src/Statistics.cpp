//
// Created by aymeric on 12/03/2021.
//

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
    // check if the file named fileName exist or not
    return static_cast<bool>(ifstream(fileName));
}

bool writeCsvFile(string &fileName, map<string,int> data, vector<string> headers) {
    // write data in csv file
    lock_guard<mutex> csvLock(logMutex);
    fstream file;
    file.open (fileName, ios::out | ios::app);

    if (file) {
        // add a line to the csv file with the data
        for (vector<string>::iterator it = headers.begin(); it != headers.end(); ++it){
            file << data[*it] << ",";
        }
        file <<  std::endl;
        return true;
    }
    else {return false;}
}

bool writeHeadersCsvFile(string &fileName, vector<string> headers) {
    // write the headers to the csv file
    lock_guard<mutex> csvLock(logMutex);
    fstream file;
    file.open (fileName, ios::out | ios::app);

    if (file) {
        // add the headers to the file
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
    // save the headers add initialize them at 0
    for(vector<string>::iterator it = headers.begin(); it != headers.end(); ++it){
        data.insert(pair<string,int>(*it,0) );
    }

    // creation of the csv file
    time_t now = time(0);
    char* dt = ctime(&now);
    csvFile = strcat(dt, "-statistics.csv");

    // if the file does not exists, we create it and add the headers
    if(!fileExists(csvFile)){writeHeadersCsvFile(csvFile, headers);}
    else{cerr << "File " << csvFile << " already exist." << endl;}
}

void Statistics::modifyData(string key, bool increment){
    // modify the data contained in header with the key "key". If increment is at true the data takes +1,
    // else the data takes -1
    cout << key << ":" << increment << endl;
    if (increment){data[key] = data[key] + 1;}
    else{data[key] = data[key] - 1;}
}

void Statistics::saveData(){
    // save the current stage of headers in the csv file
    if (!writeCsvFile(csvFile, data, headers)) {
        std::cerr << "Failed to write to file: " << csvFile << "\n";
    }
}
Statistics::~Statistics( void ){
    cout << "Destruction of Statistics" << endl;
}
