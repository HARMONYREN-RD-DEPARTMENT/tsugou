PROJECT_NAME := tsu
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
TARGET := $(BUILD_DIR)/$(PROJECT_NAME)

SRC_FILES := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
HEADER_FILES := $(shell find $(INCLUDE_DIR) -type f -name "*.hpp")

OBJ_FILES += $(wildcard libs/*.a)

CXX := g++
CXX_FLAGS := -static -std=c++17 -O3 -I$(INCLUDE_DIR)
LD_FLAGS := -lcrypto # -lyaml-cpp

all: $(TARGET)

$(TARGET): $(OBJ_FILES) | $(HEADER_FILES)
	@ mkdir -p $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LD_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

clean:
	@ rm -rf $(BUILD_DIR)

setup:
	mkdir -p libs
	mkdir -p tmp && cd tmp && \
		git clone https://github.com/HARMONYREN-RD-DEPARTMENT/libharmonyren.git && \
		cp libharmonyren/build/libharmonyren.a ../libs && \
		cp -r libharmonyren/include ../
	rm -rf tmp
	
test:
	docker-compose down && docker-compose build && docker-compose run test /bin/bash

install: $(TARGET)
	cp $(TARGET) /bin/tsu



.PHONY: all clean install test setup

DIST_DIR := dist
WIN_TARGET := $(DIST_DIR)/$(PROJECT_NAME).exe
LINUX_TARGET := $(DIST_DIR)/$(PROJECT_NAME)

release: $(LINUX_TARGET) $(WIN_TARGET)

$(LINUX_TARGET): $(OBJ_FILES) | $(HEADER_FILES)
	@ mkdir -p $(DIST_DIR)
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LD_FLAGS)

$(WIN_TARGET): $(SRC_FILES) $(HEADER_FILES)
	@ mkdir -p $(DIST_DIR)
	x86_64-w64-mingw32-g++ -static -std=c++17 -O3 -I$(INCLUDE_DIR) $(SRC_FILES) -o $@ -lcrypto

.PHONY: release
