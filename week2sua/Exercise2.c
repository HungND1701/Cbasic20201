#include<stdlib.h>
#include<stdio.h>
typedef struct point        
{
    double x;
    double y;
}point_t;
typedef struct circle
{
    point_t center;
    double radius;
}circle_t ;
int is_in_circle(point_t *p,circle_t *c){
    double x_dist,y_dist;
    x_dist= p->x - c->center.x;
    y_dist= p->y - c->center.y;
    return(x_dist * x_dist + y_dist * y_dist <= c->radius * c->radius);
}

int main(){
    point_t p;
    circle_t c;
    printf("Enter point cooordinates : ");
    scanf("%lf %lf",&p.x,&p.y);
    printf("\nEnter circle center coordinates ");
    scanf("%lf%lf", &c.center.x, &c.center.y);
    printf("\nEnter circle radius ");
    scanf("%lf", &c.radius);
    if(is_in_circle(&p,&c)) printf("\npoint is in circle !!\n");
    else printf("\npoint is out of circle \n");
    return 0;
}