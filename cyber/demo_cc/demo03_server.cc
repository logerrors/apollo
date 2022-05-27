#include "cyber/cyber.h"
#include "cyber/demo_base_proto/addints.pb.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Response;


void cb(const std::shared_ptr<AddInts_Request>& request, const std::shared_ptr<AddInts_Response>& response){
    int64_t num1 = request->num1();
    int64_t num2 = request->num2();
    AINFO << "client receive num1 = " << num1 << " , num2 = " << num2;
    int64_t sum = num1 + num2;
    response->set_sum(sum);
}

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "server ....";
    auto server_node = apollo::cyber::CreateNode("server_node");
    auto server = server_node->CreateService<AddInts_Request, AddInts_Response>("addints", cb);

    apollo::cyber::WaitForShutdown();
    return 0;
}
