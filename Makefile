# Компиляторы
CXX_WINDOWS = x86_64-w64-mingw32-g++

# Пути
SFML_WINDOWS_DIR = /home/user/code/c++/libs/SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.0

# Файлы
SRC = /home/user/code/c++/Cpp/RandomGrafs
OUT_WINDOWS = app.exe

# Флаги
CXXFLAGS_LINUX = -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS_WINDOWS = -mconsole -I$(SFML_WINDOWS_DIR)/include \
  -L$(SFML_WINDOWS_DIR)/lib \
  -lsfml-graphics -lsfml-window -lsfml-system

default:
	$(CXX_WINDOWS) /home/user/code/c++/Cpp/RandomGrafs/main.cpp /home/user/code/c++/Cpp/RandomGrafs /home/user/code/c++/Cpp/RandomGrafs/getUserData.cpp /home/user/code/c++/Cpp/RandomGrafs/gui.cpp -o $(OUT_WINDOWS) $(CXXFLAGS_WINDOWS)
