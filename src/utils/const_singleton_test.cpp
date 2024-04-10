#include "src/utils/const_singleton.h"
#include <iostream>
#include "gtest/gtest.h"

struct MyStruct {

    int num;
};

using MyStructSingleton = example::utils::ConstSingleton<MyStruct>;

TEST(const_singleton,struct) {
    {
        auto &ss = MyStructSingleton::get();
        std::cout << &ss << std::endl;
    }
    {
        auto &ss = MyStructSingleton::get();
        std::cout << &ss << std::endl;
    }

    GTEST_LOG_(INFO) << "This is an info log struct1";
}


TEST(const_singleton,struct2) {
    {
        auto &ss = MyStructSingleton::get();
        std::cout << &ss << std::endl;
    }
    {
        auto &ss = MyStructSingleton::get();
        std::cout << &ss << std::endl;
    }

    GTEST_LOG_(INFO) << "This is an info log struct2";
}

