#include "cyber/component/component.h"
#include "cyber/demo_base_proto/laser.pb.h"

using apollo::cyber::Component;
using apollo::cyber::demo_base_proto::Laser;

class LaserCpt : public Component<Laser, Laser> {
    public:
        bool Init() override;
        bool Proc(const std::shared_ptr<Laser>& front_laser, const std::shared_ptr<Laser>& back_laser) override;
    private:
        std::shared_ptr<apollo::cyber::Writer<Laser>> writer_ = {nullptr};
        uint64_t seq_ = {0};
};

CYBER_REGISTER_COMPONENT(LaserCpt);