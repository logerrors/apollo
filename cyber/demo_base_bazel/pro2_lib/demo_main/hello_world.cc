#include <iostream>

#include "demo_lib/hello_great.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << get_great(argv[1]) << endl;
    return 0;
}
