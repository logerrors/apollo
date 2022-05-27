#include "cyber/cyber.h"
#include "cyber/demo_base_proto/laser.pb.h"

using apollo::cyber::demo_base_proto::Laser;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "init front lasers ....";

    auto pub_node = apollo::cyber::CreateNode("front_laser_node");
    auto pub = pub_node->CreateWriter<Laser>("/front/laser");
    apollo::cyber::Rate rate(1.0);

    auto laser = std::make_shared<Laser>();
    laser->set_count(2);
    uint64_t seq = 0;
    while(apollo::cyber::OK()){
        seq++;
        laser->set_seq(seq);
        pub->Write(laser);
        AINFO << "send " << seq << " seq";
        rate.Sleep();
    }

    apollo::cyber::WaitForShutdown();
    return 0;
}
