#include <iostream>
using namespace std;
#include <string>
#include "RandomIdGenerator.h"

int RandomIdGenerator::nextId = 1000;

RandomIdGenerator::RandomIdGenerator(){}

RandomIdGenerator::~RandomIdGenerator(){}

int RandomIdGenerator::getNextId(){ return ++nextId; }
