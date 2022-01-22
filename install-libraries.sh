#!/bin/bash


if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    ArduinoCLI=arduino
elif [[ "$OSTYPE" == "darwin"* ]]; then
    ArduinoCLI=/Applications/Arduino.app/Contents/MacOS/Arduino
else
    exit 1;
fi

if [ -x "$(command -v arduino-cli)" ];then
    while read p; do
        Package=$(echo "$p" | tr : @);
        echo -e "\n\\033[0;34mInstalling $Package\\033[0m";
        arduino-cli lib install "$Package";
        if [ $? != 0 ];then exit 1;fi;
    done <libraries.txt;
else

    while read p; do
        echo -e "\n\n\\033[0;34mInstalling $p\\033[0m\n\n";
        $ArduinoCLI --install-library "$p";
        if [ $? != 0 ];then exit 1;fi;
    done <libraries.txt;
fi



