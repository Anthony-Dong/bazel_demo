# 下载插件

1. CodeLLDB  debug工具 https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb
2. clangd 插件


# 配置 vscode

1. .vscode/settings.json 配置

```json
"clangd.path": "/usr/local/opt/llvm@14/bin/clangd",
"clangd.arguments": [
    "--all-scopes-completion",
    "--completion-style=bundled",
    "--cross-file-rename",
    "--background-index",
    "--clang-tidy",
    "--log=error",
    "--pretty",
    "--fallback-style=google",
    "--pch-storage=disk",
],
```

2. 配置 bazel 

使用 https://github.com/hedronvision/bazel-compile-commands-extractor 生成 compile_commands.json 文件

推荐自己配置规则

3. 愉快的使用！
