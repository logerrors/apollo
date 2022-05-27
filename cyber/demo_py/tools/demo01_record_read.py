from asyncore import read
from cyber.python.cyber_py3 import record
from cyber.demo_base_proto.student_pb2 import Student

if __name__ == "__main__":
    record_file = "/apollo/cyber/demo_py/tools/mytest.record"
    reader = record.RecordReader(record_file)

    channel = "chatter"
    count = reader.get_messagenumber(channel)
    msg_type = reader.get_messagetype(channel)
    desc = reader.get_protodesc(channel)

    print(f"count: {count}, type: {msg_type}, desc = {desc}")

    msgs = reader.read_messages()
    for msg in msgs:
        print(f"channel = {msg[0]}, data = {msg[1]}, type = {msg[2]}, ts = {msg[3]}")
