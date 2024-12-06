#ifndef ASSET_H
#define ASSET_H

#include <string>
#include <vector>


class Asset {

    private:
        std::string name;
        std::vector<double> returns;
        double currentValue;

    public:
        Asset(const std::string& name, double currentValue);

        void addReturn(double ret);
        const std::vector<double>& getReturns() const;
        double getCurrentValue() const;
        const std::string& getName() const;
   
};

#endif 


