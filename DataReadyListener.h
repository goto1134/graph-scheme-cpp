//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_PROCEDUREFACTORY_H
#define GRAPH_SCHEME_CPP_MPI_PROCEDUREFACTORY_H

#include <experimental/any>
#include <map>
#include "Tag.h"

class DataReadyListener {
public:
    virtual void start(ModuleId moduleId, Tag tag, const std::map<int, std::experimental::any> &data);
};

#endif //GRAPH_SCHEME_CPP_MPI_PROCEDUREFACTORY_H
