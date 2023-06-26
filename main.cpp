#include <iostream>
#include "absl/strings/str_format.h"
#include "src/utils/time.h"
#include "src/utils/threadsafe_singleton.h"
#include "src/model/model.pb.h"
#include "google/protobuf/util/json_util.h"

using SingletonList = Example::Utils::ThreadSafeSingleton<std::vector<std::string>>;

int main() {
    std::string format_str = absl::StrFormat("Welcome to %s, Number %d!", "The Village", 6);
    std::cout << format_str << std::endl;
    std::cout << Example::Utils::LocalTime() << std::endl;
    std::cout << Example::Utils::UnixTime(1686813191) << std::endl;

    SingletonList::get().emplace_back("k1");
    SingletonList::get().emplace_back("k2");
    std::for_each(SingletonList::get().begin(), SingletonList::get().end(),
                  [](const std::string &elem) { std::cout << elem << std::endl; });

    Example::Model::People people{};
    people.set_name("tom");
    people.set_id(1);
    std::string output{};
    google::protobuf::util::JsonOptions ops;
    google::protobuf::util::MessageToJsonString(people, &output, ops);

    std::cout << "data: " << output << std::endl;
}