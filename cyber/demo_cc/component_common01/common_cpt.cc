#include "cyber/demo_cc/component_common01/common_cpt.h"

bool CommonCpt::Init(){
    AINFO << "...................... init CommonCpt ............................";
    return true;
}

bool CommonCpt::Proc(const std::shared_ptr<Student>& stu){
    AINFO << "do message: " << stu->name() << " --- " << stu->age();
    return true;
}