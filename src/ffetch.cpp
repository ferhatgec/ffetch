// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#include <memory>
#include <vector>
#include <fstream>
#include "../include/ffetch.hpp"

FFetch::FFetch(std::string url) : url(url) {}

int main(int argc, char** argv) noexcept {
    if(argc < 2) {
        std::cout << "ffetch - fetch fetch\n" <<
            argv[0] << " to={file} {url}\n" <<
            argv[0] << " {url}\n";

        return 1;
    }

    std::vector<std::string> args(argv, argv + argc);
    std::string to, val;

    for(auto& arg : args) {
        if(arg.substr(0, 3) == "to=") {
            to = arg.substr(3, arg.size());
        }
    }

    std::unique_ptr<FFetch> init(new FFetch(std::string(args.back())));

    init->init.setopt(CURLOPT_URL, init->url);
    init->init.setopt(CURLOPT_WRITEFUNCTION, curl4::easy::writefunc);
    init->init.setopt(CURLOPT_WRITEDATA, &val);

    CURLcode res = curl4::easy::perform(init->init);

    if(!to.empty()) {
        std::ofstream outfile(to);

        if(outfile) {
            outfile << val;
        } outfile.close();
    } else {
        std::cout << val << '\n';
    }
}