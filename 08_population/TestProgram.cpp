#include "Country.h"
#include "CountryService.h"
#include "Program.h"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>

TEST(Country, ToString) {
    Country country{"Afghanistan", "AFG", {{1960, 8996973}, {1961, 9169410}}};
    EXPECT_EQ(country.toString(), "Afghanistan (AFG): 8996973[1960], 9169410[1961]");
}

#ifdef PART1_SOLVED // remove to enable tests

// Part 1
TEST(WorldPopulation, Reading) {
    Program program;
    program.readCountryPopulationFromFile("08_population/world_population_1960-2018.csv", ';');
    program.worldPopulation.calcWorldPopulation();
    EXPECT_EQ(program.worldPopulation.countries.size(), 217);
    std::map<int, int64_t> expected{
        {1960, 3014710265}, {1961, 3055350225}, {1962, 3107917777}, {1963, 3172611908},
        // Add remaining values yourself
    };
    EXPECT_THAT(program.worldPopulation.totalYearPopulation, ::testing::ContainerEq(expected));
}

#endif // remove to enable tests

#ifdef PART2_SOLVED // remove to enable tests

TEST(WorldCountries, Reading) {
    Program program;
    program.readWorldCountriesFromFile(
        "08_population/countries.csv", "08_population/world_population_1960-2018.csv", ';'
    );
    program.worldCountries.calcWorldPopulation();
    EXPECT_EQ(program.worldCountries.countries.size(), 217);
    ASSERT_EQ(program.worldCountries.countries[0].name, "Afghanistan");
    EXPECT_EQ(program.worldCountries.countries[0].feature.code, "AFG");
    EXPECT_EQ(program.worldCountries.countries[0].feature.income, Income::LOW);
    EXPECT_EQ(program.worldCountries.countries[0].feature.region, Region::SOUTH_ASIA);
    EXPECT_EQ(program.worldCountries.countries[0].yearPopulation[1960], 8996973);
}

#endif // remove to enable tests

#ifdef PART3_SOLVED // remove to enable tests

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

WorldCountries sampleWorldCountries() {
    WorldCountries result;
    result.countries = {
        WorldCountry{
            "Afghanistan",
            {
                "AFG",
                Region::SOUTH_ASIA,
                Income::LOW,
            },
            {{1960, 9000000}, {1961, 9170000}, {2017, 36300000}},
        },
        WorldCountry{
            "Maldives",
            {
                "MDV",
                Region::SOUTH_ASIA,
                Income::UPPER_MIDDLE,
            },
            {{1960, 90000}, {1961, 92000}},
        },
        WorldCountry{
            "Serbia",
            {
                "SRB",
                Region::EUROPE_CENTRAL_ASIA,
                Income::UPPER_MIDDLE,
            },
            {{2017, 7020000}, {2018, 7000000}},
        },
    };
    result.calcWorldPopulation();
    return result;
}

TEST(WorldCountries, WriteWorldRegionPopulationToFile) {
    const auto filename = "region_population.csv";

    Program program;
    program.worldCountries = sampleWorldCountries();
    program.writeWorldRegionPopulationToFile(filename, ';');
    const auto contents = readFile(filename);
    EXPECT_EQ(
        contents,
        "Region;1960;1961;2017;2018\n"
        "South Asia;9090000;9262000;36300000;\n"
        "Europe & Central Asia;;;7020000;7000000\n"
    );
}

TEST(CountryService, FindByIncome) {
    const CountryService service(sampleWorldCountries());
    const auto result = service.findByIncome(Income::LOW);
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].name, "Afghanistan");
    EXPECT_EQ(result[0].yearPopulation.at(1960), 9000000);
}

TEST(CountryService, FindByPopulationGreaterThan) {
    const CountryService service(sampleWorldCountries());

    const auto result1 = service.findByPopulationGreaterThan(1960, 90000, Region::SOUTH_ASIA);
    ASSERT_EQ(result1.size(), 1);
    EXPECT_EQ(result1[0].name, "Afghanistan");

    const auto result2 = service.findByPopulationGreaterThan(1961, 90000, Income::UPPER_MIDDLE);
    ASSERT_EQ(result2.size(), 1);
    EXPECT_EQ(result2[0].name, "Maldives");
}

TEST(CountryService, FindRegions) {
    const CountryService service(sampleWorldCountries());
    EXPECT_THAT(
        service.findRegions(),
        ::testing::UnorderedElementsAre(Region::SOUTH_ASIA, Region::EUROPE_CENTRAL_ASIA)
    );
    EXPECT_THAT(
        service.findRegionsSet(),
        ::testing::ElementsAre(Region::SOUTH_ASIA, Region::EUROPE_CENTRAL_ASIA)
    );
}

#endif // remove to enable tests
