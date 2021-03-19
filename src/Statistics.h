#ifndef CPP_ECOSYSTEM_PROJECT_STATISTICS_H
#define CPP_ECOSYSTEM_PROJECT_STATISTICS_H

#include <vector>
#include <map>

using namespace std;

class Statistics{
    map<string,int> data;
    vector<string> headers;
    string csvFile;

public:
    Statistics(vector<string> behaviorAccessoriesCaptorsNames);
    ~Statistics();

    void modifyData(string key, bool increment);
    void saveData();
};

#endif //CPP_ECOSYSTEM_PROJECT_STATISTICS_H

