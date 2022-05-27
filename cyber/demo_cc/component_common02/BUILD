# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
package(default_visibility = ["//visibility:public"])
load("//tools/install:install.bzl", "install")


cc_binary(
    name = "front_laser",
    srcs = ["front_laser.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:laser_proto_cc",
    ]
)

cc_binary(
    name = "back_laser",
    srcs = ["back_laser.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:laser_proto_cc",
    ]
)



cc_library(
    name = "lasers_cpt_lib",
    srcs = ["lasers_cpt.cc"],
    hdrs = ["lasers_cpt.h"],
    deps = ["//cyber", "//cyber/demo_base_proto:laser_proto_cc"],
)

cc_binary(
    name = "lib_lasers_cpt.so",
    linkshared = True,
    linkstatic = False,
    deps = [":lasers_cpt_lib"],
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
    runtime_dest = "/cyber/demo_cc/component_common02",
    targets = [
        ":back_laser",
        ":front_laser",
        ":lib_lasers_cpt.so",
    ],
)