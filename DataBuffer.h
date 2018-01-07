//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_DATABUFFER_H
#define GRAPH_SCHEME_CPP_MPI_DATABUFFER_H

#include <experimental/any>
#include <map>
#include "Tag.h"
#include "Module.h"
#include "Input.h"
#include "Data.h"

class DataBuffer {
public:
    virtual std::map<int, Data> take(ModuleId moduleId, Tag tag) = 0;

    virtual bool isReady(ModuleId moduleId, Tag tag) const = 0;

    virtual void
    put(ModuleId moduleId, int inputIndex, Tag tag, const Data &value) = 0;
};

#endif //GRAPH_SCHEME_CPP_MPI_DATABUFFER_H

