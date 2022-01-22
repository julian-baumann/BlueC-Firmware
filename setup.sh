#!/bin/bash

if ! [ -x "$(command -v arduino-cli)" ];then
    echo -e "\n${RedColor}arduino-cli not found. Please install it.${DefaultColor}\n";
    echo -e "https://arduino.github.io/arduino-cli/latest/installation\n";
    exit 1;
fi

arduino-cli core update-index
arduino-cli core install esp32:esp32

./install-libraries.sh
