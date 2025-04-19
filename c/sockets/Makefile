BUILD_DIR = build

all: clean
	gcc server.c -o $(BUILD_DIR)/server
	gcc client.c -o $(BUILD_DIR)/client

clean: 
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
