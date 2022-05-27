#include "cyber/component/component.h"
#include "cyber/component/timer_component.h"

using apollo::cyber::TimerComponent;
using apollo::cyber::Component;

class MyTimer : public TimerComponent {
    public:
        bool Init() override;
        bool Proc() override;
    private:
        int seq_ = {0};
};

CYBER_REGISTER_COMPONENT(MyTimer)