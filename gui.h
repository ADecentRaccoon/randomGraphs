#ifndef GUI
#define GUI

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "logic.h"
#include "getUserData.h"


class Gui {
public:
    Gui();
    void run(int nodes, vector<pair<int, int>>& graph, graphInfo& info, UsersData& request);

private:
    sf::RenderWindow window;
    std::vector<sf::Vector2f> points;
    sf::Text text;
    sf::Font font;

    void handleEvent();
    void render(vector<pair<int, int>>& graph, int nodes, graphInfo& info, UsersData& request);
    void createNode(int number);
    void drawNodes();
    void connectNodes(std::vector<std::pair<int, int>>& graph);
    void renderData(graphInfo& info, UsersData& request);
};

#endif
