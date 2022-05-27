#include "cyber/demo_base_proto/student.pb.h"


int main(int argc, char const *argv[])
{
    apollo::cyber::demo_base_proto::Student stu;

    stu.set_name("wuxing");
    stu.set_age(28);
    stu.set_height(1.75);
    stu.add_books("csapp");
    stu.add_books("ldap");

    std::string name = stu.name();
    uint64_t age = stu.age();
    double height = stu.height();
    std::cout << name << " == " << age << " == " << height << " == " <<  std::endl;
    for(int i = 0; i < stu.books_size(); i++){
        std::cout << stu.books(i) << "-";
    }

    std::cout << std::endl;
    return 0;
}
