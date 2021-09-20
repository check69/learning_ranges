#include<ranges>
#include <stdexcept>
#include<vector>

using namespace std;
namespace view = ranges::views;


int main()
{
    std::vector<int> vec{1, 2, 3, 4};
    auto my_view = vec | view::reverse;
	return 0;
}