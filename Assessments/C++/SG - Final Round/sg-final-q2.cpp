#include <vector>
#include <iostream>
#include <climits>

using namespace std;

void show_vector(vector<int> vt) {
    for (auto i: vt)
        cout << i << "\t";
}

int solution (vector<int> vt) {
    
    int min_dif = INT_MAX;
    
    for (int i = 0; i < vt.size(); i++)
    {
        for (int j = i + 1; j < vt.size(); j++)
        {
            if (vt.at(i) - vt.at(j) < min_dif && vt.at(i) - vt.at(j) >= 0)
                min_dif = vt.at(i) - vt.at(j);
        }
    }
    
    return min_dif;
}

int main(int argc, const char * argv[]) {
    
    ios_base :: sync_with_stdio(false);
    
    vector<int> vt;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vt.push_back(num);
    }
    
    // <--START HERE-->
    cout << (solution(vt)) << endl;
    
    return 0;
}
