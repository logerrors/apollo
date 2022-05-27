#include "cyber/demo_cc/component_common02/lasers_cpt.h"

bool LaserCpt::Init(){
    writer_ =  this->node_->CreateWriter<Laser>("/laser");
    AINFO << "............ init laser cpt ok.................";
    return true;
}

bool LaserCpt::Proc(const std::shared_ptr<Laser>& front_laser, const std::shared_ptr<Laser>& back_laser){
    seq_++;
    uint64_t front_seq = front_laser->seq();
    uint64_t front_count = front_laser->count();

    uint64_t back_seq = back_laser->seq();
    uint64_t back_count = back_laser->count();

    uint64_t sum = front_count + back_count;

    auto laser_ptr = std::make_shared<Laser>();
    laser_ptr->set_count(sum);
    laser_ptr->set_seq(seq_);
    AINFO << "front " << front_seq << " back " << back_seq;
    
    writer_->Write(laser_ptr);
    return true;
}