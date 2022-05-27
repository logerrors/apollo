#include "cyber/cyber.h"
#include "cyber/record/record_reader.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::record::RecordReader;
using apollo::cyber::record::RecordMessage;
using apollo::cyber::demo_base_proto::Student;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "record read demo ...";

    RecordReader reader("/apollo/cyber/demo_cc/tools/mytest.record");

    std::string channel = "chatter";
    uint64_t msg_count = reader.GetMessageNumber(channel);
    AINFO << "total " << msg_count << " messages";
    std::string msg_type = reader.GetMessageType(channel);
    AINFO << "channel msg type " << msg_type;
    std::string msg_dec = reader.GetProtoDesc(channel);
    AINFO << "channel desc " << msg_dec;

    RecordMessage msg;
    for(size_t i = 0; i < msg_count; i++){
        if(reader.ReadMessage(&msg)){
            AINFO << "seq: " << i << " name: " << msg.channel_name << " content: " << msg.content << " time: " << msg.time;
        }else{
            AWARN << "read msg error seq " << i;
        }
    }
    return 0;
}
