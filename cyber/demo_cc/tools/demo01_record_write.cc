#include "cyber/cyber.h"
#include "cyber/record/record_writer.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::record::RecordWriter;
using apollo::cyber::demo_base_proto::Student;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "record write demo ...";

    RecordWriter writer;
    writer.SetSizeOfFileSegmentation(0);
    writer.SetIntervalOfFileSegmentation(0);

    writer.Open("/apollo/cyber/demo_cc/tools/mytest.record");
    AINFO << "file : " << writer.GetFile();

    std::string channel = "chatter";
    writer.WriteChannel(channel, "apollo.cyber.demo_base_proto.Student", "test ....");
    
    for(size_t i = 0; i < 1000; i++){
        auto stu = std::make_shared<Student>();
        stu->set_name("huluwa");
        stu->add_books("english");
        stu->add_books("cpp");
        stu->set_age(i);

        std::string content;
        stu->SerializeToString(&content);
        writer.WriteMessage(channel, content, 10000000000000 + i * 10000000);
    }

    writer.Close();
    return 0;
}
