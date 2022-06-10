#include <stdio.h>

int square(int num){
    int sum = num * num;
    return sum;
}

int main(){
    printf("%d",square(3));
    while( getchar() == '\0'){

    }
    return 0;
}