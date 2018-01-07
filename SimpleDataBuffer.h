//
// Created by goto1134 on 06.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_SIMPLEDATABUFFER_H
#define GRAPH_SCHEME_CPP_MPI_SIMPLEDATABUFFER_H


#include <vector>
#include "DataBuffer.h"
#include "DataReadyListener.h"

class SimpleDataBuffer : public DataBuffer {

    std::map<ModuleId, std::vector<Input>> moduleInputs;
    DataReadyListener *dataReadyListener;
public:
    SimpleDataBuffer(DataReadyListener *procedureFactory, std::vector<ModuleData> modules) : dataReadyListener(
            procedureFactory) {

        for (ModuleData moduleData: modules) {
            std::vector<Input> inputs;
            for (int i = 0; i < moduleData.inputCount; ++i) {
                inputs.emplace_back();
            }
            moduleInputs.insert(make_pair(moduleData.id, inputs));
        }
    }

    std::map<int, std::experimental::fundamentals_v1::any> take(ModuleId moduleId, Tag tag) override {
        std::map<int, std::experimental::fundamentals_v1::any> data;
        std::vector<Input> inputs = moduleInputs[moduleId];
        for (unsigned long i = 0; i < inputs.size(); i++) {
            const auto any = inputs.at(i).get(tag);
            data.insert(std::make_pair(i, any));
        }

        return data;
    }

    bool isReady(ModuleId moduleId, Tag tag) const override {
        std::vector<Input> inputs = moduleInputs[moduleId];
        for (const auto &input:inputs) {
            if (!input.has(tag)) return false;
        }
        return true;
    }

    void
    put(ModuleId moduleId, int inputIndex, Tag tag, const std::experimental::fundamentals_v1::any &value) override {
        std::vector<Input> inputs = moduleInputs[moduleId];
        inputs[inputIndex].put(tag, value);
        if (isReady(moduleId, tag)) {
            auto data = take(moduleId, tag);
            dataReadyListener->start(moduleId, tag, data);
        }
    }
};


#endif //GRAPH_SCHEME_CPP_MPI_SIMPLEDATABUFFER_H
