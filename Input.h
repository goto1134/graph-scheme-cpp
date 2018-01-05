//
// Created by Andrew on 28.11.2017.
//

#ifndef GRAPH_SCHEME_CPP_INPUT_H
#define GRAPH_SCHEME_CPP_INPUT_H

#include <map>
#include <experimental/any>
#include "Tag.h"
#include "Module.h"

class IllegalStateException : std::exception {
};

class Input {
private:
    std::map<Tag, std::experimental::any> buffer;
public:
    /**
     * Adds data with specific tag
     * @param tag tag of data
     * @param value data
     */
    void put(Tag tag, std::experimental::any value) throw(IllegalStateException) {
        if (has(tag)) {
            throw IllegalStateException();
        }
        buffer.insert(std::make_pair(tag, value));
    }

    /**
     * @param tag
     * @return data from input with specified tag
     */
    std::experimental::any get(Tag tag) const throw(IllegalStateException) {
        if (!has(tag)) {
            throw IllegalStateException();
        }
        return buffer.find(tag);
    }

    std::experimental::any remove(Tag tag) throw(IllegalStateException) {
        std::experimental::any value = get(tag);
        buffer.erase(tag);
        return value;
    }

    bool has(Tag tag) const {
        return buffer.count(tag) > 0;
    }
};

#endif //GRAPH_SCHEME_CPP_INPUT_H
