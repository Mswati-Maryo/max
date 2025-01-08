#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

struct WeatherData {
	std::string date;
	double temperature;
};

void parseWeatherData(const std::string& filename, std::vector<WeatherData>& weatherData) {
	std::ifstream file(filename);
	if (!file.is_open()) {
