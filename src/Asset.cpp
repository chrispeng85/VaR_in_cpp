#include "Asset.h"

Asset::Asset(const std::string& name, double currentValue)
    :name(name), currentValue(currentValue) {}

void Asset::addReturn(double ret) {
    returns.push_back(ret);

}

const std::vector<double>& Asset::getReturns() const {
    return returns;

}

double Asset::getCurrentValue() const {
        return currentValue;
}

const std::string& Asset::getName() const {
    return name;

}