#include "cyber/cyber.h"

using apollo::cyber::Time;
using apollo::cyber::Duration;

int main(int argc, char const *argv[])
{
    Time t1(100.0);
    Time t2(200.0);
    Time t3(500.0);

    Duration du1(30.0);
    Duration du2(50.0);
    Duration du3(100.0);

    AINFO << (t1 == t2);
    AINFO << (t1 != t2);

    AINFO << (t1 >= t2);
    AINFO << (t1 <= t2);

    AINFO << t1;
    AINFO << t1 + du1;
    AINFO << t1 - du1;
    AINFO << t2 - t1;

    AINFO << (du1 == du2);
    AINFO << (du1 >= du2);
    return 0;
}
