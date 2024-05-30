#include <stdio.h>
#include <stdlib.h>
#include "syntax_corrector.h"

int main() {
    // Fragmentul de cod care trebuie corectat
    const char *code = "3 + + 2";
    // Lista de fragmente de cod valide conform regulilor de sintaxă
    const char *rules[] = { "3 + 2", "3 + 3", "3 * 2" };
    int rules_count = sizeof(rules) / sizeof(rules[0]);

    // Determinarea numărului minim de operații și a codului corectat
    char *best_target = NULL;
    int min_edits = minimum_syntax_edits(code, rules, rules_count, &best_target);

    printf("Numărul minim de operații: %d\n", min_edits);
    if (best_target) {
        printf("Codul corectat: %s\n", best_target);
        free(best_target);
    }

    return 0;
}
