#pragma once
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>
#include <windows.h>
#include <algorithm>
#include <random>

std::string caesar_encrypt(std::string text, int shifting_value);
std::string caesar_decrypt(std::string text, int shifting_value);