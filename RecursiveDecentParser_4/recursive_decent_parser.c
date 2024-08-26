// E –> T E’ 
// E’ –> + T E’ | -TE' | e 
// T –> FT’ 
// T’ –> * F T’ | / F T' | e 
// F -> P F'
// F' -> ^ F | e
// P –> ( E ) | id

#include <stdio.h>
#include <string.h>

int E(), Edash(), T(), Tdash(), F() , Fdash() , P();

const char *index;
char string[64];

int main() {
	puts("Enter the string");
	scanf("%s", string); 
	index = string;
	puts("");
	puts("Input		 Action");
	puts("__________________________________");

	if (E() && *index == '\0') { 
		puts("String is successfully parsed");
		return 0;
	} 
	else {
		puts("Error in parsing String");
		return 1;
	}
}

//E -> T E'
int E() {
	printf("%-16s E -> T E'\n", index);
	if (T()) { 
		if (Edash()) 
			return 1;
		else
			return 0;
	} 
	else
		return 0;
}

//E' -> + T E'| - T E' | $
int Edash() {
	if (*index == '+') {
		printf("%-16s E' -> + T E'\n", index);
		index++;
		if (T()) { 
			if (Edash()) 
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	}
    else if (*index == '-') {
		printf("%-16s E' -> - T E'\n", index);
		index++;
		if (T()) { 
			if (Edash()) 
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	}
	else {
		printf("%-16s E' -> $\n", index);
		return 1;
	}
}

// T -> F T'
int T() {
	printf("%-16s T -> F T'\n", index);
	if (F()) { 
		if (Tdash()) 
			return 1;
		else
			return 0;
	} 
	else
		return 0;
}

// T' -> * F T' | $
int Tdash() {
	if (*index == '*') {
		printf("%-16s T' -> * F T'\n", index);
		index++;
		if (F()) { 
			if (Tdash()) 
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	} 
    else if (*index == '/') {
		printf("%-16s T' -> / F T'\n", index);
		index++;
		if (F()) { 
			if (Tdash()) 
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	} 
	else {
		printf("%-16s T' -> $\n", index);
		return 1;
	}
}

// F -> P F'
int F(){
    printf("%-16s F -> P F'\n", index);
    if(P()){
        if(Fdash()){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

// F' -> ^ F | e 
int Fdash() {
	if (*index == '^') {
		printf("%-16s F' -> ^ F | e \n", index);
		index++;
		if (F()) { 
			return 1;
		} 
		else
			return 0;
	} 
	else
		return 1;
}


// P -> ( E ) | i
int P() {
	if (*index == '(') {
		printf("%-16s P -> ( E )\n", index);
		index++;
		if (E()) { 
			if (*index == ')') {
				index++;
				return 1;
			} 
			else
				return 0;
		} 
		else
			return 0;
	} 
	else if (strncmp(index, "id", 2) == 0) {
        printf("%-16s P -> id\n", index);
        index += 2; 
        return 1;
    }  
	else
		return 0;
}
