/*
** EPITECH PROJECT, 2018
** tree
** File description:
** print a tree
*/

int calculer_taille_max(int size)
{
    int height = 4;
    int width = 1;
    int floor = 1;
    while (floor <= size) {
	for (int current = 0 ; current < height ; current++ ) {
            width += 2;
	}
        if ((floor % 2) == 1) {
            width = width - floor - 1;
	} else {
            width = width - floor;
	}
        width -= 2;
	height++;
	floor++;
    }
    return (width - 2);
}

void print_char(int nb, char c)
{
    int i;
    for (i = 0 ; i < nb ; i++) {
        my_putchar(c);
    }
    my_putchar('\n');
}

void print_wood(int size)
{
    int y = 1;
    
    if ((size % 2) == 0) {
        size += 1;
    }
    while (y <= size) {
        print_char(size, '|');
        y++;
    }
}    

void tree(int size)
{
    int height = 4;
    int width = 1;
    int floor = 1;
    if (size <= 0) {
        write(1, "erreure", 7);
    }
    while (floor <= size) {
        for (int current = 0 ; current < height ; current++ ) {
            print_char(width, '*');
            width += 2;
        }
        if ((floor % 2) == 1) {
            width = width - floor - 1;
        } else {
            width = width - floor;
        }
        width -= 2;
        height++;
        floor++;
    }
    print_wood(size);
}

int main(){
    tree(100);
}
