#ifndef LIB_PPF
#define LIB_PPF
#include <stdio.h>
void apply_ppf(const unsigned char ppf[], unsigned int ppf_len, FILE *bin);
void undo_ppf(const unsigned char ppf[], unsigned int ppf_len, FILE *bin);

#endif /* LIB_PPF */