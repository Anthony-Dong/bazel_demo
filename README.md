# Bazel 示例

# 环境
- C++ 20
- llvm14 / clang14
- mac/linux

# 开始

1. 定义一个 `WORKSPACE` 文件，主要是申明一下 项目的依赖关系

```python
# 项目名称
workspace(name = "bazel_demo")
```

2. 定义 `BUILD` 文件

```python
load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
    ],
    deps = [
        "//src/utils:utils",
        "//src/config:config"
    ],
)
```

# 运行

1. 运行
```shell
bazel 'build' '--compilation_mode=dbg' '//:main'
```

2. 查看构建流程

```shell
bazel aquery //:main
```

# 内置规则

1. http_archive https://bazel.build/rules/lib/repo/http#http_archive

```shell
http_archive(
	name = "com_google_absl",  # namespace name
	urls = ["https://github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz"],  # 下载地址
	strip_prefix = "abseil-cpp-20220623.1",
	sha256 = "91ac87d30cc6d79f9ab974c51874a704de9c2647c40f6932597329a282217ba8",  # 下载文件的sha256，这个你不写也行
)
```

我觉得大家比较疑惑的是 strip_prefix，本质上就是因为我们下载的这些依赖文件吧，解压出来的路径有问题，需要移除掉有问题的前缀路径，最终需要此路径可以查找到`WORKSPACE` 文件

```shell
# 1. 下载
wget https://github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz
# 2. 解压
tar -zxvf 20220623.1.tar.gz
# 3. http_archive 需要寻找解压文件的 WORKSPACE 文件, 因此需要 strip_prefix `abseil-cpp-20220623.1`
➜  software ls -al  abseil-cpp-20220623.1 | grep 'WORKSPACE'
-rw-r--r--  1 bytedance staff  2556  9  1  2022 WORKSPACE
```

2. proto_library https://docs.bazel.build/versions/master/be/protocol-buffer.html#proto_library

# 一些问题
1. Bazel 的进阶资料特别少，只能看官方文档了，以及参考一些开源项目的实践，不行问GPT
2. 开发者工具的话，clion傻瓜，vscode灵活，vscode配置可以我的配置 [settings.json](./.vscode/settings.json)
3. 限制bazel构建版本:  `.bazelversion` 文件填入版本，推荐下载 https://github.com/bazelbuild/bazelisk 工具替换 bazel
4. bazel构建配置: `.bazelrc` 文件填入构建配置

# 其他文档[doc](./doc)