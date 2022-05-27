#include "cyber/cyber.h"
#include "cyber/parameter/parameter_client.h"

using apollo::cyber::ParameterClient;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "parameter client...";

    std::shared_ptr<apollo::cyber::Node> param_client_node = apollo::cyber::CreateNode("param_client");
    auto param_client = std::make_shared<ParameterClient>(param_client_node, "param");

    Parameter temp;
    param_client->GetParameter("type", &temp);
    AINFO << temp.Name() << " = " << temp.AsString();
    param_client->GetParameter("height", &temp);
    AINFO << temp.Name() << " = " << temp.AsDouble();
    param_client->GetParameter("lasers", &temp);
    AINFO << temp.Name() << " = " << temp.AsInt64();

    param_client->SetParameter(Parameter("lasers", 1));
    AINFO << "change .....";
    param_client->GetParameter("lasers", &temp);
    AINFO << temp.Name() << " = " << temp.AsInt64();


    apollo::cyber::WaitForShutdown();

    return 0;
}
