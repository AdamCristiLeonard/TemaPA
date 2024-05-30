#include "syntax_validator.h"
#include <regex.h>
#include <stdio.h>

bool is_valid_syntax(const char *code) {
    regex_t regex;
    int reti;

    // Expresia regulată pentru sintaxă validă
    const char *pattern = "^[0-9]+([\\s]*[\\+\\-\\*/][\\s]*[0-9]+)*$";

    // Compilarea expresiei regulate
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }

    // Compararea codului cu expresia regulată
    reti = regexec(&regex, code, 0, NULL, 0);
    regfree(&regex);

    // Dacă reti este 0, codul este valid
    return !reti;
}
