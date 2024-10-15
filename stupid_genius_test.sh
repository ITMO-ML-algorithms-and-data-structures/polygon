#!/usr/bin/env bash
expected_output=$'[1, 1, 1]\n[1, 0, 0]\n[0, 1, 0]\n[0, 0, 1]'
output=$(g++ -o run count_vectorizer.cpp && ./run)

if [[ "$output" == "$expected_output" ]]; then
    echo "OK"
else
    echo "ERROR"
fi
