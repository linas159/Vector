#include <iostream>
#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void pushtestas1(int sz)
{
    auto start = chrono::high_resolution_clock::now();
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
    auto duration = duration_cast<microseconds>(chrono::high_resolution_clock::now() - start);
    cout << sz << " std::vector uztruko: " << float(duration.count()) / 1000000 << endl;
}
void pushtestas2(int sz)
{
    auto start = chrono::high_resolution_clock::now();
    Vector<int> v2;
    for (int i = 1; i <= sz; ++i)
        v2.push_back(i);
    auto duration = duration_cast<microseconds>(chrono::high_resolution_clock::now() - start);
    cout <<sz<< " Vector uztruko: " << float(duration.count()) / 1000000<<endl;
}

int main()
{
    for (int i = 10000; i <= 100000000; i *= 10)
    {
        pushtestas1(i);
    }
    cout << endl;
    for (int i = 10000; i <= 100000000; i *= 10)
    {
        pushtestas2(i);
    }
}