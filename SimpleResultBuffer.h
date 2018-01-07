//
// Created by goto1134 on 07.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_SIMPLERESULTBUFFER_H
#define GRAPH_SCHEME_CPP_MPI_SIMPLERESULTBUFFER_H

#include <fruit/fruit.h>
#include <queue>
#include "ResultBuffer.h"

class SimpleResultBuffer : public ResultBuffer {
private:
    std::queue<Result *> buffer;
public:
    INJECT(SimpleResultBuffer()) = default;

    void put(Result *result) override {
        buffer.push(result);
    }

    Result *take() override {
        const auto pResult = buffer.front();
        buffer.pop();
        return pResult;
    }

    bool empty() override {
        return buffer.empty();
    }
};

fruit::Component<ResultBuffer> getSimpleResultBuffer() {
    return fruit::createComponent().bind<ResultBuffer, SimpleResultBuffer>();
}

#endif //GRAPH_SCHEME_CPP_MPI_SIMPLERESULTBUFFER_H
