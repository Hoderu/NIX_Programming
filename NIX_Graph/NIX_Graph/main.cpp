#include <iostream>
#include <vector>
#include <map>
#include <set>

#define mplll map<pair<long,long>,long>
#define sl set<long>

using namespace std;

class Graph {
private:
    mplll ribs;
    sl tips;
    bool flag;
    
public:
    Graph()
    {
        flag = false;
    }
    
    long i_v(long v)
    {
        if (1 == tips.count(v))
        {
            return 1;
        }
        else
        {
            tips.insert(v);
            return 0;
        }
    }
    
    long e_v(long v)
    {
        if (0 == tips.count(v))
        {
            return 1;
        }
        else
        {
            tips.erase(v);
            for (long u : tips)
            {
                if (0 != ribs.count({ v, u }))
                {
                    ribs.erase({ v, u });
                }
                if (0 != ribs.count({ u, v }))
                {
                    ribs.erase({ u, v });
                }
            }
            return 0;
        }
    }
    
    long i_e(long v, long u, long w)
    {
        if (flag)
        {
            swap(v, u);
        }
        if ( (0 == tips.count(v)) || (0 == tips.count(u)) )
        {
            return 1;
        }
        else
        {
            long weight;
            bool late = (1 == ribs.count({ v, u }));
            if (late)
            {
                weight = ribs[{ v, u }];
            }
            else
            {
                weight = w;
            }
            if (weight < w)
            {
                return 0;
            }
            else
            {
                if (late)
                {
                    ribs.erase({ v, u });
                }
                ribs.insert({ { v, u }, w });
                return 0;
            }
        }
    }
    
    long e_e(long v, long u)
    {
        if (flag)
        {
            swap(v, u);
        }
        if (0 == ribs.count({ v, u }))
        {
            return 1;
        }
        else
        {
            ribs.erase({ v, u });
            return 0;
        }
    }
    
    void i()
    {
        if (flag)
        {
            flag = false;
        }
        else
        {
            flag = true;
        }
    }
    
    long g_e(long v, long u)
    {
        if (flag)
        {
            swap(v, u);
        }
        if (0 == ribs.count({ v, u }))
        {
            return 2;
        }
        else
        {
            return ribs[{ v, u }];
        }
    }
};

int main() {
    Graph gg;
    while (1)
    {
        string s;
        cin >> s;
        if ("exit" == s)
        {
            cout << "See you later\n";
            break;
        }
        else if ("insert_vertex"  == s)
        {
            long v;
            cin >> v;
            long res = gg.i_v(v);
            if (0 == res)
            {
                cout << "oK\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        else if ("insert_edge" == s)
        {
            long v, u, w;
            cin >> v >> u >> w;
            long res = gg.i_e(v, u, w);
            if (0 == res)
            {
                cout << "oK\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        else if ("erase_vertex" == s)
        {
            long v;
            cin >> v;
            long res = gg.e_v(v);
            if (0 == res)
            {
                cout << "oK\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        else if ("erase_edge" == s)
        {
            long v, u;
            cin >> v >> u;
            long res = gg.e_e(v, u);
            if (0 == res)
            {
                cout << "oK\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        else if ("get_edge" == s)
        {
            long v, u;
            cin >> v >> u;
            long res = gg.g_e(v, u);
            if (res == 2)
            {
                cout << "edge doesn't exist\n";
            }
            else
            {
                cout << res << "\n";
            }
        }
        else if ("invert" == s)
        {
            gg.i();
            cout << "oK\n";
        }
        else
        {
            cout << "invalid_command\n";
        }
    }
    return 0;
}
