#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"
#include "../node.h"
#include "../parser.h"
#include "symtab.h"
struct symtab_stack_s symtab_stack;
int    symtab_level;
void init_symtab(void)
{
    symtab_stack.symtab_count = 1;
    symtab_level = 0;
    struct symtab_s *global_symtab = malloc(sizeof(struct symtab_s));
    if(!global_symtab)
    {
        fprintf(stderr, "fatal error: no memory for global symbol table\n");
        exit(EXIT_FAILURE);
    }
    memset(global_symtab, 0, sizeof(struct symtab_s));
    symtab_stack.global_symtab  = global_symtab;
    symtab_stack.local_symtab   = global_symtab;
    symtab_stack.symtab_list[0] = global_symtab;
    global_symtab->level        = 0;
}
