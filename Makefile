CXX = g++
CXXCFLAGS = -std=c++2a -g -Wall -Wextra -Werror -pedantic
SRC_DIR = ./src
BUILD_DIR = ./build
INC_DIR = ./include
LIB_DIR = ./lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Création du dossier build s'il n'existe pas
$(shell mkdir -p $(BUILD_DIR))

# Obtention de la liste de tous les fichiers .cpp dans le répertoire SRC_DIR
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Création de la liste des fichiers objets dans BUILD_DIR
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Liste des fichiers header utilisés dans le projet
HEADERS := $(wildcard $(SRC_DIR)/*.hpp)

# Règle par défaut
all: compile link execute

# Compilation des fichiers objets
compile: $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) -c $< -o $@ $(CXXCFLAGS) -I$(INC_DIR)

# Édition des liens
link: $(OBJS)
	$(CXX) $^ -o $(BUILD_DIR)/main -L$(LIB_DIR) $(LIBS)

# Nettoyage
clean:
	cd $(BUILD_DIR) && del *.o && del *.exe

# Exécution
execute:
	$(BUILD_DIR)/main.exe
