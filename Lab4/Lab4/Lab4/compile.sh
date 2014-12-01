#!/bin/bash
g++ -o "video_store" rentalstore.h rentalstore.cpp main.cpp
valgrind ./video_store

