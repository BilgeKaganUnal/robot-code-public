cc_library(
    name = "subsystem_runner",
    srcs = ["subsystem_runner.cpp"],
    hdrs = ["subsystem_runner.h"],
    restricted_to = ["//tools:roborio"],
    visibility = ["//visibility:public"],
    deps = [
        "//muan/subsystems/drivetrain",
        "//o2018/subsystems/arm",
        "//o2018/interfaces:interface_runner",
        "//o2018/subsystems/drivetrain:drivetrain_base",
        "//muan/utils:threading_utils",
        "//third_party/aos/common:time",
        "//third_party/aos/common/util:phased_loop",
        "//third_party/aos/linux_code:init",
    ],
)
