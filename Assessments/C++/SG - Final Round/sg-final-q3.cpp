#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int find_lcm(vector<int> vt)
{
    int lcm = vt.at(0);

    for (int i = 1; i < vt.size(); i++)
        lcm = ((vt[i] * lcm)) / (gcd(vt[i], lcm));
 
    return lcm;
}



long solution (vector<int> vt1, vector<int> vt2) {
    
    int max_vt1 = find_lcm(vt1);
    
    int min_vt2 = vt2.at(0);
    
    for (auto i: vt2) {
        
        if (i < min_vt2)
            min_vt2 = i;
    }
    
    vector<int> set_of_nos;
    
    int multiplier = 1;
    
    while (min_vt2 >= multiplier * max_vt1) {
        
        if (min_vt2 % (multiplier * max_vt1) == 0)
            set_of_nos.push_back(multiplier * max_vt1);
        
        multiplier++;
    }
    
    return set_of_nos.size();
}

int main(int argc, const char * argv[]) {
    
    ios_base :: sync_with_stdio(false);
    
    vector<int> vt1;
    vector<int> vt2;
    
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vt1.push_back(num);
    }
    
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        vt2.push_back(num);
    }
    // <--START HERE-->
    cout << solution(vt1, vt2) << endl;
    
    return 0;
}
