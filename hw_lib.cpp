#include "hw_lib.h"

#include <iostream>
#include <regex>
#include <algorithm>

std::string userInput (){
    std::cout << "Enter an ip list: " << std::endl;
    std::string string_input = "";
    std::getline(std::cin, string_input);
    return string_input;
}

std::vector <std::vector <int>> findIpAddrInString(std::string string_user_input){
    std::vector <std::vector <int>> ip_list;
    std::regex regx("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}");
    for (std::sregex_iterator itter = std::sregex_iterator(string_user_input.begin(), string_user_input.end(), regx), end = std::sregex_iterator(); itter != end; ++itter){
        std::smatch regex_match = *itter;
        // std::cout << regex_match.str();
        std::vector <int> ip_addr = ipAddrStrToVectorInt(regex_match.str());
        ip_list.push_back(ip_addr);
    }
    std::sort(ip_list.begin(), ip_list.end(), reverse_sorting);
    return ip_list;
}

std::vector <int> ipAddrStrToVectorInt(std::string ip_addr_str){
    std::vector <int> ip_addr_vector;
    std::regex regx("[0-9]{1,3}");
    for (std::sregex_iterator itter = std::sregex_iterator(ip_addr_str.begin(), ip_addr_str.end(), regx), end = std::sregex_iterator(); itter != end; ++itter){
        std::smatch ip_segment = *itter;
        ip_addr_vector.push_back(std::stoi(ip_segment.str()));
    }
    return ip_addr_vector;
}

bool reverse_sorting(std::vector <int> firts_item, std::vector <int> second_item)
{
    return firts_item > second_item;
}

int print_full_ip_list(std::vector <std::vector <int>> ip_list)
{
    for (const auto& ip_addr: ip_list){
        for (std::vector <int>::const_iterator itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
            if (itter == ip_addr.begin())
                std::cout << *itter;
            else
                std::cout << '.' << *itter;
        }
        std::cout << std::endl;
    }
    return 0;
}

int print_ip_list_with_value_in_first_byte(std::vector <std::vector <int>> ip_list, int value)
{
    for (const auto& ip_addr: ip_list){
        if (ip_addr[0] == value){
            for (std::vector <int>::const_iterator itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
            if (itter == ip_addr.begin())
                std::cout << *itter;
            else
                std::cout << '.' << *itter;
            }
        std::cout << std::endl;
        }
    }
    return 0;
}

int print_ip_list_with_value_in_first_and_second_byte(std::vector <std::vector <int>> ip_list, int value_first_byte, int value_second_byte)
{
    for (const auto& ip_addr: ip_list){
        if (ip_addr[0] == value_first_byte and ip_addr[1] == value_second_byte){
            for (std::vector <int>::const_iterator itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
            if (itter == ip_addr.begin())
                std::cout << *itter;
            else
                std::cout << '.' << *itter;
            }
        std::cout << std::endl;
        }
    }
    return 0;
}

int print_ip_list_with_value_any_byte(std::vector <std::vector <int>> ip_list, int value)
{
    for (const auto& ip_addr: ip_list){
        if (find_value_in_ip_addr(ip_addr, value)){
            for (std::vector <int>::const_iterator itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
            if (itter == ip_addr.begin())
                std::cout << *itter;
            else
                std::cout << '.' << *itter;
            }
        std::cout << std::endl;
        }
    }
    return 0;
}

bool find_value_in_ip_addr(std::vector <int> ip_addr, int value){
    std::vector<int>::iterator itter;
    itter = std::find (ip_addr.begin(), ip_addr.end(), value);
    if (itter != ip_addr.end()){
        return true;
    }
    else{
        return false;
    }
}