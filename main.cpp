#include "lib.h"
#include "hw_lib.h"

#include <iostream>

int main (int, char **) {
    std::string user_input = userInput();
    std::vector <std::vector <int>> ip_list = findIpAddrInString(user_input);
    print_full_ip_list(ip_list);
    print_ip_list_with_value_in_first_byte(ip_list, 1);
    print_ip_list_with_value_in_first_and_second_byte(ip_list, 46, 70);
    print_ip_list_with_value_any_byte(ip_list, 46);
    
    //std::cout << "Version: " << version() << std::endl;

    return 0;
}
 
