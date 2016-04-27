//
//  main.cpp
//  NIX_BrainFuck
//
//  Created by Андрей Решетников on 14.04.16.
//  Copyright © 2016 mipt. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

/*int main(int argc, char **argv)
{
    static char Super_answer[100000];
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    
    std::vector<char> Input_Text;
    char Input_Char;
    
    while(!std::cin.eof())
    {
        std::cin >> Input_Char;
        Input_Text.push_back(Input_Char);
    }
    
    unsigned int Super_Count = 50000;
    int While_Counter = 0;
    for(int i = 0; i < Input_Text.size(); ++i)
    {
        if(Input_Text[i] == '>') {
            Super_Count = Super_Count + 1;
        }
        if(Input_Text[i] == '<') {
            Super_Count = Super_Count - 1;
        }
        if(Input_Text[i] == '+') {
            Super_answer[Super_Count] = Super_answer[Super_Count] + 1;
        }
        if(Input_Text[i] == '-') {
            Super_answer[Super_Count] = Super_answer[Super_Count] - 1;
        }
        if(Input_Text[i] == '.') {
            std::cout << Super_answer[Super_Count];
        }
//        if(Input_Text[i] == ',') {
//            std::cin >> Super_answer[Super_Count];
//        }
        if(Input_Text[i] == '[')
        {
            if(!Super_answer[Super_Count])
            {
                While_Counter = While_Counter + 1;
                while ( While_Counter )
                {
                    i = i + 1;
                    if (Input_Text[i] == '[') {
                        While_Counter = While_Counter + 1;
                    }
                    if (Input_Text[i] == ']') {
                        While_Counter = While_Counter - 1;
                    }
                }
            } else {
                continue;
            }
        }
        else if (Input_Text[i] == ']')
        {
            if ( !Super_answer[Super_Count] )
            {
                continue;
            }
            else
            {
                if (Input_Text[i] == ']') {
                    While_Counter = While_Counter + 1;
                }
                while ( While_Counter )
                {
                    i = i - 1;
                    if (Input_Text[i] == '[') {
                        While_Counter = While_Counter - 1;
                    }
                    if (Input_Text[i] == ']') {
                        While_Counter = While_Counter + 1;
                    }
                }
                i = i - 1;
            }
        }
    }
}*/

using namespace std;
static char Super_Answer[30000];
int main(int argc, char **argv) {
    vector<char> SuperPuperCom;
    char chaaaaaar;
    ifstream infile("input");
    while (infile) {
        infile.get(chaaaaaar);
        SuperPuperCom.push_back(chaaaaaar);
    }
    infile.close();
    unsigned int j = 0;
    int boundsRrrCCC = 0;
    for (int i = 0; i < SuperPuperCom.size(); ++i) {
        if (SuperPuperCom[i] == '>') {
            j++;
        }
        if (SuperPuperCom[i] == '<') {
            j--;
        }
        if (SuperPuperCom[i] == '+') {
            Super_Answer[j]++;
        }
        if (SuperPuperCom[i] == '-') {
            Super_Answer[j]--;
        }
        if (SuperPuperCom[i] == '.') {
            cout << Super_Answer[j];
        }
        if (SuperPuperCom[i] == ',') {
            cin >> Super_Answer[j];
        }
        if (SuperPuperCom[i] == '[') {
            if (!Super_Answer[j]) {
                ++boundsRrrCCC;
                while (boundsRrrCCC) {
                    ++i;
                    if (SuperPuperCom[i] == '[') ++boundsRrrCCC;
                    if (SuperPuperCom[i] == ']') --boundsRrrCCC;
                }
            } else continue;
        }
        else if (SuperPuperCom[i] == ']') {
            if (!Super_Answer[j]) {
                continue;
            }
            else {
                if (SuperPuperCom[i] == ']') boundsRrrCCC++;
                while (boundsRrrCCC) {
                    --i;
                    if (SuperPuperCom[i] == '[') boundsRrrCCC--;
                    if (SuperPuperCom[i] == ']') boundsRrrCCC++;
                }
                --i;
            }
        }
    }
}