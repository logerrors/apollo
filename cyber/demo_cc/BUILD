# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "demo00_hello_world",
    srcs = ["demo00_hello_world.cc"],
    deps = ["//cyber"],
)

cc_binary(
    name = "demo01_talker",
    srcs = ["demo01_talker.cc"],
    deps = ["//cyber", "//cyber/demo_base_proto:student_cc"],
)

cc_binary(
    name = "demo01_listener",
    srcs = ["demo01_listener.cc"],
    deps = ["//cyber", "//cyber/demo_base_proto:student_cc"],
)

cc_binary(
    name = "demo03_server",
    srcs = ["demo03_server.cc"],
    deps = ["//cyber", "//cyber/demo_base_proto:addints_cc"]
)

cc_binary(
    name = "demo03_client",
    srcs = ["demo03_client.cc"],
    deps = ["//cyber", "//cyber/demo_base_proto:addints_cc"]
)

cc_binary(
    name = "demo05_param_client",
    srcs = ["demo05_param_client.cc"],
    deps = ["//cyber"],
)

cc_binary(
    name = "demo05_param_server",
    srcs = ["demo05_param_server.cc"],
    deps = ["//cyber"],
)