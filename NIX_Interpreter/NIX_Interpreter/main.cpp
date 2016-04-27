//
//  main.cpp
//  NIX_Interpreter
//
//  Created by Андрей Решетников on 11.04.16.
//  Copyright © 2016 mipt. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::map<std::string, int> variables;
bool flag_end = false;

void answer(std::vector<std::string>::iterator beg, std::vector<std::string>::iterator end) {
    std::string while_variable;
    std::string if_variable;
    std::string variable, variable1, value;
    while (beg != end) {
        if (*beg == "begin") {
            //flag_end = false;
            std::cout << *beg << std::endl;
            beg++;
            std::cout << *beg << std::endl;
            answer(beg, end);
            if (flag_end) {
                break;
            }
        } if (*beg == "end") {
            flag_end = true;
            break;
        } else if (*beg == "while") {
            while_variable = (*(beg + 1));
            std::cout << *beg << std::endl;
            beg += 2;
            std::cout << *beg << std::endl;
            while (variables[while_variable]) {
                flag_end = false;
                answer(beg, end);
//                if (flag_end) {
//                    break;
//                }
            }
        } else if (*beg == "if") {
            if_variable = (*(beg + 1));
            if (variables[if_variable]) {
                std::cout << *beg << std::endl;
                beg += 2;
                std::cout << *beg << std::endl;
                answer(beg, end);
                if (flag_end) {
                    break;
                }
            }
        } else if (*beg == "inc") {
            variable = (*(beg + 1));
            variables[variable]++;
            std::cout << *beg << std::endl;
            beg += 2;
            std::cout << *beg << std::endl;
            answer(beg, end);
            if (flag_end) {
                break;
            }
        } else if (*beg == "dec") {
            variable = (*(beg + 1));
            variables[variable]--;
            std::cout << *beg << std::endl;
            beg += 2;
            std::cout << *beg << std::endl;
            answer(beg, end);
            if (flag_end) {
                break;
            }
        } else if (*beg == "set") {
            variable = (*(beg + 1));
            value = (*(beg + 2));
            variables[variable] = atoi(value.data());
            std::cout << *beg << std::endl;
            beg += 3;
            std::cout << *beg << std::endl;
            answer(beg, end);
            if (flag_end) {
                break;
            }
        } else if (*beg == "move") {
            variable = (*(beg + 1));
            variable1 = (*(beg + 2));
            variables[variable] = variables[variable1];
            std::cout << *beg << std::endl;
            beg += 3;
            std::cout << *beg << std::endl;
            answer(beg, end);
            if (flag_end) {
                break;
            }
        } else if (*beg == "print") {
            variable = (*(beg + 1));
            std::cout << variables[variable] << std::endl;
            std::cout << *beg << std::endl;
            beg += 2;
            std::cout << *beg << std::endl;
            answer(beg, end);
            if (flag_end) {
                break;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    std::string s;
    std::vector<std::string> program;
    
    bool flag = true;
    
    while (flag) {
        std::cin >> s;
        if (s == "set") {
            program.push_back(s);
            std::cin >> s;
            program.push_back(s);
            std::cin >> s;
            program.push_back(s);
        } else {
            if (!atoi(s.data())) {
                program.push_back(s);
            } else {
                break;
            }
        }
    }
    
    if (*program.begin() == "begin") {
        //program.erase(program.begin());
        //program.end()--;
    }
    
    int N = atoi(s.data());
    int M;
    std::string variable;
    int value;
    
    for (int i = 0; i < N; i++) {
        std::cin >> M;
        for (int j = 0; j < M; j++) {
            std::cin >> variable >> value;
            variables[variable] = value;
        }
        answer(program.begin(), program.end());
        variables.clear();
    }
    return 0;
}
