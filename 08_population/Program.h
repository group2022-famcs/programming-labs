#include <string>

class Program {
public:
    void readWorldCountriesFromFile(
        const std::string& fileCountries, const std::string& filePopulation, char delimiter
    );

    void writeWorldPopulationToFile(const std::string& file, char delimiter);

    void writeWorldRegionPopulationToFile(const std::string& file, char delimiter);
};
