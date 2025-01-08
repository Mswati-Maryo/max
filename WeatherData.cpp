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
	std::cerr << "Error: Could not open the file: " << filename << std::endl;
		return;
	}
	
	std::string line;
	std::getline(file, line); // Skip the header line
	
	while (std::getline(file, line)) {
		std::istringstream stream(line);
		std::string date;
		std::string tempStr;
		if (std::getline(stream, date, ',') && std::getline(stream, tempStr)) {
			WeatherData data;
			data.date = date;
			data.temperature = std::stod(tempStr);
			weatherData.push_back(data);
				}
	}

	file.close();
	}

void analyzeWeatherData(const std::vector<WeatherData>& weatherData) {
