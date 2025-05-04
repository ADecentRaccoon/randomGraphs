#include "gui.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "logic.h"
#include <random>
#include <iomanip>
#include <sstream>

using namespace sf;
using namespace std;


Gui::Gui() {
    if (!font.loadFromFile("font.ttf")) {
        cerr << "Error loading font" << endl;
    }
    window.create(VideoMode(750, 750), "Erdős–Rényi model");
    srand(time(NULL));
}

void Gui::run(int nodes, vector<pair<int, int>>& graph, graphInfo& info){
    for (int i = 0; i < nodes; i++){
        createNode(i);
    }
    while (window.isOpen())
    {
        handleEvent();
        render(graph, nodes, info);
    }
}

void Gui::handleEvent(){
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed) window.close();
    }
}

void Gui::render(vector<pair<int, int>>& graph, int nodes, graphInfo& info){
    window.clear(Color::White);
    drawNodes();
    connectNodes(graph);
    renderData(info);
    window.display();
}

void Gui::createNode(int number){
    int xCoord = rand() % 500 + 1;
    int yCoord = rand() % 500 + 1;
    points.push_back(Vector2f(xCoord, yCoord));
}

void Gui::drawNodes(){
    for (int i = 0; i < points.size(); i++){
        int xCoord = points[i].x;
        int yCoord = points[i].y;
        CircleShape shape(15);
        shape.setOrigin(15,15);
        shape.setFillColor(Color::Red);
        shape.setPosition(xCoord, yCoord);

        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(12);
        text.setString(to_string(i));
        text.setPosition(xCoord, yCoord);
        window.draw(shape);
        window.draw(text);
    }
}

void Gui::connectNodes(vector<pair<int, int>>& graph){
    VertexArray line(Lines, 2);
    for (pair<int, int> connPair : graph){
        line[0].position = points[connPair.first];
        line[1].position = points[connPair.second];

        line[0].color = Color::Black;
        line[1].color = Color::Black;
        window.draw(line);
    }
}

void Gui::renderData(graphInfo& info) {
    const int Xtext = 550;

    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(Color::Black);

    text.setString(info.connected ? "Graph is connected." : "Graph is not connected.");
    text.setPosition(Xtext, 10);
    window.draw(text);

    text.setString(info.cycled ? "Graph is cyclic." : "Graph is a forest.");
    text.setPosition(Xtext, 30);
    window.draw(text);

    std::stringstream ss;
    ss << "Diameter: " << info.diameter;
    text.setString(ss.str());
    text.setPosition(Xtext, 50);
    window.draw(text);

    ss.str("");
    ss << "Average degree: " << fixed << setprecision(2) << info.degreeAverage;
    text.setString(ss.str());
    text.setPosition(Xtext, 70);
    window.draw(text);
}
