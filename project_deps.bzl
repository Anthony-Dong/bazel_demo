load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# https://bazel.build/rules/lib/repo/http#http_archive
def project_dependencies():
    # absl
    http_archive(
        name = "com_google_absl",
        urls = ["https://github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz"],
        strip_prefix = "abseil-cpp-20220623.1",
        sha256 = "91ac87d30cc6d79f9ab974c51874a704de9c2647c40f6932597329a282217ba8",
    )

    http_archive(
        name = "bazel_skylib",
        urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz"],
        sha256 = "f7be3474d42aae265405a592bb7da8e171919d74c16f082a5457840f06054728",
    )

    http_archive(
        name = "com_github_google_benchmark",
        urls = ["https://github.com/google/benchmark/archive/bf585a2789e30585b4e3ce6baf11ef2750b54677.zip"],
        strip_prefix = "benchmark-bf585a2789e30585b4e3ce6baf11ef2750b54677",
        sha256 = "2a778d821997df7d8646c9c59b8edb9a573a6e04c534c01892a40aa524a7b68c",
    )

    # https://github.com/google/googletest/commits/release-1.12.1
    http_archive(
        name = "com_google_googletest",
        urls = ["https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip"],
        strip_prefix = "googletest-58d77fa8070e8cec2dc1ed015d66b454c8d78850",
    )

    # proto buf dep
    http_archive(
        name = "com_google_protobuf",
        urls = ["https://github.com/protocolbuffers/protobuf/archive/refs/tags/v3.19.0.tar.gz"],
        strip_prefix = "protobuf-3.19.0",
        sha256 = "4a045294ec76cb6eae990a21adb5d8b3c78be486f1507faa601541d1ccefbd6b",
    )
