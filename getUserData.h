#ifndef GETUSERDATA
#define GETUSERDATA

#include <vector>
#include <utility>

struct UsersData{
    short int typeOfModel;
    float PorVec;
    int unsigned nodes;
};

UsersData getUserRequest();
std::vector<std::pair<int, int>> createGnm(int quantityOfNodes, int quantityOfEdges);

#endif