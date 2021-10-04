#include <iostream>
#include <vector>

std::string userInput();

std::vector <std::vector <int>> findIpAddrInString(std::string srting_user_input);

std::vector <int>  ipAddrStrToVectorInt(std::string ip_addr_str);

bool reverse_sorting(std::vector <int> firts_item, std::vector <int> second_item);

bool find_value_in_ip_addr(std::vector <int> ip_addr, int value);

int print_full_ip_list(std::vector <std::vector <int>> ip_list);

int print_ip_list_with_value_in_first_byte(std::vector <std::vector <int>> ip_list, int value);

int print_ip_list_with_value_in_first_and_second_byte(std::vector <std::vector <int>> ip_list, int value_first_byte, int value_second_byte);

int print_ip_list_with_value_any_byte(std::vector <std::vector <int>> ip_list, int value);