#include "cyber/cyber.h"

using apollo::cyber::Time;
using apollo::cyber::Duration;
using apollo::cyber::Rate;

int main(int argc, char const *argv[])
{
    Rate r1(1.0);
    Rate r2(uint64_t(1000000));
    Rate r3(Duration(2.0));

    AINFO << Time::Now();
    r1.Sleep();
    AINFO << Time::Now();
    return 0;
}
