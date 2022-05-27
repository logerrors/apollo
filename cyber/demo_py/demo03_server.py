from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.addints_pb2 import AddInts_Request
from cyber.demo_base_proto.addints_pb2 import AddInts_Response


def callback(req):
    num1 = req.num1
    num2 = req.num2
    print("num1: {}, num2: {}".format(num1, num2))
    sum = num1 + num2
    res = AddInts_Response()
    res.sum = sum
    return res

if __name__ == "__main__":
    cyber.init()
    server_node = cyber.Node("ser222ver_node")
    server = server_node.create_service("addints", AddInts_Request, AddInts_Response, callback = callback)
    print("register service")
    server_node.spin()
    cyber.shutdown()