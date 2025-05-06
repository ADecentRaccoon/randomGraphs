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
    }else if (request.typeOfModel == 3) {
        graph = createGnm(10, 10);
        request.nodes = 10;
        vector<pair<int, int>> graph2 = createGnm(request.nodes, 3);
        vector<pair<int, int>> graph3 = createGnp(request.nodes, 0.2);
        vector<pair<int, int>> graph4 = createGnp(request.nodes, 0.015);
        Gui gui2;
        Gui gui3;
        Gui gui4;
        info = getGraphInfo(graph, request.nodes);
        graphInfo info2 = getGraphInfo(graph2, request.nodes);
        graphInfo info3 = getGraphInfo(graph3, request.nodes);
        graphInfo info4 = getGraphInfo(graph4, request.nodes);
        gui.run(request.nodes, graph,info, request);
        gui2.run(request.nodes, graph2,info2, request);
        gui3.run(request.nodes, graph3,info3, request);
        gui4.run(request.nodes, graph4,info4, request);
        return 0;
    }
    info = getGraphInfo(graph, request.nodes);
    
    gui.run(request.nodes, graph, info,request);
    return 0;
}