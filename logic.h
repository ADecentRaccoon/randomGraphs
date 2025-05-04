#ifndef LOGIC
#define LOGIC

#include <vector>
#include <utility>
using namespace std;

struct graphInfo
{
    bool connected;
    int diameter;
    double degreeAverage;
    bool cycled;
};

std::vector<std::pair<int, int>> createGnp(int quantityOfNodes, float probability);
std::vector<std::pair<int, int>> createGnm(int quantityOfNodes, int quantityOfEdges);

graphInfo getGraphInfo(vector<pair<int, int>>& graph, int nodes);

#endif