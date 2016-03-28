//
//  main.cpp
//  NIX_Dictionary
//
//  Created by Андрей Решетников on 09.12.15.
//  Copyright © 2015 mipt. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>

using namespace std;

char little_letter(char cymbol) {
    char cc;
    cc = tolower(cymbol);
    return cc;
}

struct para { // pair: key->value
    long number; string ss;
    
    para(long k, string v) : number(k), ss(v) {}
    
    bool operator<(const para& right) const {
        if (number > right.number) {
            return true;
        } else if (number == right.number) {
            return ss < right.ss;
        } else {
            return false;
        }
    }
};

int main() {
    ifstream file_input("input");
    char cymbol; string w_string;
    map<string, long> d_work_map;
    while (!file_input.eof()) {
        file_input >> noskipws >> cymbol;
        if (!isalpha(cymbol)) {
            if (0 != w_string.length()) {
                d_work_map[w_string]++;
            }
            w_string.clear();
        } else if ( (file_input.eof()) && (0 != w_string.length()) ) {
            d_work_map[w_string]++;
            w_string.clear();
        } else {
            w_string.push_back(little_letter(cymbol));
        }
    }
    
    set<para> d_work_set;
    map<string, long>::iterator iterate;
    for (iterate = d_work_map.begin(); iterate != d_work_map.end(); iterate++) {
        string work_string = iterate->first;
        long number = iterate->second;
        
        d_work_set.insert(para(number, work_string));
        cout << work_string;
        cout << " ";
        cout << number;
        cout << endl;
    }
    
    set<para>::iterator iterate1;
    for (iterate1 = d_work_set.begin(); iterate1 != d_work_set.end(); iterate1++) {
        cout << iterate1->number;
        cout << " ";
        cout << iterate1->ss;
        cout << endl;
    }
    
    return 0;
}