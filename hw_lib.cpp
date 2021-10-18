#include "hw_lib.h"

#include <iostream>
#include <algorithm>

std::string userInput (){
    std::cout << "Enter an ip list: " << std::endl;
    std::string string_input = "";
    std::getline(std::cin, string_input);
    return string_input;
}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    r.reserve(10);
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<int> split_ip_addr(const std::string &str)
{
    std::vector<int> r;
    r.reserve(4);
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of('.');
    while(stop != std::string::npos)
    {
        r.push_back(std::stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of('.', start);
    }

    r.push_back(std::stoi(str.substr(start)));
    return r;
}

std::vector <std::vector <int>> findIpAddrInString(std::string string_user_input){
    std::vector <std::vector <int>> ip_list_splitted;
    ip_list_splitted.reserve(10);
    std::vector <std::string> ip_list;
    ip_list.reserve(10);
    std::vector <int> ip_addr_splitted;
    ip_addr_splitted.reserve(4);
    ip_list = split(string_user_input, '\n');
    for (auto ip_addr: ip_list){
        ip_addr_splitted = split_ip_addr(ip_addr);
        ip_list_splitted.push_back(ip_addr_splitted);
    }
    return ip_list_splitted;
}

bool reverse_sorting(const std::vector <int> &firts_item, const std::vector <int> &second_item)
{
    return firts_item > second_item;
}

int print_full_ip_list(const std::vector <std::vector <int>> &ip_list)
{
    for (const auto& ip_addr: ip_list){
        for (auto itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
            if (itter == ip_addr.begin())
                std::cout << *itter;
            else
                std::cout << '.' << *itter;
        }
        std::cout << std::endl;
    }
    return 0;
}

int ip_list_filtered(const std::vector <std::vector <int>> &ip_list, bool any_byte, int first_byte, int second_byte)
{
    if (any_byte == true){
        for (const auto& ip_addr: ip_list){
            if (find_value_in_ip_addr(ip_addr, first_byte)){
                for (auto itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
                if (itter == ip_addr.begin())
                    std::cout << *itter;
                else
                    std::cout << '.' << *itter;
                }
            std::cout << std::endl;
            }
        }
    } else if (first_byte >= 0 and second_byte >= 0){
        for (const auto& ip_addr: ip_list){
            if (ip_addr[0] == first_byte and ip_addr[1] == second_byte){
                for (auto itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
                if (itter == ip_addr.begin())
                    std::cout << *itter;
                else
                    std::cout << '.' << *itter;
                }
            std::cout << std::endl;
            }
        }   
    } else if ((first_byte >= 0 and second_byte < 0)){
        for (const auto& ip_addr: ip_list){
            if (ip_addr[0] == first_byte){
                for (auto itter = ip_addr.begin(); itter != ip_addr.end(); ++itter){
                if (itter == ip_addr.begin())
                    std::cout << *itter;
                else
                    std::cout << '.' << *itter;
                }
            std::cout << std::endl;
            }
        }
    }
    return 0;
}

bool find_value_in_ip_addr(const std::vector <int> &ip_addr, int value)
{
    auto itter = std::find (ip_addr.begin(), ip_addr.end(), value);
    if (itter != ip_addr.end()){
        return true;
    }
    else{
        return false;
    }
}