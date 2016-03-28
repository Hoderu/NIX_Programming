//
//  main.cpp
//  NIX_Prioritet_Queue
//
//  Created by Андрей Решетников on 19.11.15.
//  Copyright © 2015 mipt. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;

struct vertex {
    string data;
    struct vertex *reference;
    double order;
};

class Queue_with_Prioritet {
private:
    struct vertex *top_element;
    long range_queue;
public:
    Queue_with_Prioritet() {
        top_element = NULL;
        range_queue = 0;
    }
    long queue_size() {
        return range_queue;
    }
    void insert_in_queue(const string &x, double precedency) {
        struct vertex *temp, *q_top;
        range_queue++;
        temp = new vertex;
        temp->data = x;
        temp->order = precedency;
        if ((NULL == top_element) || (precedency < top_element->order)) {
            temp->reference = top_element;
            top_element = temp;
        } else {
            q_top = top_element;
            while ((NULL != q_top->reference) && (q_top->reference->order <= precedency)) {
                q_top = q_top->reference;
            }
            temp->reference = q_top->reference;
            q_top->reference = temp;
        }
    }
    void delele_element() {
        vertex *temp;
        if (NULL == top_element) {
            return;
        } else {
            temp = top_element;
            cout << temp->data << endl;
            top_element = top_element->reference;
            free(temp);
            range_queue--;
        }
    }
};

int main() {
    Queue_with_Prioritet q;
    string s;
    while (1) {
        cin >> s;
        if ("PROCESS" == s) {
            if (0 == q.queue_size()) {
                continue;
            }
            q.delele_element();
        } else if ("ADD" == s) {
            double precedency;
            string data;
            cin >> precedency;
            cin >> data;
            if (32 != data.length()) {
                continue;
            }
            if ((precedency < 0) || (precedency > 1)) {
                continue;
            }
            q.insert_in_queue(data, precedency);
        } else if ("FINISH" == s) {
            int number;
            cin >> number;
            if ((number > q.queue_size()) || (number < 0)) {
                continue;
            }
            for (int i = 0; i <number; i++) {
                q.delele_element();
            }
            cout << q.queue_size();
            break;
        }
    }
    return 0;
}