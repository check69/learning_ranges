#include<ranges>
#include <stdexcept>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>


using namespace std;


//int get_newline_position(const std::string& the_string)
//{
//    return *std::find(the_string.begin(), the_string.end(), '\n');
//}
//
//
//int cpp20_get_newline_position(const std::string& the_string)
//{
//    return *std::ranges::find(the_string, '\n');
//}
//
//int cpp20_get_newline_position2(const std::string& the_string)
//{
//    return *std::ranges::find(the_string.begin(), std::unreachable_sentinel, '\n');
//}
//
//
//int main()
//{
//    std::string string1{ "This is a \n Test" };
//
//    std::cout << "First function result: " << get_newline_position(string1) << std::endl;
//    std::cout << "Second function result: " << cpp20_get_newline_position(string1) << std::endl;
//    std::cout << "Third function result: " << cpp20_get_newline_position2(string1) << std::endl;
//
//    return 0;
//}


bool is_odd(int n)
{
    return n % 2;
}

int power_2(int n)
{
    return n * n;
}

vector<int> odd_numbers(const std::vector<int>& vec)
{
    vector<int> v;
    for (auto elem : vec)
    {
        if (is_odd(elem))
        {
            v.push_back(elem);
        }
    }

    return v;
}

void power_2_numbers(std::vector<int>& vec)
{
    std::transform(vec.begin(), vec.end(), vec.begin(), power_2);
}

void print_vector(auto& vec)
{
    for (const auto elem : vec)
        std::cout << elem << " ";
    std::cout << endl;
}

void view_example()
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> vec2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto filter_vec = odd_numbers(vec);
    print_vector(filter_vec);
    power_2_numbers(filter_vec);
    print_vector(filter_vec);


    auto my_view = vec2
        | std::ranges::views::filter(is_odd)
        | std::ranges::views::transform(power_2);

    print_vector(my_view);
}

void cpp17_sort_vector(vector<int>& vec)
{
    std::sort(vec.begin(), vec.end(), [](int a, int b) { return std::abs(a) < std::abs(b); });
}

void cpp20_sort_vector(auto& vec)
{
    std::ranges::sort(vec, [](int a, int b) { return std::abs(a) < std::abs(b); });
}

void cpp20_sort_vector_with_projection(auto& vec)
{
    std::ranges::sort(vec, {}, [](int i) { return std::abs(i); });
    std::ranges::sort(vec, std::ranges::less{}, [](int i) { return std::abs(i); });
}

void projection_example()
{
    std::vector<int> vec{ 1, 5, -7, -2, 9, -3, 4, 8, 3 };
    std::vector<int> vec2{ 1, 5, -7, -2, 9, -3, 4, 8, 3 };
    std::vector<int> vec3{ 1, 5, -7, -2, 9, -3, 4, 8, 3 };
    cpp17_sort_vector(vec);
    cpp20_sort_vector(vec2);
    cpp20_sort_vector_with_projection(vec3);

    print_vector(vec);
    print_vector(vec2);
    print_vector(vec3);
}

struct Task
{
    std::string description;
    int priority;
};

void projection_example2()
{
    std::vector<Task> tasks{
        {"Watch LaLiga matches", 10 }, {"Prepare this LED Talk", 9 },
        { "Watch Premier League matches", 8 }, { "Play Football Manager", 12 }
    };

    std::ranges::sort(tasks, std::ranges::greater{}, &Task::priority);
    auto print = [](Task& t) {
        std::cout << t.description << ", priority -> " << t.priority << std::endl;
    };

    std::ranges::for_each(tasks, print);
}

int main()
{
    // view_example();
    projection_example();
    projection_example2();
	return 0;
}