load("@rules_cc//cc:defs.bzl", "cc_binary")

# https://bazel.build/reference/be/functions#package
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "utils",
    srcs = [
        "const_singleton.h",
        "threadsafe_singleton.h",
        "time.h",
    ],
    linkstatic = True,
    deps = [
        "@com_google_absl//absl/time",
    ],
)

cc_test(
    name = "time_test",
    size = "small",
    srcs = ["time_test.cpp"],
    deps = [
        ":utils",
        "@com_google_googletest//:gtest_main",
    ],
)
