#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


struct Product
{
    struct User* seller;
    char* name;
    int price;
    int count;

};
struct User
{
    char* name;
    char* password;
    char* role;
    int deposit;
    int products_num;
    struct Product* products;
};
int main()
{
    struct User* users;
    struct Product* products;
    users = malloc(1 * sizeof(struct User));
    products = malloc(1 * sizeof(struct Product));
    char** input;
    int num_of_users = 0;
    int num_of_products = 0;
    int user_num;
    int command = 0;
    int loged_in = 0;
    char* str;
    printf("        ******////// welcome to ut-kala \\\\\\\\\\\\******\n");
    while (1 == 1)
    {
        while (loged_in == 0)
        {
            input = split(getinput());
            command = command_check(input);
            if (command == 1)
            {
                if (check_signup(input, users, num_of_users) == 1)
                {
                    num_of_users += 1;
                    users = realloc(users, num_of_users * sizeof(struct  User));
                    {
                        users[num_of_users - 1] = *signup(input);
                    };
                    command = 0;
                }
            }
            if (command == 2)
            {
                loged_in = login(input, users, num_of_users, &user_num);
                command = 0;
            }
            if (command == 3)
            {
                show_goods(products, num_of_products);
                command = 0;
            }
            


        }
        while (loged_in == 1)
        {//loged in as seller
            input = split(getinput());
            command = seller_command_check(input);
            if (command == 1)
            {
                logout(&loged_in);
                command = 0;
            }
            if (command == 2)
            {
                view_user(users[user_num]);
                command = 0;
            }
            if (command == 3)
            {

                if (check_add_goods(input, products, num_of_products, &users[user_num]) == 1)
                {
                    num_of_products += 1;
                    products = realloc(products, num_of_products * sizeof(struct Product));
                    products[num_of_products - 1] = *add_goods(input, &users[user_num]);
                    command = 0;
                }
            }
            if (command == 4)
            {
                show_goods(products, num_of_products);
                command = 0;
            }



        }
        while (loged_in == 2)
        {//loged in as buyer
            input = split(getinput());
            command = buyer_command_check(input);
            if (command == 1)
            {
                logout(&loged_in);
                command = 0;
            }
            if (command == 2)
            {
                view_user(users[user_num]);
                command = 0;
            }
            if (command == 3)
            {
                deposit(&users[user_num], input);
            }
            if (command == 4)
            {
                show_goods(products, num_of_products);
                command = 0;
            }
            if (command == 5)
            {
                if (check_buy(input, products, num_of_products, users, num_of_users, users[user_num]))
                {
                    buy(input, products, num_of_products, &users[user_num], users, num_of_users);
                    printf("item successfully purchased!\n");
                    command = 0;

                }
            }


        }

    }








    return 0;
}
