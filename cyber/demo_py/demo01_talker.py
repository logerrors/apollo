from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.student_pb2 import Student
import time


if __name__ == "__main__":
    cyber.init()
    talker_node = cyber.Node("xx")
    talker = talker_node.create_writer("chatter", Student, 6)

    g = 0
    stu = Student()
    while not cyber.is_shutdown():
        time.sleep(1)
        stu.age = g
        stu.name = "wuxing"
        talker.write(stu)
        g = g + 1

    cyber.shutdown()