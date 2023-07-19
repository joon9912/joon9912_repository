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

void process_command();

int main() {
    // coefficient  : integer
    // exponent     : positive integer
    process_command();
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
    if (pTerm->coef == 1) {
        if (pTerm->expo >= 2)
            printf("x^%d", pTerm->expo);
        else if (pTerm->expo == 1)
            printf("x");
        else
            printf("1");
    }
    else if (pTerm->coef == -1) {
        if (pTerm->expo >= 2)
            printf("-x^%d", pTerm->expo);
        else if (pTerm->expo == 1)
            printf("-x");
        else
            printf("-1");
    }
    else {
        if (pTerm->expo >= 2)
            printf("%dx^%d", pTerm->coef, pTerm->expo);
        else if (pTerm->expo == 1)
            printf("%dx", pTerm->coef);
        else
            printf("-%d", pTerm->coef);
    }

}

void print_poly(Polynomial *p) {
    printf("%c=", p->name);
    Term *t = p->first;
    if (p->size == 1) {
        print_term(t);
        printf("\n");
        return;
    }
    for (int i = 0; i < p->size - 1; ++i) {
        print_term(t);
        t = t->next;
        if (t->coef > 0)
            printf("+");
    }
    print_term(t);
    printf("\n");
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
    int i;
    for (i = 0; i < n; ++i) {
        if (polys[i]->name == name)
            break;
    }

    if (i == n) return;

    int j = 0, res = 0;
    while (j < strlen(x_str) && x_str[i] >= '0' && x_str[i] <= '9') {
        res = res * 10 + (int)(x_str[i] - '0');
        j++;
    }
    printf("%d\n", eval(polys[i], res));
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

int parse_and_add_term(char *expr, int begin, int end, Polynomial *p_poly) {
    int i = begin;
    int sign_coef = 1, coef = 0, expo = 1;

    if (expr[i] == '+')
        i++;
    else if (expr[i] == '-') {
        sign_coef = -1;
        i++;
    }

    while (i < end && expr[i] >= '0' && expr[i] <= '9') {
        coef = coef * 10 + (int)(expr[i] - '0');
        i++;
    }

    if (coef == 0) // ex) x^1, -x^3
        coef = sign_coef;
    else
        coef *= sign_coef;

    if (i >= end) { // constant
        add_term(coef, 0, p_poly);
        return 1;
    }

    if (expr[i] != 'x')
        return 0;
    i++;

    if (i >= end) { // ex) x^1 => x
        add_term(coef, 1, p_poly);
        return 1;
    }

    if (expr[i] != '^')
        return 0;
    i++;

    expo = 0;
    while (i < end && expr[i] >= '0' && expr[i] <= '9') {
        expo = expo * 10 + (int)(expr[i] - '0');
        i++;
    }

    add_term(coef, expo, p_poly);

    return 1;
}

void destroy_polynomial(Polynomial *ptr_poly) {
    if (ptr_poly == NULL)
        return;
    Term *t = ptr_poly->first, *tmp;
    while (t != NULL) {
        tmp = t;
        t = t->next;
        free(tmp);
    }
    free(ptr_poly);
}

void insert_polynomial(Polynomial *ptr_poly) {
    for (int i = 0; i < n; ++i) {
        // if have same poly
        if (polys[i]->name == ptr_poly->name) {
            destroy_polynomial(polys[i]);
            polys[i] = ptr_poly;
            return;
        }
    }
    // if not have same name poly
    polys[n++] = ptr_poly;
}

Polynomial *create_by_parse_polynomial(char name, char *body) {
    Polynomial *ptr_poly = create_polynomial_instance(name);

    int i = 0, begin_term = 0;
    while (i < strlen(body)) {
        if (body[i] == '+' || body[i] == '-')
            i++;

        while (i < strlen(body) && body[i] != '+' && body[i] != '-')
            i++;

        // [begin_term, i) == term
        int result = parse_and_add_term(body, begin_term, i , ptr_poly);

        if (result == 0) {
            destroy_polynomial(ptr_poly);
            return NULL;
        }
        begin_term = i;
    }
    return ptr_poly;
}

Polynomial *create_by_add_two_polynomials(char name, char f, char g) {
    Polynomial *ptr_poly = create_polynomial_instance(name);

    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        if (polys[i]->name == f || polys[i]->name == g) {
            if (x == -1) x = i;
            else if (y == -1) y = i;
        }
    }

    if (x == -1 || y == -1) return NULL;

    Term *t = polys[x]->first, *tmp;
    while (t != NULL) {
        tmp = t;
        t = t->next;
        add_term(tmp->coef, tmp->expo, ptr_poly);
    }
    // print_poly(ptr_poly);

    t = polys[y]->first;
    while (t != NULL) {
        tmp = t;
        t = t->next;
        add_term(tmp->coef, tmp->expo, ptr_poly);
    }
    // print_poly(ptr_poly);

    return ptr_poly;
}

void show_all() {
    for (int i = 0; i < n; ++i) {
        handle_print(polys[i]->name);
    }
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
        Polynomial *pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);

        if (pol == NULL) {
            printf("Invalid expression format.");
            return;
        }
        insert_polynomial(pol);

        // print_poly(pol);
    }
    else {
        Polynomial *pol = create_by_parse_polynomial(f_name[0], exp_body);
        if (pol == NULL) {
            printf("Invalid expression format");
            return;
        }
        insert_polynomial(pol);
    }

    // show_all();
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
        else if (strcmp(command, "show") == 0)
            show_all();
        else
            handle_definition(copied); // read poly
    }
}