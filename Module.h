//
// Created by Andrew on 28.11.2017.
//

#ifndef GRAPH_SCHEME_CPP_MODULE_H
#define GRAPH_SCHEME_CPP_MODULE_H

typedef int ModuleId;

enum ModuleFlags {
    INITIAL = 1,
    FINAL = 2
};

struct ModuleData {
    ModuleId id;
    int inputCount;
    int type;

    ModuleData(ModuleId id, int inputCount, int type = 0)
            : id(id), inputCount(inputCount), type(type) {};

    bool isInitial() {
        return ((type & INITIAL) > 0);
    }

    bool isFinal() {
        return ((type & FINAL) > 0);
    }
};

#endif //GRAPH_SCHEME_CPP_MODULE_H
