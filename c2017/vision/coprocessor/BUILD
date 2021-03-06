cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":sender",
        ":vision",
        "//third_party/gflags:gflags",
        "@opencv//:opencv",
    ],
    linkopts = [
        "-lpthread",
        "-lopencv_imgproc",
        "-lopencv_core",
        "-lopencv_video",
        "-lopencv_videoio",
        "-lopencv_highgui",
    ],
    restricted_to = ["//tools:k8", "//tools:armhf-debian"],
)

cc_library(
    name = "sender",
    srcs = ["sender.cpp"],
    hdrs = ["sender.h"],
    deps = [
        "//third_party/aos/common/util:phased_loop",
        "//third_party/aos/vision/events:udp",
        "//c2017/vision:vision_queues"
    ]
)

filegroup(
    name = "v4l_params_file",
    srcs = [
        "constants/vision_camera_params",
        "constants/stream_camera_params"
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "vision",
    srcs = ["vision.cpp"],
    hdrs = ["vision.h"],
    deps = [
        ":sender",
        "@opencv//:opencv",
        "//muan/vision:vision"
    ],
    data = [
        "constants/robot_constants.pb.text",
        "constants/thresholds.pb.text"
    ],
    linkopts = [
        "-lopencv_video",
        "-lopencv_highgui",
    ],
    visibility = ["//visibility:public"],
    restricted_to = ["//tools:k8", "//tools:armhf-debian"],
)
