//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_RESULTBUFFER_H
#define GRAPH_SCHEME_CPP_MPI_RESULTBUFFER_H

#include <queue>
#include "Result.h"

class ResultBuffer {
    std::queue<Result *> buffer;
public:
    void put(Result *result) {
        buffer.push(result);
    }

    Result *take() {
        const auto pResult = buffer.front();
        buffer.pop();
        return pResult;
    }

    bool empty() {
        return buffer.empty();
    }
};

#endif //GRAPH_SCHEME_CPP_MPI_RESULTBUFFER_H
