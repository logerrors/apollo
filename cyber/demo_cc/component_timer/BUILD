# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
package(default_visibility = ["//visibility:public"])
load("//tools/install:install.bzl", "install")

cc_library(
    name = "timer_cpt_lib",
    srcs = ["timer_cpt.cc"],
    hdrs = ["timer_cpt.h"],
    deps = [
        "//cyber", 
        # "//cyber/demo_base_proto:laser_proto_cc"
    ],
)

cc_binary(
    name = "lib_timer_cpt.so",
    linkshared = True,
    linkstatic = False,
    deps = [":timer_cpt_lib"],
)

filegroup(
    name = "conf",
    srcs = [
        ":cpt.dag",
        ":cpt.launch",
    ],
)

install(
    name = "install",
    data = [
        ":conf",
    ],
    runtime_dest = "/cyber/demo_cc/component_timer",
    targets = [
        ":lib_timer_cpt.so",
    ],
)