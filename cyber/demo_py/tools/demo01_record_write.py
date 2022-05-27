from cyber.python.cyber_py3 import record, cyber
from cyber.demo_base_proto.student_pb2 import Student

if __name__ == "__main__":
    # cyber.init()
    writer = record.RecordWriter()
    writer.set_intervaltime_fileseg(0)
    writer.set_size_fileseg(0)

    record_file = "/apollo/cyber/demo_py/tools/mytest.record"
    if not writer.open(record_file):
        print(f"failed open {record_file}")
        exit(1)
    stu = Student()
    stu.name = "hah"
    stu.height = 1.78
    stu.books.append("cpp")
    stu.books.append("c")
    stu.books.append("python")

    print(f"full name: { stu.DESCRIPTOR.full_name }")
    channel = "chatter"
    
    writer.write_channel("chatter", "cyber.demo_base_proto.Student", "test...")
    for seq in range(20):
        stu.age = seq
        writer.write_message(channel, stu.SerializeToString(), seq)

    writer.close()
