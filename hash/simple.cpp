#include <iostream>
#include <vector>
#include <set>

using namespace std;

class hashTable{
private:
    int mod;
    vector<set<int>> table;
public:
    hashTable(int m)
    {
        mod = m;
        table.resize(m);
    }

    void insert(int x)
    {
        int index = x % mod;
        table[index].insert(x);
    }

    void erase(int x)
    {
        int index = x % mod;
        table[index].erase(x);
    }

    bool find(int x)
    {
        int index = x % mod;
        return table[index].find(x) != table[index].end();
    }
    
    void print()
    {
        cout << "===== s =====" << endl;
        for (int i = 0; i < mod; i++)
        {
            printf("[%0.3d]:", i);
            for (auto it : table[i])
            {
                cout << it << " -> ";
            }
            cout << "NULL\n";
        }
        cout << "===== e =====" << endl;
    }
};

int main()
{
    int k,m;
    while (cin >> k >> m)
    {
        hashTable ht(m);
        for (int i = 0; i < k; i++)
        {
            int op, x;
            cin >> op;
            if (op == 1)
            {
                cin >> x;
                ht.insert(x);
            }
            else if (op == 2)
            {
                cin >> x;
                ht.erase(x);
            }
            else if (op == 3)
            {
                ht.print();
            }
        }
    }
    
}