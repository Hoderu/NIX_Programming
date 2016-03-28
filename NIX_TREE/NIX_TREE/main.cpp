//
//  main.cpp
//  NIX_TREE
//
//  Created by Андрей Решетников on 11.11.15.
//  Copyright © 2015 mipt. All rights reserved.
//

#include <cstdlib>
#include <iostream>

using namespace std;

double tree_parsing(const string &work, int left, int right) {
    if ('(' != work[left]) {
        string s;
        s = work.substr(left, right - left);
        return atoi(s.c_str());
    } else {
        int mid;
        double left_result, right_result;
        left++;
        right--;
        int count = 0;
        for (int i = left; i < right; i++) {
            if (')' == work[i]) {
                count--;
            } else if ('(' == work[i]) {
                count++;
            } else if ((' ' == work[i]) && (0 == count)) {
                mid = i;
                break;
            }
        }
        right_result = tree_parsing(work, 1 + mid, right);
        left_result = tree_parsing(work, left, mid);
        return 0.5 * (left_result + right_result);
    }
}

int main(int argc, char* argv[]) {
    string work;
    getline(cin, work);
    int len = work.length(), start = 0;
    double answer = tree_parsing(work, start, len);
    printf("%0.2f\n", answer);
}
