#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "lib.h"

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

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

int main() {
    std::ifstream file("ip_filter.tsv");
    std::string line;

    std::vector<std::vector<std::string> > ip_pool;
    for(std::string line; std::getline(file, line);)
    {
        std::vector<std::string> v = split(line, '\t');
        ip_pool.push_back(split(v.at(0), '.'));
    }

    // reverse lexicographically sort
    std::sort(begin(ip_pool), end(ip_pool), [](std::vector<std::string> a, std::vector<std::string> b)
    {
        std::vector<std::string> a2;
        std::vector<std::string> b2;
        for (int i = 0; i < 4;) {
            a2 = split(a.at(i), '.');
            b2 = split(b.at(i), '.');
            if (std::stoi(a2.at(0)) > std::stoi(b2.at(0))) {
                return true;
            }
            else if (std::stoi(a2.at(0)) == std::stoi(b2.at(0))) {
                i++;
            }
            else {
                return false;
            }
        }
        return false;
    });

    int IpAmount = ip_pool.size();

    // full list
    for(int i = 0; i < IpAmount; i++) {
        for(int j = 0; j < 4; j++) {
            if (j != 0)
            {
                std::cout << ".";
            }
            std::cout << ip_pool[i][j];
        }
        std::cout << std::endl;
    }

    // 1st byte == 1
    bool DontSkip = false;
    for(int i = 0; i < IpAmount; i++) {
        for(int j = 0; j < 4; j++) {   
            if (ip_pool[i][0] != "1") {
                DontSkip = true;
                break;
            }
           if (j != 0)
            {
                std::cout << ".";
            }
            std::cout << ip_pool[i][j];
        }
        if (!DontSkip) {
            std::cout << std::endl;
        }
        DontSkip = false;
    }

    // // 1st byte == 46, 2nd byte == 70
    for(int i = 0; i < IpAmount; i++)
    {
        for(int j = 0; j < 4; j++)
        {   
            if (ip_pool[i][0] != "46" || ip_pool[i][1] != "70") {
                DontSkip = true;
                break;
            }
            if (j == 1 || j == 2)
            {
                std::cout << ".";
            }
            std::cout << ip_pool[i][j];
        }
        if (!DontSkip) {
            std::cout << std::endl;
        }
        DontSkip = false;
    }
    
    // any byte == 46
    bool NoNumber = true;
    for(int i = 0; i < IpAmount; i++)
    {
        for(int j = 0; j < 4; j++)
        {   
            for(int l = 0; l < 4; l++) {
                if (ip_pool[i][l] == "46") {
                    NoNumber = false;
                }
            }
            if (NoNumber) {
                DontSkip = true;
                break;
            }
            if (j != 0)
            {
                std::cout << ".";
            }
            std::cout << ip_pool[i][j];
            NoNumber = true;
        }
        if (!DontSkip) {
            std::cout << std::endl;
        }
        DontSkip = false;
    }

    file.close();
    return 0;
    }