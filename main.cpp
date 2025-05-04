#include "getUserData.h"
#include "gui.h"
#include "logic.h"
#include <vector>
using namespace std;

int main(){
    Gui gui;
    UsersData request;
    vector<pair<int, int>> graph;
    graphInfo info;

    request = getUserRequest();
    if (request.typeOfModel == 1){
        graph = createGnp(request.nodes, request.PorVec);
    }else if (request.typeOfModel == 2)
    {
        graph = createGnm(request.nodes, request.PorVec);
    }
    info = getGraphInfo(graph, request.nodes);
    
    gui.run(request.nodes, graph, info);
}