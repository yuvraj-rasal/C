#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display_menu();
void display_total(float price_per_item);
void draw_line(char ch, int length);
void print_colored(const char *text, const char *color_code);
void clear_screen();
void print_blinking(const char *text);

int main() {
    clear_screen();

    // Display hotel name with color
    print_colored("\n\n", "\033[0m");
    print_colored("\t\t\t###########################################\n", "\033[1;34m");
    print_colored("\t\t\t#                                         #\n", "\033[1;34m");
    print_colored("\t\t\t#   WELCOME TO HOTEL ROYAL SATARKAR!!!!   #\n", "\033[38;5;208m");
    print_colored("\t\t\t#                                         #\n", "\033[1;34m");
    print_colored("\t\t\t###########################################\n\n", "\033[1;34m");

    display_menu();

    int number;
    printf("\nEnter your order number: ");
    scanf("%d", &number);

    switch (number) {
        case 1:
            display_total(180);
            break;
        case 2:
            display_total(250);
            break;
        case 3:
            display_total(170);
            break;
        case 4:
            display_total(190);
            break;
        case 5:
            display_total(70);
            break;
        case 6:
            display_total(140);
            break;
        case 7:
            display_total(50);
            break;
        default:
            print_colored("\nInvalid choice.\n", "\033[1;31m");
            break;
    }

    print_blinking("\n***** Please visit again! *****\n");
    return 0;
}

void display_menu() {
    draw_line('=', 50);
    print_colored(" MENU\n", "\033[1;35m");
    draw_line('=', 50);
    printf("1. Chicken Thali: 180\n");
    printf("2. Mutton Thali: 250\n");
    printf("3. Paneer Tikka Masala: 170\n");
    printf("4. Veg Handi: 190\n");
    printf("5. Misal Pav: 70\n");
    printf("6. Pithla Bhakri: 140\n");
    printf("7. Sabudana Khichdi: 50\n");
    draw_line('=', 50);
}

void display_total(float price_per_item) {
    float quantity, total;
    printf("\nEnter the quantity you want to order: ");
    scanf("%f", &quantity);
    total = quantity * price_per_item;
    print_colored("\nTotal: ", "\033[1;36m");
    printf("%.2f\n", total);
}

void draw_line(char ch, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

void print_colored(const char *text, const char *color_code) {
    printf("%s%s\033[0m", color_code, text);
}

void clear_screen() {
    printf("\033[H\033[J");
}

void print_blinking(const char *text) {
    printf("\033[5m%s\033[0m", text);
}
