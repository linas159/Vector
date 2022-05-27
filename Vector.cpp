#include <iostream>
#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;


int main()
{
    Vector<int> v;
    for (int i = 0; i < 11; ++i)
    {
        v.push_back(i);
    }
    Vector<int> w;
    w.push_back(4);
    cout << w<<endl;
    w = v;
    cout << w << endl;
    w.erase(4);
    w.erase(7);
    cout << w<<endl;

    w.insert(4, 9);
    w.insert(4, 9);
    w.insert(4, 9);
    w.insert(4, 9);
    w.insert(4, 9);
    w.insert(4, 9);
    w.insert(4, 9);
    cout << w << endl;
    w.resize(4);
    cout << w << endl;
    w.resize(7);
    cout << w << endl;
    w.resize(9,5);
    cout << w << endl;
    Vector<int>a{ 1, 2, 4, 8, 16 };
    w.swap(a);
    cout << w<<endl;
    cout << a << endl;

        //Vector<int> nums{ 1, 2, 4, 8, 16 };
        //Vector<std::string> fruits{ "orange", "apple", "raspberry" };
        //Vector<char> empty;

        //// Print vector.
        //std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
        //std::cout << '\n';

        //// Sums all integers in the vector nums (if any), printing only the result.
        //std::cout << "Sum of nums: "
        //    << std::accumulate(nums.begin(), nums.end(), 0) << '\n';

        //// Prints the first fruit in the vector fruits, checking if there is any.
        //if (!fruits.empty())
        //    //std::cout << "First fruit: " << *fruits.begin() << '\n';

        //if (empty.begin() == empty.end())
        //    std::cout << "vector 'empty' is indeed empty.\n";
  
    return 0;
}