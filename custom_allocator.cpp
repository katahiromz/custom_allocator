#include "stdafx.h"

int main(void) {
    katahiromz::custom_string str;
    str = "OK\n";
    str += "OK\n";
    std::cout << str << std::endl;
    katahiromz::custom_vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    return 0;
}
