#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POLYS 100
#define BUFFER_LENGTH 100

struct term {
    int coef;
    int expo;
    struct term *next;
};

typedef struct term Term;

typedef struct polynomial {
    char name;
    Term *first;
    int size = 0;
} Polynomial;

Polynomial *polys[MAX_POLYS];
int n = 0; // # of polys

int main() {
    // coefficient  : integer
    // exponent     : positive integer


    return 0;
}

int read_line(FILE *fp, char str[], int limit) {
    int ch, i = 0;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}

Term *create_term_instance() {
    Term *t = (Term *)malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;
    return t;
}

Polynomial *create_polynomial_instance(char name) {
    Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
    ptr_poly->name = name;
    ptr_poly->size = 0;
    ptr_poly->first = NULL;
    return ptr_poly;
}

void add_term(int c, int e, Polynomial *poly) {
    // coef is 0
    if (c == 0)
        return;
    Term *p = poly->first;
    Term *q = NULL;
    while (p != NULL && p->expo > e) {
        q = p;
        p = p->next;
    }
    if (p != NULL && p->expo == e) {
        p->coef += c;
        if (p->coef == 0) {
            if (q == NULL) // first term becomes zero
                poly->first = p->next;
            else
                q->next = p->next;
            poly->size--;
            free(p); // delete
        }
        return;
    }

    // have no same coef term
    Term *term = create_term_instance();
    term->coef = c;
    term->expo = e;

    if (q == NULL) {
        // first term
        term->next = poly->first;
        poly->first = term;
    }
    else {
        term->next = p;
        q->next= term;
    }
    poly->size++;
}

int eval(Term *term, int x) {
    int result = term->coef;
    for (int i = 0; i < term->expo; ++i)
        result *= x;
    return result;
}

int eval(Polynomial *poly, int x) {
    // expo >= 0
    int result = 0;
    Term *t = poly->first;
    while (t != NULL) {
        result += eval(t, x);
        t = t->next;
    }
    return result;
}

void print_term(Term *pTerm) {
    if (pTerm->expo >= 2)
        printf("%dx^%d", pTerm->coef, pTerm->expo);
    else if (pTerm->expo == 1)
        printf("%dx", pTerm->coef);
    else
        printf("%d", pTerm->coef);
}

void print_poly(Polynomial *p) {
    printf("%c-", p->name);
    Term *t = p->first;
    while (t != NULL) {
        print_term(t);
        printf("+");
        t = t->next;
    }
}

void handle_print(char name) {
    int i;
    for (i = 0; i < n; ++i) {
        if (polys[i]->name == name)
            break;
    }

    if (i == n) return;

    print_poly(polys[i]);
}

void handle_calc(char name, char *x_str) {

}

void erase_blanks(char *expression) {
    int i, k = 0;
    char *str = (char*)malloc(sizeof(expression));

    for (i = 0; i < strlen(expression); ++i)
        if (expression[i] != ' ')
            str[k++] = expression[i];

    str[k] = '\0';
    strcpy(expression, str);
}

Polynomial *create_by_parse_polynomial(char name, char *body) {
    Polynomial *ptr_poly = create_polynomial_instance(name);

    int i = 0, begin_term = 0;
    while (i < strlen(body)) {
        if (body[i] == '+' || body[i] == '-')
            i++;

        while (i < strlen(body) && body[i] != '+'
            && body[i] != '-')
        { i++; }

        int result = parse_and_add_term(body, begin_term, i , ptr_poly);

        if (result == 0) {
            destroy_polynomial(ptr_poly);
            return NULL;
        }
        begin_term = i;
    }
    return ptr_poly;
}

void handle_definition(char *expression) {
    erase_blanks(expression);

    char *f_name = strtok(expression, "=");
    if (f_name == NULL || strlen(f_name) != 1) {
        printf("Unsupported command.");
        return;
    }

    char *exp_body = strtok(NULL, "=");
    if (exp_body == NULL || strlen(exp_body) <= 0) {
        printf("Invalid expression format.--");
        return;
    }

    if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
       char *former = strtok(exp_body, "+");
        if (former == NULL || strlen(former) != 1) {
            printf("Invalid expression format.");
            return;
        }
        char *later = strtok(NULL, "+");
        if (later == NULL || strlen(later) != 1) {
            printf("Invalid expression format.");
            return;
        }
        Polynomial *pol = create_by_add_two_polynomias(f_name[0], former[0], later[0]);

        if (pol == NULL) {
            printf("Invalid expression format.");
            return;
        }
        insert_polynomial(pol);
    }
    else {
        Polynomial *pol = create_by_parse_polynomial(f_name[0], exp_body);
        if (pol == NULL) {
            printf("Invalid expression format");
            return;
        }
        insert_polynomial(pol);
    }
}

void process_command() {
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *arg1, *arg2;

    while (1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
            continue;
        strcpy(copied, command_line);
        command = strtok(command_line, " ");
        if (strcmp(command, "print") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_print(arg1[0]);
        }
        else if (strcmp(command, "calc") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            arg2 = strtok(NULL, " ");
            if (arg2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_calc(arg1[0], arg2);
        }
        else if (strcmp(command, "exit") == 0)
            break;
        else
            handle_definition(copied); // read poly
    }
}