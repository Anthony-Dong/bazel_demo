load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "model_proto",
    srcs = [
        "common.proto",
        "model.proto",
    ],
    deps = [
        "@com_google_protobuf//:any_proto",
    ],
)

cc_proto_library(
    name = "model",
    visibility = ["//visibility:public"],
    deps = [":model_proto"],
)
