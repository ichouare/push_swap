# include "push_swap.h"

int main() {

    char *str;
    while(1) {
        str = get_next_line(0);
        if (!str)
            break;
        puts(str);
    }
}