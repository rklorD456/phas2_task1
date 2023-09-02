#include <stdio.h>

float calWeightAverage(float sensor1[], float sensor2[], int size, float accuracy1, float accuracy2)
{
    float weightSum = 0.0;
    float totalAccuracy = accuracy1 + accuracy2;

    for (int i = 0; i < size; i++) {
        float weightValue = (accuracy1 * sensor1[i] + accuracy2 * sensor2[i]) / totalAccuracy;
        weightSum += weightValue;
    }

    return weightSum;
}

int main() {
    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[10] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    
    // Sensor accuracies
    float accuracy_mpu6050 = 0.79;
    float accuracy_bno55 = 0.92;

    int size = sizeof(mpu6050) / sizeof(mpu6050[0]);
    // Calculate weighted average
    float weightedAvg = calWeightAverage(mpu6050, bno55, size, accuracy_mpu6050, accuracy_bno55);

    printf("Weighted Average: %.2f\n", weightedAvg);
    return 0;
}