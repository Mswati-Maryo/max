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
	if (weatherData.empty()) {
		std::cerr << "No weather data available for analysis." << std::endl;
		return;
		}

	double totalTemp = 0.0;
	double highestTemp = std::numeric_limits<double>::lowest();
	double lowestTemp = std::numeric_limits<double>::max();
	std::string highestTempDate, lowestTempDate;

	for (const auto& data : weatherData) {
			totalTemp += data.temperature;
		if (data.temperature > highestTemp) {
			highestTemp = data.temperature;
				highestTempDate = data.date;
		}
		if (data.temperature < lowestTemp) {
				lowestTemp = data.temperature;
			lowestTempDate = data.date;
		}
	}
	
	double averageTemp = totalTemp / weatherData.size();

	std::cout << "Weather Data Analysis:" << std::endl;
		std::cout << "-----------------------" << std::endl;
	std::cout << "Average Temperature: " << averageTemp << "°C" << std::endl;
	std::cout << "Highest Temperature: " << highestTemp << "°C on " << highestTempDate << std::endl;
		std::cout << "Lowest Temperature: " << lowestTemp << "°C on " << lowestTempDate << std::endl;
}

int main() {
		std::string filename = "weather_data.csv";
	std::vector<WeatherData> weatherData;

	parseWeatherData(filename, weatherData);
	analyzeWeatherData(weatherData);

	return 0;
}
