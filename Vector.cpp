#include <iostream>
#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> foo(3, 100);
    std::vector<int> bar(5, 200);

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';

    Vector<int> foo1(3, 100);
    Vector<int> bar1(5, 200);

    foo1.swap(bar1);

    std::cout << "foo1 contains:";
    for (unsigned i = 0; i < foo1.size(); i++)
        std::cout << ' ' << foo1[i];
    std::cout << '\n';

    std::cout << "bar1 contains:";
    for (unsigned i = 0; i < bar1.size(); i++)
        std::cout << ' ' << bar1[i];
    std::cout << '\n';
}