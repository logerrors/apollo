#include "cyber/cyber.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::demo_base_proto::Student;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);

    auto talker_node = apollo::cyber::CreateNode("ergou");
    auto talker = talker_node->CreateWriter<Student>("chatter");

    uint64_t seq = 0;
    apollo::cyber::Rate rate(0.5);
    while(apollo::cyber::OK()){
        seq++;

        AINFO << "publish " << seq << " data";

        auto msg = std::make_shared<Student>();
        msg->set_name("wuxing");
        msg->set_age(seq);
        msg->set_height(1.72);
        msg->add_books("cpp");
        msg->add_books("python");
        msg->add_books("js");

        talker->Write(msg);

        rate.Sleep();
    }

    apollo::cyber::WaitForShutdown();
    return 0;
}
