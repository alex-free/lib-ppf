// example by Alex Free
#include "lib-ppf.h"
#include "patches.h"
#include  <string.h>

FILE *bin;

int main (int argc, const char * argv[]) 
{
    printf("Lib PPF example %s by Alex Free\n", VERSION);

    if(argc != 3) {
        printf("Error: incorrect number of arguments\n\nUsage:\n\nexample -a <track 1 bin file of PlayStation 1 CD game>    Apply patch\nexample -u <track 1 bin file of PlayStation 1 CD game>    Undo patch\n");
        return 1;
    }

    bin = fopen(argv[2], "rb+");

    if(bin == NULL)
    {
        printf("Error: Can not open: %s\n", argv[2]);
        fclose(bin);
        return 1;
    }

    if(strncmp(argv[1], "-a", 2) == 0)
    {
        printf("Apply\n"); // patched: 1f8eded54a0e5e918cc811eb190fd9d0
        apply_ppf(kings_field_japan_english_translation_with_save_fix_PPF, kings_field_japan_english_translation_with_save_fix_PPF_len, bin);
    } else if(strncmp(argv[1], "-u", 2) == 0) {
        printf("Undo\n"); // original: c2b8b1652407c6c8107b0c93e20624a6
        undo_ppf(kings_field_japan_english_translation_with_save_fix_PPF, kings_field_japan_english_translation_with_save_fix_PPF_len, bin);
    }

    fclose(bin);
}