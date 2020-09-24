#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 50

int absolute_value(int x){
    if(x < 0) return -x;
    else return x;
}

int manhattan_distance(int x1, int y1, int x2, int y2){
    return absolute_value(x1-x2) + absolute_value(y1-y2);
}

void find_best_slot(int area[CAPACITY][CAPACITY], int size){
    int min_to_nearest_car, dist, max = 0, x = 3, y = 3, i, j, k, l;
    for (i = 0; i < size; i++){ // it looks for a empty slot
        for (j = 0; j < size; j++){
            if (area[i][j] == 0){ // if the emty slot is found
                min_to_nearest_car = 100;
                for (k = 0; k < size; k++){ // it looks for a car
                    for (l = 0; l < size; l++){
                        if(area[k][l] == 1){ // if car is found
                            dist = manhattan_distance(i, j, k, l); // it is calculating manhattan distance btw empty slot and car
                            if(dist < min_to_nearest_car) min_to_nearest_car = dist; // it finds nearest cars' distance
                        }
                    }
                }
                if(min_to_nearest_car > max){ // it finds  max distance to the nearest car
                    max = min_to_nearest_car;
                    x = i;
                    y = j;

                }
            }
        }
    }
    printf("Best Slot Found In: %d %d\n", x+1 , y+1);
}

int main(){
    int size, cars, x, y, i, j;
    printf("Size: ");
    scanf("%d", &size);
    while(size > 50 || size <1){
        printf("Size must be between 50 and 1\n");
        printf("Size: ");
        scanf("%d", &size);
    }
    printf("Cars: ");
    scanf("%d", &cars);

    if(cars >= size*size){
        printf("Best Slot Found In: 0 0\n");
        return EXIT_SUCCESS;
    }

    int area[CAPACITY][CAPACITY];

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            area[i][j] = 0;
        }
    }

    for (i = 0; i < cars; i++){
        printf("Locations: ");
        scanf("%d %d", &x, &y);
        area[x-1][y-1] = 1;
    }

    find_best_slot(area,size);
    return EXIT_SUCCESS;
}
