#include "syntax_corrector.h"
#include "syntax_validator.h"
#include "levenshtein_distance.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int minimum_syntax_edits(const char *code, const char **rules, int rules_count, char **best_target) {
    int min_edits = INT_MAX;

    for (int i = 0; i < rules_count; i++) {
        if (is_valid_syntax(rules[i])) {
            int edits = levenshtein_distance(code, rules[i]);
            if (edits < min_edits) {
                min_edits = edits;
                *best_target = (char *)malloc((strlen(rules[i]) + 1) * sizeof(char));
                strcpy(*best_target, rules[i]);
            }
        }
    }

    return min_edits;
}
