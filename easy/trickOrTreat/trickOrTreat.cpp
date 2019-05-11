// https://www.codeeval.com/open_challenges/220/

#include <cstdio>

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    
    int vamp, zomb, wit, house, each;
    
    while (fscanf(file, "Vampires: %d, Zombies: %d, Witches: %d, Houses: %d ", &vamp, &zomb, &wit, &house) == 4) {
        each = ((vamp * 3 * house) + (zomb * 4 * house) + (wit * 5 * house)) / (vamp + zomb + wit);
        printf("%d\n", each);
    }
    
    fclose(file);
    
    return 0;
}