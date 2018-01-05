//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_DATABUFFER_H
#define GRAPH_SCHEME_CPP_MPI_DATABUFFER_H

#include"Input.h"
#include <vector>
#include <experimental/any>
#include <fruit/fruit.h>


class DataBuffer {
private:
    std::vector<Input> inputs;
public:

    std::map<int, std::experimental::any> take(Tag tag) {
        std::map<int, std::experimental::any> data;

        for (unsigned long i = 0; i < inputs.size(); i++) {
            const auto any = inputs.at(i).get(tag);
            data.insert(std::make_pair(i, any));
        }

        return data;
    }

    bool isReady(Tag tag) const {
        for (const auto &input:inputs) {
            if (!input.has(tag)) return false;
        }
        return true;
    }

    void put(int inputIndex, Tag tag, const std::experimental::any &value) {
        inputs[inputIndex].put(tag, value);
    }

};

#endif //GRAPH_SCHEME_CPP_MPI_DATABUFFER_H

