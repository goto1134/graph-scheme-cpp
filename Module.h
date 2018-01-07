//
// Created by Andrew on 28.11.2017.
//

#ifndef GRAPH_SCHEME_CPP_MODULE_H
#define GRAPH_SCHEME_CPP_MODULE_H

typedef int ModuleId;

struct ModuleData {
    ModuleId id;
    int inputCount;
    bool isInitial;

    ModuleData(ModuleId id, int inputCount, bool isInitial = false)
            : id(id), inputCount(inputCount), isInitial(isInitial) {};
};

#endif //GRAPH_SCHEME_CPP_MODULE_H
