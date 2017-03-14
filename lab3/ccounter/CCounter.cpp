//
// Created by rencpawe on 14.03.17.
//
#include <string>
#include <memory>
#include <map>
#include "CCounter.h"



std::unique_ptr <Counter> Init();

void Inc(std::string key, std::unique_ptr <Counter> *counter);

int Counts(const std::unique_ptr <Counter> &counter, std::string key);

void SetCountsTo(std::string key, int value, std::unique_ptr <Counter> *counter);