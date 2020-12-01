#pragma once

#include <Config.hh>

#include <fstream>
#include <string>

class Stream {
    std::ifstream m_ifstream;
    std::string m_line;

public:
    explicit Stream(std::string &&path) : m_ifstream(ROOT_PATH + path) {}

    std::string *next() {
        std::getline(m_ifstream, m_line);
        if (!m_ifstream) {
            return nullptr;
        }
        return &m_line;
    }
};
