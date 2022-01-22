#!/bin/bash

# Configs. Can be changed
Port="/dev/ttyUSB0"
Board="esp32:esp32:esp32"
File=$(find . -type f -name "*.ino")


# Colors
RedColor="\\033[0;31m"
DefaultColor="\\033[0m"
GreenColor="\\033[0;32m"
BlueColor="\\033[0;34m"

if ! [ -x "$(command -v arduino-cli)" ];then
    echo -e "\n${RedColor}arduino-cli not found. Please install it.${DefaultColor}\n";
    echo -e "https://arduino.github.io/arduino-cli/latest/installation\n";
    exit 1;
fi

# compile sketch
echo -e "${BlueColor}Compiling...${DefaultColor}";
arduino-cli compile -b "$Board" "$File"
if [ $? == 0 ];then
    echo -e "\n${GreenColor}Compiled Successful${DefaultColor}";
else
    echo -e "\n${RedColor}Compiling Failed!${DefaultColor}";
    exit 1;
fi

# Upload compiled sketch to board
echo -e "${BlueColor}\nUploading...${DefaultColor}";
arduino-cli upload -b "$Board:PSRAM=disabled,PartitionScheme=huge_app,CPUFreq=240,FlashMode=qio,FlashFreq=80,FlashSize=4M,UploadSpeed=115200,DebugLevel=none" -p $Port
if [ $? == 0 ];then
    echo -e "\n${GreenColor}Upload Successful${DefaultColor}";
else
    echo -e "\n${RedColor}Upload Failed!${DefaultColor}";
    rm -r build
    exit 1;
fi

rm -r build
