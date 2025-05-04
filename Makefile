default:
	g++ main.cpp getUserData.cpp logic.cpp gui.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system && ./app
