#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

bool compar(int a, int b) {
    return (a%2 == 0) && (b%2 != 0);
}

int main() {
    vector<int> vec;
    int d;
    while ( cin >> d ) vec.push_back(d);
    cin.clear();

    sort(vec.begin(), vec.end(), compar);

    copy(vec.begin(),vec.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
}
