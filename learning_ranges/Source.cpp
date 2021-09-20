#include<ranges>
#include <stdexcept>
#include<iostream>
#include<vector>

using namespace std;


int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto my_view = vec
        | std::ranges::views::filter([](int i) { return i % 2; })
        | std::ranges::views::transform([](int i) { return i * i; });

    for (auto elem : my_view)
    {
        std::cout << elem << std::endl;
    }

	return 0;
}