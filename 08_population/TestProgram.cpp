#include "Program.h"
#include "Country.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

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
