#include "cyber/cyber.h"

int main(int argc, char* argv[]){
    apollo::cyber::Init(argv[0]);
    AINFO << "hello world";
    AWARN << "hello apollo cyber rt";
    AERROR << "hello apollo cyber rt";
    // AFATAL << "hello ..";
    return 0;
}