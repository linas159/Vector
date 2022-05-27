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
        std::vector<int> numbers;
        std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

        numbers.push_back(42);
        std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

        Vector<int> numbers1;
        std::cout << "Initially, numbers1.empty(): " << numbers1.empty() << '\n';

        numbers1.push_back(42);
        std::cout << "After adding elements, numbers1.empty(): " << numbers1.empty() << '\n';
}