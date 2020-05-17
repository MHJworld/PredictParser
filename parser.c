#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*

E → E + T | E – T |  T
T  → T * F | T / F | F
F → ( E ) |  id  | num

E -> T R1
R1 -> + T R1 | - T R1 | ε
T -> F R2
R2 -> * F R2 | / F R2 | ε
F -> (E) | id | num

*/

char input[30]; // 사칙연산을 input하기 위해 선언
char* Newinput[10] = { NULL, }; // 2차원 배열을 위한 포인터 선언
int i; // 문자열을 읽기위한 변수 선언
void split(); // 문자열을 쪼개기 위한 함수
void E();
void T();
void R1();
void R2();
void F();
void ε() {}

void main()
{
    i = 0;
    printf("Input : ");
    gets(input);
    split();
    E();
}

void split() {
    int a = 0;

    char* ptr = strtok(input, " "); // 공백을 기준으로 문자열을 자름
    while (ptr != NULL)
    {
        Newinput[a] = ptr; // 2차원 배열에 각 문자열 삽입
        a++;
        ptr = strtok(NULL, " ");
    }
}

void E() {
    T();
    R1();
}

void R1() {
    if (*Newinput[i] == '+') {
        i++;
        T();
        printf("+ ");
        R1();
    }

    else if (*Newinput[i] == '-') {
        i++;
        T();
        printf("- ");
        R1();
    }
    else
        ε();
}

void T() {
    F();
    R2();
}

void R2() {
    if (*Newinput[i] == '*') {
        i++;
        F();
        printf("* ");
        R2();
    }
    else if (*Newinput[i] == '/') {
        i++;
        F();
        printf("/ ");
        R2();
    }
    else
        ε();
}

void F() {
    if (isalnum(*Newinput[i])) {
        printf("%s ", Newinput[i]);
        i++;
    }

    else if (*Newinput[i] == '(') {
        i++;
        printf("( ");
        E();
        if (*Newinput[i] == ')') {
            i++;
            printf(") ");
        }
    }
}
