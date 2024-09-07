#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace fmt;
int main()
{
    int i;
    vector<float> v(10, 0); // []()->float { return rand()/9.999;} );

    std::generate(v.begin(), v.end(), []() -> float
                  { return static_cast<float>(rand() ) / 1.23; });
    fmt::print("{}", v);
}