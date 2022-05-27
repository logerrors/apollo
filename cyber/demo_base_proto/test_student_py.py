from cyber.demo_base_proto.student_pb2 import Student



if __name__ == "__main__":
    stu = Student()
    stu.name = "aotuman"
    stu.age = 8
    stu.height = 1.4
    stu.books.append("yuwen")
    stu.books.append("c++")

    print(stu.name, stu.books)