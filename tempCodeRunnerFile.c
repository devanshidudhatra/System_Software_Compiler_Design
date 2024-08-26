#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to write code to a file
void write_code_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    const char *code =
        "#include <stdio.h>\n"
        "int add(int a, int b) {\n"
        "    return a + b;\n"
        "}\n"
        "int main() {\n"
        "    int result = add(5, 3);\n"
        "    printf(\"The result is: %d\\n\", result);\n"
        "    return 0;\n"
        "}\n";

    fputs(code, file);
    fclose(file);
}

// Function to check if a string is a keyword or a special character
int is_keyword_or_special_char(const char *str) {
    const char *keywords[] = {"int", "float", "char", "string", "bool", "printf", "scanf", "const", "return"};
    const char *special_chars[] = {"(", ")", "{", "}", "[", "]", ";", ","};
    size_t i;

    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }

    for (i = 0; i < sizeof(special_chars) / sizeof(special_chars[0]); i++) {
        if (strcmp(str, special_chars[i]) == 0) {
            return 1;
        }
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    FILE *ptr;
    char str[100];
    int tokens = 0;

    // Step 1: Write code to the file
    const char *code_filename = "code.txt";
    write_code_to_file(code_filename);

    // Step 2: Read the content of the file and count tokens
    ptr = fopen(code_filename, "r");
    if (ptr == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(ptr, "%s", str) != EOF) {
        printf("%s\n", str);
        if (is_keyword_or_special_char(str)) {
            tokens++;
        }
    }

    printf("Number of tokens: %d\n", tokens);
    fclose(ptr);

    // Step 3: Compile and run the code, capture output
    system("gcc code.txt -o output");
    system("./output > output.txt");

    // Step 4: Display and store the output
    ptr = fopen("output.txt", "r");
    if (ptr == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    printf("\nOutput of the code:\n");
    while (fgets(str, sizeof(str), ptr) != NULL) {
        printf("%s", str);
    }

    fclose(ptr);

    return 0;
}
