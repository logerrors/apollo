# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
py_binary(
    name="demo00_hello_world_py",
    srcs=["demo00_hello_world_py.py"],
    deps=["//cyber/python/cyber_py3:cyber"],
)

py_binary(
    name = "demo01_talker",
    srcs = ["demo01_talker.py"],
    deps = ["//cyber/python/cyber_py3:cyber", "//cyber/demo_base_proto:student_py"],
)

py_binary(
    name = "demo01_listener",
    srcs = ["demo01_listener.py"],
    deps = ["//cyber/python/cyber_py3:cyber", "//cyber/demo_base_proto:student_py"],
)

py_binary(
    name = "demo03_client",
    srcs = ["demo03_client.py"],
    deps = ["//cyber/python/cyber_py3:cyber", "//cyber/demo_base_proto:addints_py"],
)

py_binary(
    name = "demo03_server",
    srcs = ["demo03_server.py"],
    deps = ["//cyber/python/cyber_py3:cyber", "//cyber/demo_base_proto:addints_py"],
)

py_binary(
    name = "demo05_param_client",
    srcs = ["demo05_param_client.py"],
    deps = ["//cyber/python/cyber_py3:cyber", "//cyber/python/cyber_py3:parameter"],
)

py_binary(
    name = "demo05_param_server",
    srcs = ["demo05_param_server.py"],
    deps = ["//cyber/python/cyber_py3:cyber", "//cyber/python/cyber_py3:parameter"],
)