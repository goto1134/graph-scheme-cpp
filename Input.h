//
// Created by Andrew on 28.11.2017.
//

#ifndef GRAPH_SCHEME_CPP_INPUT_H
#define GRAPH_SCHEME_CPP_INPUT_H

#include <map>
#include <experimental/any>
#include "Tag.h"
#include "Module.h"
#include "Data.h"

class IllegalStateException : std::exception {
};

struct InputAddress {
    ModuleId moduleId;
    int input;
};

class Input {
private:
    std::map<Tag, Data> buffer;
public:
    /**
     * Adds data with specific tag
     * @param tag tag of data
     * @param value data
     */
    void put(Tag tag, Data value) throw(IllegalStateException) {
        if (has(tag)) {
            throw IllegalStateException();
        }
        buffer.insert(std::make_pair(tag, value));
    }

    /**
     * @param tag
     * @return data from input with specified tag
     */
    Data get(Tag tag) const throw(IllegalStateException) {
        if (!has(tag)) {
            throw IllegalStateException();
        }
        return buffer.at(tag);
    }

    Data remove(Tag tag) throw(IllegalStateException) {
        Data value = get(tag);
        buffer.erase(tag);
        return value;
    }

    bool has(Tag tag) const {
        return buffer.count(tag) > 0;
    }
};

#endif //GRAPH_SCHEME_CPP_INPUT_H
