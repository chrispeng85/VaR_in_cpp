#include "VaRCalculator.h"
#include "Statistics.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

void VaRCalculator::addAsset(const Asset& asset) {

    portfolio.push_back(asset);

}

double VaRCalculator::calculateHistoricalVaR(double confidenceLevel, int holdingPeriod) const {

    if (portfolio.empty()) {

        throw std::runtime_error("empty portfolio");

    }

    std::vector<double> portfolioReturns;
    double totalValue = getTotalPortfolioValue();

    for (const auto& asset : portfolio) {
        const auto& assetReturns = asset.getReturns();

        if (portfolioReturns.empty()) {
            portfolioReturns = assetReturns;

        }

        else {

                for (size_t i = 0; i < portfolioReturns.size(); ++i) {

                        portfolioReturns[i] += assetReturns[i];
                }
        }
 

    }

    double scalingFactor = std::sqrt(holdingPeriod);
    for (double& ret: portfolioReturns) {

            ret *= scalingFactor;
    }

    double percentile = Statistics::calculatePercentile(portfolioReturns, 1.0 - confidenceLevel);
    return -totalValue * percentile;

}

double VaRCalculator::calculateParametricVaR(double confidenceLevel, int holdingPeriod) const {

        if (portfolio.empty()) {

                throw std::runtime_error("empty portfolio");
        }

        std::vector<double> portfolioReturns;
        double totalValue = getTotalPortfolioValue();

        for (const auto & asset : portfolio) {

                const auto& assetReturns = asset.getReturns();

                if (portfolioReturns.empty()) {
                        portfolioReturns = assetReturns;
                }

                else {

                        for (size_t i = 0; i < portfolioReturns.size(); ++i) {
                            
                                portfolioReturns[i] += assetReturns[i];
                }
        }
                }

        double mean = Statistics::calculateMean(portfolioReturns);
        double stdDev = Statistics::calculateStdDev(portfolioReturns, mean);
        double zScore = Statistics::getZScore(confidenceLevel);

        stdDev *= std::sqrt(holdingPeriod);

        return totalValue *zScore * stdDev;

}