#include "Statistics.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace Statistics {

    double calculateMean(const std::vector<double>& data) {

        if (data.empty()) {
            throw std::runtime_error("cannot calculate mean of empty dataset");

        }

        double sum = 0.0;

        for (double value: data ) {
            sum += value;

        }

        return sum / data.size();
    }


    double calculateStdDev(const std::vector<double>& data, double mean) {

        if (data.size() < 2) {

            throw std::runtime_error("Need at least two data points for standard deviation");
        }

        double sum_sq = 0.0;
        for (double value : data) {

            sum_sq += (value - mean) * (value - mean);
        }
        return std::sqrt(sum_sq / (data.size() - 1));

    }

    double calculatePercentile(std::vector<double> data, double percentile) {

        if (data.empty()) {

                throw std::runtime_error("cannot calculate percentile on empty dataset");

        }

        if (percentile < 0.0 || percentile > 1.0) {

            throw std::runtime_error("percentile must be between 0 and 1");

        }

        std::sort(data.begin(), data.end());
        int index = static_cast<int>(std::ceil(percentile * data.size())) -1;

        return data[index];

    }

    double getZScore(double confidenceLevel) {

        if (confidenceLevel == 0.95) return 1.645;
        if (confidenceLevel == 0.99) return 2.326;
        throw std::runtime_error("Unsupported confidence level");
        

    }
}