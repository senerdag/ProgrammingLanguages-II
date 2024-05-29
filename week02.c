#include <stdio.h>
#include <stdlib.h>

#define PI 3.14




float square(const int r){
    float area;

    area=PI*r*r ;
    return area;
}

int main(){

    int r;
    float area;

    printf("dairenin yaricapi nedir:");
    scanf("%d",&r);

    area=square(r);

    printf("dairenin alani:%f",area);

    return 0 ;
}
