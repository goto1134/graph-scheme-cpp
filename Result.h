//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_RESULT_H
#define GRAPH_SCHEME_CPP_MPI_RESULT_H

#include <utility>

#include "Input.h"

class Result {
private:
    const Tag tag;
    const InputAddress inputAddress;
    const std::experimental::any data;
public:
    Result(const Tag tag, const InputAddress &inputAddress, std::experimental::any data) : tag(tag),
                                                                                           inputAddress(inputAddress),
                                                                                           data(std::move(data)) {}

    const InputAddress &getInputAddress() const {
        return inputAddress;
    }

    const std::experimental::any &getData() const {
        return data;
    }
};

#endif //GRAPH_SCHEME_CPP_MPI_RESULT_H
