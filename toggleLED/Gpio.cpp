// File name: myGpio.cpp

#include"Gpio.h"
#include<fstream>
#include<iostream>

using namespace std;

MYGPIO::MYGPIO(int number) {
  path = "/sys/class/gpio/gpio" + to_string(number) + "/";
}

int MYGPIO::getNumber() {
  return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir) {
    string dirStr = (dir == OUTPUT) ? "out" : "in";
     write(path, "direction", dirStr);
 }

GPIO_DIRECTION MYGPIO::getDirection() {
  string direction = read(path, "direction");
  return (direction == "out") ? OUTPUT : INPUT;
}

int MYGPIO::setValue(GPIO_VALUE val) {
  return write(path, "value", val);
}

GPIO_VALUE MYGPIO::getValue() {
  int value = stoi(read(path, "value"));
  return (value == 1) ? HIGH : LOW;
}

void MYGPIO::toggleOutput() {
  GPIO_VALUE currentValue = getValue();
  setValue((currentValue == HIGH) ? LOW : HIGH);
}

MYGPIO::~MYGPIO() { }

int MYGPIO::write(string path, string filename, string value) {
  ofstream file(path + filename);
    file << value;
    file.close();
    return 0;
}

int MYGPIO::write(string path, string filename, int value) {
  return write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename) {
  ifstream file(path + filename);
  string value;
  if (file.is_open()) {
    getline(file, value);
    file.close();
  } 
   return value;
}                                                
