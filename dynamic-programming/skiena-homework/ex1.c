#include <stdio.h>
#include "../edit_distance.h"

int main(){
    char* s[] = {"watch the movie raising arizona?", "this is what happens when I type slow", "leonard skiena"};
    char* t[] = {"watch da mets raze arizona?", "htishisth whaty havpens when ui type fasht", "lynard skynard"};
    printf("%d\n", EditDistance(s[0], t[0]));
    printf("%d\n", EditDistance(s[1], t[1]));
    printf("%d\n", EditDistance(s[2], t[2]));
    return 0;
}