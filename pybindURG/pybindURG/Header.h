#pragma once

#include "urg_sensor.h"
#include "urg_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>

class urgCommunication {
private:
	urg_t urg;
	int ret;
	long *length_data;
	int length_data_size;
public:	
	urgCommunication(std::string com){
		const char* connect_device = com.c_str();
		const long connect_baudrate = 115200;

		ret = urg_open(&urg, URG_SERIAL, connect_device, connect_baudrate);

		length_data = (long *)malloc(sizeof(long)* urg_max_data_size(&urg));
	}

	std::vector<double> run() {
		std::vector<double> data;

		ret = urg_start_measurement(&urg, URG_DISTANCE, 1, 0);
		length_data_size = urg_get_distance(&urg, length_data, NULL);
		for (int i = 0; i < length_data_size; ++i) {
			double radian;
			long length;

			radian = urg_index2rad(&urg, i);
			length = length_data[i];
			data.push_back(radian);
			data.push_back((double)length);
		}
		return data;
	}

};
