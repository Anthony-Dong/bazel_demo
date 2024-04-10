


1. 在 namespace 文件中添加

```python
# init protobuf dep
# https://github.com/bazelbuild/rules_proto/releases/tag/4.0.0
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()
```

2. 编译Protobuf

```shell
➜  bazel_demo git:(master) ✗ tree -L 2 src/model/
src/model/
├── BUILD
├── common.proto
└── model.proto
```

> 注意PB include 是基于项目根路径进行引用

- BUILD 文件

```python
load("@rules_proto//proto:defs.bzl", "proto_library")

# 定义pb文件
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

# 编译cpp文件
cc_proto_library(
    name = "model",
    visibility = ["//visibility:public"],
    deps = [":model_proto"],
)
```