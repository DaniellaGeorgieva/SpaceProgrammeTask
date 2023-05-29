#pragma once
#include "Day.h"

class Forecast {
private:
	Day** days;
	size_t capacity;
	size_t size;

public:
	Forecast();
	Forecast(const Forecast& other);
	Forecast& operator=(const Forecast& other);
	~Forecast();

	void addDay(Day&);
	Day* getDay(size_t index);
	//void readDay(const char* input, Day& day);
	//void readDays(std::ifstream& file, Day* daysCollection, size_t daysCount);

	size_t getSize() const;

	int getAvgTemp() const;
	int getMaxTemp() const;
	int getMinTemp() const;
	int getMedianTemp() const;
	//int getMostAppropriateLaunchTemp() const;

	int getAvgWind() const;
	int getMaxWind() const;
	int getMinWind() const;
	int getMedianWind() const;
	//int getMostAppropriateLaunchWind() const;

	unsigned int getAvgHum() const;
	unsigned int getMaxHum() const;
	unsigned int getMinHum() const;
	unsigned int getMedianHum() const;
	//unsigned int getMostAppropriateLaunchHum() const;

	unsigned int getAvgPrecip() const;
	unsigned int getMaxPrecip() const;
	unsigned int getMinPrecip() const;
	unsigned int getMedianPrecip() const;

	bool checkTemp(size_t index) const;
	bool checkWind(size_t index) const;
	bool checkHum(size_t index) const;
	bool checkPrecip(size_t index) const;
	bool checkLightning(size_t index) const;
	bool checkClouds(size_t index) const;

	size_t getMostAppropriateDayIndex() const;

	void setNumDay(size_t index, int info);
	void setTempToDay(size_t index, int info);
	void setWindToDay(size_t index, int info);
	void setHumToDay(size_t index, int info);
	void setPrecipToDay(size_t index, int info);
	void setLightToDay(size_t index, bool info);
	void setCloudsToDay(size_t index, std::string info);
	//unsigned int getMostAppropriateLaunchPrecip() const;

	//unsigned int getMostAppropriateLaunchLightning() const;

	//unsigned int getMostAppropriateLaunchClouds() const;

private:
	void resize();
	void copy(const Forecast&);
	void free();
};