//
// Created by goto1134 on 05.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_DATEREADYLISTENER_H
#define GRAPH_SCHEME_CPP_MPI_DATEREADYLISTENER_H

#include <map>
#include "Module.h"
#include "Tag.h"
#include "Data.h"

class DataReadyListener {
public:
    virtual void start(ModuleId moduleId, Tag tag, const std::map<int, Data> &data) = 0;
};

#endif //GRAPH_SCHEME_CPP_MPI_DATEREADYLISTENER_H
