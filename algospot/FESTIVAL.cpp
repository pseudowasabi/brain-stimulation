#include <iostream>
using namespace std;

class Festival {
    int dayCount, teamCount;
    int *costForEachDay;
    long double minimumAverageRentCost;

public:
    Festival() {
        dayCount = teamCount = 0;
        costForEachDay = nullptr;
        minimumAverageRentCost = 100.0L;
    }

    void setDayCount(int dayCount) {
        this->dayCount = dayCount;
    }

    void setTeamCount(int teamCount) {
        this->teamCount = teamCount;
    }

    void setCostForEachDay(int *costForEachDay) {
        this->costForEachDay = costForEachDay;
    }

    double getMinimumAverageRentCost() {
        // brute force

        for(int i = 0; i < dayCount; ++i) {
            int localSum = 0;
            for(int j = i; j < dayCount; ++j) {
                localSum += costForEachDay[j];

                if(j - i + 1 >= teamCount) {
                    double rentCostCandidate = double(localSum) / (j - i + 1);
                    minimumAverageRentCost = rentCostCandidate < minimumAverageRentCost? rentCostCandidate: minimumAverageRentCost;
                }
            }
        }

        return minimumAverageRentCost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout.setf(ios_base::showpoint);

    int caseCount;
    cin >> caseCount;

    Festival *festival;

    for(; caseCount > 0; --caseCount) {
        festival = new Festival();

        int dayCount, teamCount;
        int *costForEachDay;

        cin >> dayCount >> teamCount;
        if(dayCount > 0) {
            costForEachDay = new int[dayCount];
        } else {
            return -1;
        }

        for(int cost, i = 0; i < dayCount; ++i) {
            cin >> cost;
            costForEachDay[i] = cost;
        }

        festival->setDayCount(dayCount);    
        festival->setTeamCount(teamCount);
        festival->setCostForEachDay(costForEachDay);

        cout << festival->getMinimumAverageRentCost() << '\n';

        delete festival;
        delete[] costForEachDay;
    }

    return 0;
}