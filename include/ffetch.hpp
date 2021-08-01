// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef FFETCH_FFETCH_HPP
#define FFETCH_FFETCH_HPP

#include <iostream>
#include <string>

#include "../libs/curl4cpp/curl4.hpp"

class FFetch {
public:
    curl4::CURL4 init = curl4::easy::init();
    std::string url;
public:
    FFetch(std::string url);
    ~FFetch()= default;
};

#endif // FFETCH_FFETCH_HPP
