# Compiler and compiler flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Header files
DEPS = $(wildcard $(SRC_DIR)/*.hpp)

# Output executable
TARGET = $(BIN_DIR)/demo

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean
