#ifndef STATISTICS_H
#define STATISTIcs_H

#include <vector>

namespace Statistics {

    double calculateMean(const std::vector<double>& data);
    double calculateStdDev(const std::vector<double>& data, double mean);
    double calculatePercentile(std::vector<double> data, double percentile);
    double getZScore(double condidenceLevel);

}

#endif 