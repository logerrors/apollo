#include "cyber/cyber.h"
#include "cyber/demo_base_proto/addints.pb.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Response;


int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    if(argc != 3){
        AWARN << "require two param";
        return 1;
    }
    AINFO << "client ....";
    auto client_node = apollo::cyber::CreateNode("client_node");
    auto client = client_node->CreateClient<AddInts_Request, AddInts_Response>("addints");

    auto req = std::make_shared<AddInts_Request>();
    req->set_num1(std::atoll(argv[1]));
    req->set_num2(std::atoll(argv[2]));

    auto res = client->SendRequest(req);
    AINFO << "res: sum = " << res->sum();

    apollo::cyber::WaitForShutdown();
    return 0;
}
