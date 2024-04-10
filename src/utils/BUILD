load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

# https://bazel.build/reference/be/functions#package
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "utils",
    srcs = [
        "const_singleton.h",
    ],
    # linkstatic = True,
    deps = [
        # "@com_google_absl//absl/time",
    ],
)

cc_test(
    name = "const_singleton_test",
    srcs = ["const_singleton_test.cpp"],
    deps = [
        ":utils",
        "@com_google_googletest//:gtest_main"
    ],
)
