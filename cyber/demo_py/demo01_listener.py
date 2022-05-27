from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.student_pb2 import Student

def callback(student):
    print(student.age)


if __name__ == "__main__":
    cyber.init()
    listener_node  = cyber.Node("lis")
    listener = listener_node.create_reader("chatter", Student, callback)
    listener_node.spin()
    cyber.shutdown()