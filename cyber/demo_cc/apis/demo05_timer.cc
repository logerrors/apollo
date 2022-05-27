#include "cyber/cyber.h"

using apollo::cyber::Time;
using apollo::cyber::Duration;
using apollo::cyber::Rate;
using apollo::cyber::Timer;

int main(int argc, char const *argv[])
{
    Timer timer(100, [](){
        AINFO << Time::Now();
    }, false);

    timer.Start();
    Duration du(5.0);
    du.Sleep();
    timer.Stop();

    apollo::cyber::WaitForShutdown();
    return 0;
}
