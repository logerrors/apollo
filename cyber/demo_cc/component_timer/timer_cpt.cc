#include "cyber/demo_cc/component_timer/timer_cpt.h"

bool MyTimer::Init(){
    AINFO << "timer component init ....";
    return true;
}

bool MyTimer::Proc(){
    seq_++;
    AINFO << "................. " << seq_;
    return true;
}