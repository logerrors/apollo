#include "cyber/cyber.h"

using apollo::cyber::Time;
using apollo::cyber::Duration;


int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);

    Time t1;
    Time t2(100);
    Time t3(100.0);
    Time right_now = Time::Now();
    Time mono_time = Time::MonoTime();

    AINFO << t1;
    AINFO << t2;
    AINFO << t3;
    AINFO << right_now;
    AINFO << mono_time;
    AINFO << mono_time.ToSecond();

    AINFO << t3.ToSecond();
    AINFO << t3.ToMicrosecond();
    AINFO << t3.ToNanosecond();
    AINFO << t3.ToString();
    AINFO << t3.IsZero();
    AINFO << t1.IsZero();

    AINFO << Time::MIN.ToNanosecond();
    AINFO << Time::MAX.ToNanosecond();
    AINFO << Time::Now();
    Time::SleepUntil(Time::Now() + Duration(5.0));
    AINFO << Time::Now();
    return 0;
}
