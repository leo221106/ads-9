#include <bits/stdc++.h>
#include "Convert.h"
using namespace std;

int main()
{
    string str;
    getline(cin, str, '\n');

    Convert *c = new Convert();

    cout << c->do_prefix(str) << endl;
    return 0;
}
