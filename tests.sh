#!/bin/bash

NC='\033[0m' # No Color
RED='\033[0;31m'
GREEN='\033[0;32m'

TEST1=$(./german-translator haus german english)

if [[ $TEST1 == *"house"* ]]; then
	echo -e "Test 1 - ${GREEN}OK${NC}"
else
	echo -e "Test 1 - ${RED}ERROR${NC}"
fi

TEST2=$(./german-translator haus german french)

if [[ $TEST2 == *"maison"* ]]; then
	echo -e "Test 2 - ${GREEN}OK${NC}"
else
	echo -e "Test 2 - ${RED}ERROR${NC}"
fi

TEST3=$(./german-translator haus german portuguese)

if [[ $TEST3 == *"casa"* ]]; then
	echo -e "Test 3 - ${GREEN}OK${NC}"
else
	echo -e "Test 3 - ${RED}ERROR${NC}"
fi

TEST4=$(./german-translator haus german russian)

if [[ $TEST4 == *"дом"* ]]; then
	echo -e "Test 4 - ${GREEN}OK${NC}"
else
	echo -e "Test 4 - ${RED}ERROR${NC}"
fi

TEST5=$(./german-translator DEVELOPMENT english german)

if [[ $TEST5 == *"Entwicklung"* ]]; then
	echo -e "Test 5 - ${GREEN}OK${NC}"
else
	echo -e "Test 5 - ${RED}ERROR${NC}"
fi

TEST6=$(./german-translator Computador portuguese german)

if [[ $TEST6 == *"Computer"* ]]; then
	echo -e "Test 6 - ${GREEN}OK${NC}"
else
	echo -e "Test 6 - ${RED}ERROR${NC}"
fi
