#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

// Structures and global variables for the grammar, first, follow sets, and parsing table
char production[MAX][MAX], first[MAX][MAX], follow[MAX][MAX];
int n, parsingTable[MAX][MAX];

// Function prototypes
int left_recursion_check();
void left_recursion_remove();
int left_factor_check();
void left_factor_remove();
void first_set();
void follow_set();
void parsing_table();
bool check_grammar();

int main() {
    int i, choice;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    
    printf("Enter the productions:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }
    
    if (left_recursion_check()) {
        printf("Left Recursion detected.\n");
        left_recursion_remove();
        printf("After removing left recursion:\n");
        for(i = 0; i < n; i++) {
            printf("%s\n", production[i]);
        }
    }

    if (left_factor_check()) {
        printf("Left Factoring detected.\n");
        left_factor_remove();
        printf("After removing left factoring:\n");
        for(i = 0; i < n; i++) {
            printf("%s\n", production[i]);
        }
    }

    first_set();
    follow_set();
    parsing_table();

    if (check_grammar()) {
        printf("The grammar is LL(1).\n");
    } else {
        printf("The grammar is not LL(1).\n");
    }
    
    return 0;
}

// Functions

// Check if left recursion exists in the grammar
int left_recursion_check() {
    int i;
    for(i = 0; i < n; i++) {
        if(production[i][0] == production[i][2]) {
            return 1;
        }
    }
    return 0;
}

// Remove left recursion from the grammar
void left_recursion_remove() {
    int i, j;
    for(i = 0; i < n; i++) {
        if(production[i][0] == production[i][2]) {
            char non_terminal = production[i][0];
            char new_production[MAX];
            
            new_production[0] = non_terminal;
            new_production[1] = '\'';
            new_production[2] = '=';
            for(j = 3; production[i][j] != '\0'; j++) {
                new_production[j] = production[i][j];
            }
            new_production[j++] = non_terminal;
            new_production[j++] = '\'';
            new_production[j] = '\0';
            
            strcpy(production[i], new_production);
            strcat(production[i+1], "|e");
        }
    }
}

// Check if left factoring exists in the grammar
int left_factor_check() {
    int i;
    for(i = 0; i < n; i++) {
        if(production[i][2] == production[i+1][2]) {
            return 1;
        }
    }
    return 0;
}

// Remove left factoring from the grammar
void left_factor_remove() {
    int i, j;
    for(i = 0; i < n; i++) {
        if(production[i][2] == production[i+1][2]) {
            char non_terminal = production[i][0];
            char new_production[MAX];
            
            new_production[0] = non_terminal;
            new_production[1] = '=';
            new_production[2] = production[i][2];
            new_production[3] = non_terminal;
            new_production[4] = '\'';
            new_production[5] = '\0';
            
            strcpy(production[i], new_production);
            production[i+1][0] = non_terminal;
            production[i+1][1] = '\'';
            production[i+1][2] = '=';
            for(j = 3; production[i+1][j] != '\0'; j++) {
                production[i+1][j] = production[i+1][j+1];
            }
            strcat(production[i+1], "|e");
        }
    }
}

// Construct the first set for the grammar
void first_set() {
    int i, j;
    printf("First sets:\n");
    for(i = 0; i < n; i++) {
        printf("First(%c) = { ", production[i][0]);
        for(j = 2; production[i][j] != '\0'; j++) {
            if(production[i][j] != '|') {
                printf("%c ", production[i][j]);
            }
        }
        printf("}\n");
    }
}

// Construct the follow set for the grammar
void follow_set() {
    int i, j;
    printf("Follow sets:\n");
    for(i = 0; i < n; i++) {
        printf("Follow(%c) = { ", production[i][0]);
        if(i == 0) {
            printf("$ ");
        }
        for(j = 2; production[i][j] != '\0'; j++) {
            if(production[i][j] == production[i+1][0]) {
                printf("%c ", production[i][j+1]);
            }
        }
        printf("}\n");
    }
}

// Construct the parsing table
void parsing_table() {
    // This is a placeholder implementation.
    // In practice, the parsing table is a 2D array based on terminals and non-terminals.
    printf("Parsing table construction is not implemented in this example.\n");
}

// Check if the grammar is LL(1)
bool check_grammar() {
    // This is a placeholder implementation.
    // An LL(1) grammar must not have any conflicts in the parsing table.
    printf("Checking if grammar is LL(1) is not implemented in this example.\n");
    return true; // Assuming it's LL(1) for simplicity
}
