from cyber.python.cyber_py3 import cyber
from cyber.python.cyber_py3 import parameter

if __name__ == "__main__":
    cyber.init()
    print("param service ....")
    node = cyber.Node("car_param")

    param_service = parameter.ParameterServer(node)

    param1 = parameter.Parameter("car_type", "car_apollo")
    param2 = parameter.Parameter("height", 1.5)
    param3 = parameter.Parameter("cameras", 2)

    param_service.set_parameter(param1)
    param_service.set_parameter(param2)
    param_service.set_parameter(param3)

    p1 = param_service.get_parameter("car_type")
    p2 = param_service.get_parameter("height")
    p3 = param_service.get_parameter("cameras")

    print(f"type = { p1.as_string() }, length = { p2.as_double() }, cameras = { p3.as_int64() }")

    ps = param_service.get_paramslist()
    for p in ps:
        print(p.debug_string())

    node.spin()

    cyber.shutdown()
