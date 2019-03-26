#include <iostream>
#include <stdio.h>
#include <math.h>

// Chrono is only imported for the speed test
#include <chrono>

// This implementation uses structs instead to return the array
struct floats
{
	float floatarray[4];
};

struct floats to_quaternion(float roll = 0.0, float pitch = 0.0, float yaw = 0.0) 
{

	struct floats quat;
	const double PI  = 3.141592653589793238463;

	float t0 = cos(((yaw*0.5)*PI / 180));
	float t1 = sin(((yaw*0.5)*PI / 180));
	float t2 = cos(((roll*0.5)*PI / 180));
	float t3 = sin(((roll*0.5)*PI / 180));
	float t4 = cos(((pitch*0.5)*PI / 180));
	float t5 = sin(((pitch*0.5)*PI / 180));

	quat.floatarray[0] = t0 * t2 * t4 + t1 * t3 * t5;
	quat.floatarray[1] = t0 * t3 * t4 - t1 * t2 * t5;
    quat.floatarray[2] = t0 * t2 * t5 + t1 * t3 * t4;
    quat.floatarray[3] = t1 * t2 * t4 - t0 * t3 * t5;

	return quat;

}

/* Single quaternion calculation: */
// int main() {
// 	struct floats quat = to_quaternion();
// 	printf("Quatenions are: %4.2f, %4.2f, %4.2f, %4.2f ", 
// 		quat.floatarray[0], quat.floatarray[1], quat.floatarray[2], quat.floatarray[3]);

// 	return 0;
// }


// speed test
int main() { 
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	for (int i = 0; i < 360; i++) {
		struct floats quat = to_quaternion(i,i,i);
		printf("Quartenions are: %4.2f, %4.2f, %4.2f, %4.2f \n", 
				quat.floatarray[0], quat.floatarray[1], quat.floatarray[2], quat.floatarray[3]);
	}
	end = std::chrono::system_clock::now(); 

	std::chrono::duration<double> elapsed_seconds = end - start; 
    std::time_t end_time = std::chrono::system_clock::to_time_t(end); 

	std::cout << "C++ took: " << elapsed_seconds.count() << " seconds." << std::endl;

	return 0;
}
