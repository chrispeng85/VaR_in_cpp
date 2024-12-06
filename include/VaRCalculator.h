#ifndef VAR_CALCULATOR_H
#define VAR_CALCULATOR_H

#include "Asset.h"
#include <vector>
#include <string>

class VaRCalculator {

    private: 
        std::vector<Asset> portfolio;

    public:
        void addAsset(const Asset& asset);
        double calculateHistoricalVaR(double confidenceLevel, int holdingPeriod = 1) const;
        double calculateParametricVaR(double confidenceLevel, int holdingPeriod = 1) const;
        double getTotalPortfolioValue() const;


};

#endif 