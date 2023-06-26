/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

namespace Example {

namespace Utils {

/**
 * ConstSingleton allows easy global cross-thread access to a const object.
 *
 * This singleton should be used for data which is initialized once at
 * start-up and then be treated as immutable const data thereafter.
 */
template <class T>
class ConstSingleton {
public:
    /**
     * Obtain an instance of the singleton for class T.
     * @return const T& a reference to the singleton for class T.
     */
    static const T &get() {
        static T *instance = new T();
        return *instance;
    }
};
} // namespace Utils
} // namespace Example
