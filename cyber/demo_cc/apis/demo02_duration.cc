#include "cyber/cyber.h"

using apollo::cyber::Time;
using apollo::cyber::Duration;

int main(int argc, char const *argv[])
{
    Duration du1(100000);
    Duration du2(5.0);
    Duration du3(3,1000000);

    AINFO << du1;
    AINFO << du2;
    AINFO << du3;
    AINFO << du2.ToNanosecond();
    AINFO << du2.ToSecond();
    AINFO << du2.IsZero();

    du2.Sleep();
    return 0;
}
