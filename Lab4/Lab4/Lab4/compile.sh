#!/bin/bash
g++ -o "video_store" customer.cpp customers.cpp hashtable.cpp main.cpp
valgrind ./video_store

