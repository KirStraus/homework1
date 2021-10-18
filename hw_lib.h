#include <iostream>
#include <vector>

std::string userInput();

std::vector <std::vector <int>> findIpAddrInString(std::string string_user_input);

std::vector<std::string> split(const std::string &str, char d);

bool reverse_sorting(const std::vector <int> &firts_item, const std::vector <int> &second_item);

bool find_value_in_ip_addr(const std::vector <int> &ip_addr, int value);

int print_full_ip_list(const std::vector <std::vector <int>> &ip_list);

int ip_list_filtered(const std::vector <std::vector <int>> &ip_list, bool any_byte=false, int first_byte=-1, int second_byte=-1);