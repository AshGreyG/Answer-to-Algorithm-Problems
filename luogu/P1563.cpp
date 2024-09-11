#include <iostream>
#include <string>
#include <vector>

struct Toyman {
  public:
    std::string job_;
    int direction_;
    Toyman(int d, std::string j) : direction_(d), job_(j) {}
};

int main() {
    unsigned int toy_count = 0, command_count = 0;
    std::cin >> toy_count >> command_count;
    std::vector<Toyman> toys;

    // begin input

    for (int i = 1; i <= toy_count; ++i) {
        int temp_int;
        std::string temp_str;
        std::cin >> temp_int >> temp_str;
        toys.emplace_back(temp_int, temp_str);
    }

    // end input

    // begin calculate the final index

    unsigned int index = 0, self_dir, step;
    for (int i = 1; i <= command_count; ++i) {
        std::cin >> self_dir >> step;
        if (self_dir != toys[index].direction_) {
            index = (index + step) % toy_count;
            
            // when self_dir = 1 && toys[index].direction_ = 0
            //   or self_dir = 0 && toys[index].direction_ = 1
            // then counterclockwise  

        } else {
            index = (index + toy_count - step) % toy_count;

            // when self_dir = 1 && toys[index].direction_ = 1
            //   or self_dir = 0 && toys[index].direction_ = 0
            // then clockwise  

        }
    }

    // end calculate the final index : 1. notice that 1 <= step < toy_count
    //                               :    , so `index + toy_count - step > 0`
    
    std::cout << toys[index].job_;
    return 0;
}