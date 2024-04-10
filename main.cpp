#include <iostream>
#include <string>
#include "src/config/clang.h"
#include "src/utils/const_singleton.h"

using Str = example::utils::ConstSingleton<std::string>;

int main() {
    std::cout << "data: " << Str::get() << std::endl;
    std::cout << example::config::clang_version() << std::endl;
}