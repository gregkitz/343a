#!/bin/bash
g++ -o "video_store" dvdmedia.cpp comedy.h drama.h bintree.cpp classics.h rentalstore.cpp main.cpp
valgrind ./video_store

