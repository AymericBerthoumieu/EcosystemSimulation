#include "Statistics.h"

#include <vector>

using namespace std;

int main() {
    string col1 = "col1";
    string col2 = "col2";
    string col3 = "col3";
    vector<string> headers{col1,col2,col3};

    Statistics st(headers);

    st.saveData();

    st.modifyData(col1, true);
    st.modifyData(col1, true);
    st.modifyData(col1, true);
    st.saveData();

    st.modifyData(col2, true);
    st.modifyData(col2, false);
    st.modifyData(col3, true);
    st.saveData();

    st.modifyData(col3, true);
    st.modifyData(col3, false);
    st.modifyData(col3, true);
    st.modifyData(col3, true);
    st.saveData();

}