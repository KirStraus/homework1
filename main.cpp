#include "lib.h"
#include "hw_lib.h"
#include <iostream>
#include <algorithm>

int main(int, char **)
{
    std::string user_input = userInput();
    std::vector<std::vector<int>> ip_list = findIpAddrInString(user_input);
    std::sort(ip_list.begin(), ip_list.end(), reverse_sorting);
    print_full_ip_list(ip_list);
    ip_list_filtered(ip_list, false, 1);
    ip_list_filtered(ip_list, false, 46, 70);
    ip_list_filtered(ip_list, true, 46);
    //std::cout << "Version: " << version() << std::endl;

        return 0;
}