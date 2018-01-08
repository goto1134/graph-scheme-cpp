//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_RESULT_H
#define GRAPH_SCHEME_CPP_MPI_RESULT_H

#include <utility>
#include "Input.h"
#include "Data.h"

struct Result {
    const Tag tag;
    const InputAddress inputAddress;
    const Data data;

    Result(const Tag tag, const InputAddress &inputAddress, Data data) : tag(tag),
                                                                         inputAddress(inputAddress),
                                                                         data(std::move(data)) {}
};

#endif //GRAPH_SCHEME_CPP_MPI_RESULT_H
