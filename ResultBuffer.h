//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_RESULTBUFFER_H
#define GRAPH_SCHEME_CPP_MPI_RESULTBUFFER_H

#include "Result.h"

class ResultBuffer {
public:
    virtual void put(Result *result) = 0;

    virtual Result *take() = 0;

    virtual bool empty() = 0;
};

#endif //GRAPH_SCHEME_CPP_MPI_RESULTBUFFER_H
