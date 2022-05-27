from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.addints_pb2 import AddInts_Request, AddInts_Response
import sys


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("require two param")
        sys.exit(1)

    cyber.init()
    client_node = cyber.Node("client")
    client = client_node.create_client("addints", AddInts_Request, AddInts_Response)

    req = AddInts_Request()
    req.num1 = int(sys.argv[1])
    req.num2 = int(sys.argv[1])

    response = client.send_request(req)
    print("response: sum = {}".format(response.sum))

    cyber.shutdown()