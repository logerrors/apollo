#include "cyber/cyber.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::demo_base_proto::Student;


void CallBack(const std::shared_ptr<apollo::cyber::demo_base_proto::Student> &msg){
    AINFO << "receive " << msg->age();
}

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);

    auto listener_node = apollo::cyber::CreateNode("wuxing_go");
    auto listener = listener_node->CreateReader<Student>("chatter", CallBack);


    apollo::cyber::WaitForShutdown();
    return 0;
}