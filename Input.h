//
// Created by Andrew on 28.11.2017.
//

#ifndef GRAPH_SCHEME_CPP_INPUT_H
#define GRAPH_SCHEME_CPP_INPUT_H

#include <map>
#include "Tag.h"
#include "Module.h"

template<typename T>
class Input {
private:
    std::map<Tag, T> buffer;
public:
    /**
     * Adds data with specific tag
     * @param tag tag of data
     * @param value data
     */
    void put(Tag tag, T value) throw(IllegalStateException) {
        if (has(tag)) {
            throw IllegalStateException();
        }
        buffer.insert(std::pair<int, T>(tag, value));
    }

    /**
     * @param tag
     * @return data from input with specified tag
     */
    T get(Tag tag) throw(IllegalStateException) {
        if (!has(tag)) {
            throw IllegalStateException();
        }
        return buffer.find(tag);
    }

    T remove(Tag tag) throw(IllegalStateException) {
        T value = get(tag);
        buffer.erase(tag);
        return value;
    }

    bool has(Tag tag) {
        return buffer.count(tag) > 0;
    }
};
class ControlInput : public Input<bool> {
};
class IllegalStateException : std::exception {
};

#endif //GRAPH_SCHEME_CPP_INPUT_H
