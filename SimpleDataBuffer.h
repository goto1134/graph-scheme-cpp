//
// Created by goto1134 on 06.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_SIMPLEDATABUFFER_H
#define GRAPH_SCHEME_CPP_MPI_SIMPLEDATABUFFER_H


#include <vector>
#include <fruit/fruit.h>
#include "Data.h"
#include "DataBuffer.h"
#include "DataReadyListener.h"

class SimpleDataBuffer : public DataBuffer {

    std::map<ModuleId, std::vector<Input>> moduleInputs;
    DataReadyListener *dataReadyListener;
public:
    INJECT(SimpleDataBuffer(DataReadyListener *procedureFactory, std::vector<ModuleData> modules)): dataReadyListener(
            procedureFactory) {

        for (ModuleData moduleData: modules) {
            std::vector<Input> inputs;
            for (int i = 0; i < moduleData.inputCount; ++i) {
                inputs.emplace_back();
            }
            moduleInputs.insert(make_pair(moduleData.id, inputs));
        }
    }

    std::map<int, Data> take(ModuleId moduleId, Tag tag) override {
        std::map<int, Data> data;
        std::vector<Input> inputs = moduleInputs[moduleId];
        for (unsigned long i = 0; i < inputs.size(); i++) {
            const auto any = inputs.at(i).get(tag);
            data.insert(std::make_pair(i, any));
        }

        return data;
    }

    bool isReady(ModuleId moduleId, Tag tag) const override {
        std::vector<Input> inputs = moduleInputs.at(moduleId);
        for (const auto &input:inputs) {
            if (!input.has(tag)) return false;
        }
        return true;
    }

    void
    put(ModuleId moduleId, int inputIndex, Tag tag, const Data &value) override {
        std::vector<Input> inputs = moduleInputs[moduleId];
        inputs[inputIndex].put(tag, value);
        if (isReady(moduleId, tag)) {
            auto data = take(moduleId, tag);
            dataReadyListener->start(moduleId, tag, data);
        }
    }
};


#endif //GRAPH_SCHEME_CPP_MPI_SIMPLEDATABUFFER_H
