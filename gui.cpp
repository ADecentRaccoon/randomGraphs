#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
using namespace sf;
using namespace std;

class Gui{
public:
    Gui() {
        if (!font.loadFromFile("font.ttf")) {
            cerr << "Error loading font" << endl;
        }
        window.create(VideoMode(750, 750), "Erdős–Rényi model");
        srand(time(NULL));
    }

    void run(){
        for (int i = 0; i < 10; i++){
            createNode(i);
        }
        while (window.isOpen())
        {
            handleEvent();
            render();
        }
        
    }

private:
    RenderWindow window;
    vector<Vector2f> points;
    Text text;
    Font font;
    void handleEvent(){
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }
        
    }

    void render(){
        window.clear(Color::White);
        drawNodes();
        connectNodes(3, 4);
        window.display();
    }


    void createNode(int number){
        int xCoord = rand() % 700 + 1;
        int yCoord = rand() % 700 + 1;
        cout << xCoord << endl;
        cout << yCoord << endl;
        points.push_back(Vector2f(xCoord, yCoord));
    }

    void drawNodes(){
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

    void connectNodes(int firstPoint, int secondPoint){
        VertexArray line(Lines, 2);
        line[0].position = points[firstPoint];
        line[1].position = points[secondPoint];
        
        line[0].color = Color::Black;
        line[1].color = Color::Black;
        window.draw(line);
    }
};

int main(){
    Gui gui;
    gui.run();
    return 0;
}