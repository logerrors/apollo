from cyber.python.cyber_py3 import cyber
from cyber.python.cyber_py3 import parameter

if __name__ == "__main__":
    cyber.init()
    print("param service ....")
    node = cyber.Node("camera_service")

    param_client = parameter.ParameterClient(node, "car_param")

    p1 = param_client.get_parameter("car_type")
    p2 = param_client.get_parameter("height")
    p3 = param_client.get_parameter("cameras")

    print(f"car_type = {p1.as_string()}, height = {p2.as_double()}, cameras = {p3.as_int64}")

    ps = param_client.get_paramslist()
    for p in ps:
        print(p.debug_string())

    cyber.shutdown()
