//
// Created by goto1134 on 07.01.18.
//

#ifndef GRAPH_SCHEME_CPP_MPI_DATA_H
#define GRAPH_SCHEME_CPP_MPI_DATA_H

struct Data {
    const char *array;
    int length;

    Data(const char *array, int length) : array(array), length(length) {};
};

#endif //GRAPH_SCHEME_CPP_MPI_DATA_H
