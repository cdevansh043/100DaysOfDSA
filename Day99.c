#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

int compareCars(const void* a, const void* b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    if (n == 0) return 0;

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target, n;
    if (scanf("%d %d", &target, &n) != 2) return 0;

    int* position = (int*)malloc(n * sizeof(int));
    int* speed = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &position[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));

    free(position);
    free(speed);
    return 0;
}