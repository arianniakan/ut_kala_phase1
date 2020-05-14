#include<string.h>

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
    int password;
    char* role;
    int deposit;
    int products_num;
    struct Product* products;
};


char* getinput()
{
    char* str;
    int i = 0;
    char key = 0;
    str = malloc(sizeof(char));
    while (key != '\n')
    {
        key = getchar();
        if (key == '\n')
        {
            str[i] = 0;
            i++;
            str = realloc(str, (i + 1) * sizeof(char));
        }
        str[i] = key;
        i++;
        str = realloc(str, (i + 1) * sizeof(char));

    }




    return str;
}

char** split(char* input)
{
    char** list;
    list = malloc(sizeof(char*));
    list[0] = malloc(1 * sizeof(char));
    int i = 0;
    int j = 0;
    int k = 0;
    while (1 == 1)
    {

        while (1 == 1)
        {
            if (input[k] == ' ')
            {
                k += 1;
            }
            list[i][j] = input[k];
            k += 1;
            if (input[k] == 0)
            {
                break;
            }


            if (input[k] == ' ')
            {
                j += 1;
                list[i] = realloc(list[i], (j + 1) * sizeof(char));

                break;
            }
            j += 1;
            list[i] = realloc(list[i], (j + 1) * sizeof(char));
        }
        if (input[k] == 0)
        {
            j += 1;
            list[i][j] = 0;
            i += 1;
            list = realloc(list, (i + 1) * sizeof(char*));
            list[i] = malloc(sizeof(char));
            list[i][0] = 0;


            break;
        }
        list[i][j] = 0;
        i += 1;
        j = 0;
        list = realloc(list, (i + 1) * sizeof(char*));
        list[i] = malloc(sizeof(char));
    }

    return list;
}




int command_check(char** input)
{
    if (strcmp(input[0], "signup") == 0 || strcmp(input[0], "SIGNUP") == 0 || strcmp(input[0], "Signup") == 0)
    {
        return 1;
    }
    if (strcmp(input[0], "login") == 0 || strcmp(input[0], "LOGIN") == 0 || strcmp(input[0], "Login") == 0)
    {
        return 2;
    }
    if (strcmp(input[0], "show_goods") == 0 || strcmp(input[0], "SHOW_GOODS") == 0 || strcmp(input[0], "Show_Goods") == 0 || strcmp(input[0], "Show_goods") == 0)
    {
        return 3;
    }
    else
    {
        printf("invalid command try again!\n");
    }
}

int check_signup(char** input, struct User* users, int num_of_users)
{
    for (int i = 0;i < 4;i++)
    {
        if (strcmp(input[i], "") == 0)
        {
            printf("invalid input for sign up\n");
            return 0;
        }
    }

    for (int i = 0;i < num_of_users;i++)
    {
        if (strcmp(input[1], users[i].name) == 0 && strcmp(input[3], users[i].role) == 0)
        {

            printf("that user is already taken!\n");
            return 0;
        }
    }

    if (strcmp(input[3], "Seller") != 0 && strcmp(input[3], "SELLER") != 0 && strcmp(input[3], "seller") != 0 && strcmp(input[3], "buyer") != 0 && strcmp(input[3], "Buyer") != 0 && strcmp(input[3], "BUYER") != 0)
    {
        printf("Enter a valide Role!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

struct User* signup(char** input)
{

    struct User* new_user;
    new_user = malloc(1 * sizeof(struct User));
    new_user->name = input[1];
    new_user->password = input[2];
    if (strcmp(input[3], "seller") == 0 || strcmp(input[3], "Seller") == 0 || strcmp(input[3], "SELLER") == 0)
    {
        new_user->role = "seller";
    }
    else
    {
        new_user->role = "buyer";
    }
    new_user->products = malloc(sizeof(struct Product));
    new_user->products = 0;
    new_user->deposit = 0;
    new_user->products_num = 0;
    printf("you have successfully been signed in as %s\n", new_user->name);
    return new_user;



}

int login(char** input, struct User* users, int num_of_users, int* user_num)
{
    for (int i = 0;i < 4;i++)
    {
        if (strcmp(input[i], "") == 0)
        {
            printf("invalid input for login\n");
            return 0;
        }
    }
    for (int i = 0;i < num_of_users;i++)
    {
        if (strcmp(users[i].password, input[2]) == 0 && strcmp(users[i].role, input[3]) == 0 && strcmp(users[i].name, input[1]) == 0)
        {
            if (strcmp(input[3], "seller") == 0)
            {
                printf("Welcome %s\nYou have been loged in as a %s\n", input[1], input[3]);
                *user_num = i;
                return 1;
            }
            else if (strcmp(input[3], "buyer") == 0)
            {
                printf("Welcome %s\nYou have been loged in as a %s\n", input[1], input[3]);
                *user_num = i;
                return 2;
            }
        }
        else if (strcmp(users[i].name, input[1]) == 0)
        {
            if (strcmp(users[i].password, input[2]) != 0)
            {
                printf("invalid password\n");
                return 0;
            }

        }

    }
    printf("This user does not exist!\n");
    return 0;



}


int seller_command_check(char** input)
{
    if (strcmp(input[0], "logout") == 0 || strcmp(input[0], "LOGOUT") == 0 || strcmp(input[0], "Logout") == 0)
    {
        return 1;
    }
    if (strcmp(input[0], "view") == 0 || strcmp(input[0], "VIEW") == 0 || strcmp(input[0], "View") == 0)
    {
        return 2;
    }
    if (strcmp(input[0], "add_goods") == 0 || strcmp(input[0], "Add_goods") == 0 || strcmp(input[0], "ADD_GOODS") == 0 || strcmp(input[0], "Add_Goods") == 0)
    {
        return 3;
    }
    if (strcmp(input[0], "show_goods") == 0 || strcmp(input[0], "SHOW_GOODS") == 0 || strcmp(input[0], "Show_Goods") == 0 || strcmp(input[0], "Show_goods") == 0)
    {
        return 4;
    }
    else
    {
        printf("invalid command try again!\n");
    }
}
int buyer_command_check(char** input)
{
    if (strcmp(input[0], "logout") == 0 || strcmp(input[0], "LOGOUT") == 0 || strcmp(input[0], "Logout") == 0)
    {
        return 1;
    }
    if (strcmp(input[0], "view") == 0 || strcmp(input[0], "VIEW") == 0 || strcmp(input[0], "View") == 0)
    {
        return 2;
    }
    if (strcmp(input[0], "deposit") == 0 || strcmp(input[0], "DEPOSIT") == 0 || strcmp(input[0], "Deposit") == 0)
    {
        if (input[1][0] == 0)
        {
            printf("you must enter a number to add to your account!\ntry again!\n");
            return 0;

        }
        int i = 0;
        while (1 == 1)
        {
            if (input[1][i] == 0 && i != 0)
            {
                return 3;
            }
            else if (input[1][i] != '1' && input[1][i] != '2' && input[1][i] != '3' && input[1][i] != '4' && input[1][i] != '5' && input[1][i] != '6' && input[1][i] != '7' && input[1][i] != '8' && input[1][i] != '9' && input[1][i] != '0')
            {
                printf("thats an invalid value to deposit(it must be a number)\n");
                return 0;
            }


            i++;

        }

    }
    if (strcmp(input[0], "show_goods") == 0 || strcmp(input[0], "SHOW_GOODS") == 0 || strcmp(input[0], "Show_Goods") == 0 || strcmp(input[0], "Show_goods") == 0)
    {
        return 4;
    }
    if (strcmp(input[0], "buy") == 0 || strcmp(input[0], "BUY") == 0 || strcmp(input[0], "Buy") == 0)
    {
        return 5;
    }
    else
    {
        printf("invalid command try again!\n");
    }
}
void logout(int* loged_in)
{
    *loged_in = 0;
    printf("logout successful!\n");
}
void view_user(struct User loged_in_user)
{
    int i = 0;
    printf("\nUserName: %s", loged_in_user.name);
    printf("\nRole: %s\n", loged_in_user.role);
    if (strcmp(loged_in_user.role, "seller") == 0)
    {
        printf("the products you are selling are: ");

        while (1 == 1)
        {
            if (loged_in_user.products == 0)
            {
                printf("(this user is not selling any products yet!)\n");
                break;
            }
            if (i == loged_in_user.products_num)
            {
                printf("\n");
                break;
            }
            printf("\nname: %s", loged_in_user.products[i].name);
            printf("    price: %d", loged_in_user.products[i].price);
            printf("    count: %d", loged_in_user.products[i].count);
            i++;
        }

    }

    if (strcmp(loged_in_user.role, "buyer") == 0)
    {
        printf("Deposit: %d\n", loged_in_user.deposit);

        printf("the products you are buying are: ");

        while (1 == 1)
        {
            if (loged_in_user.products == 0)
            {
                printf("(this user is not buying any products yet!)\n");
                break;
            }
            if (i == loged_in_user.products_num)
            {
                printf("\n");
                break;
            }
            printf("\nname: %s", loged_in_user.products[i].name);
            printf("    price(for each): %d", loged_in_user.products[i].price);
            printf("    count: %d\n", loged_in_user.products[i].count);
            i++;
        }

    }

}
void deposit(struct User* loged_in_user, char** input)
{
    loged_in_user->deposit += atoi((input[1]));
    printf("%s has been added to your account\n", input[1]);
}
struct Product* add_goods(char** input, struct User* loged_in_user)
{

    struct Product* new_product;
    new_product = malloc(sizeof(struct Product));
    new_product->name = input[1];
    new_product->price = atoi(input[2]);
    new_product->count = atoi(input[3]);
    new_product->seller = loged_in_user;
    loged_in_user->products_num += 1;
    loged_in_user->products = realloc(loged_in_user->products, loged_in_user->products_num * sizeof(struct Product));
    loged_in_user->products[loged_in_user->products_num - 1] = *new_product;
    return new_product;
}
int check_add_goods(char** input, struct Product* products, int num_of_products, struct User* loged_in_user)
{
    if (num_of_products > 0)
    {
        for (int i = 0; i < num_of_products; i++)
        {
            if (strcmp(products[i].name, input[1]) == 0 && strcmp(products[i].seller->name, loged_in_user->name) != 0)
            {
                printf("this item is already being sold by %s.\n", products[i].seller->name);
                return 0;
            }
            else if (strcmp(products[i].name, input[1]) == 0 && strcmp(products[i].seller->name, loged_in_user->name) == 0 && products[i].price != atoi(input[2]))
            {

                printf("you can't change the price of any good!\n");
                return 0;


            }
            else if (strcmp(products[i].name, input[1]) == 0 && strcmp(products[i].seller->name, loged_in_user->name) == 0 && products[i].price == atoi(input[2]))
            {
                loged_in_user->products[i].count += atoi(input[3]);
                products[i].count += atoi(input[3]);
                printf("%s added to your count of %ss\n", input[3], input[1]);
                return 0;


            }
        }
    }
    int i = 0;
    for (int i = 0;i < 4;i++)
    {
        if (strcmp(input[i], "") == 0)
        {
            printf("invalid input to add a good\n");
            return 0;
        }
    }
    while (1 == 1)
    {
        if (input[2][i] == 0 && i != 0)
        {
            break;
        }
        else if (input[2][i] != '1' && input[2][i] != '2' && input[2][i] != '3' && input[2][i] != '4' && input[2][i] != '5' && input[2][i] != '6' && input[2][i] != '7' && input[2][i] != '8' && input[2][i] != '9' && input[2][i] != '0')
        {
            printf("thats an invalid value for price(it must be a number)\n");
            return 0;
        }


        i++;

    }
    i = 0;
    while (1 == 1)
    {
        if (input[3][i] == 0 && i != 0)
        {
            break;
        }
        else if (input[3][i] != '1' && input[3][i] != '2' && input[3][i] != '3' && input[3][i] != '4' && input[3][i] != '5' && input[3][i] != '6' && input[3][i] != '7' && input[3][i] != '8' && input[3][i] != '9' && input[3][i] != '0')
        {
            printf("thats an invalid value for count(it must be a number)\n");
            return 0;
        }


        i++;

    }
    return 1;

}
void show_goods(struct Product* products, int num_of_goods)
{
    int i = 0;

    while (1 == 1)
    {
        if (num_of_goods == 0)
        {
            printf("theres nothing go away");
            printf("\n");
            break;
        }
        if (i == num_of_goods)
        {
            printf("\n");
            break;
        }
        printf("\nname: %s", products[i].name);
        printf("    price: %d", products[i].price);
        printf("    count: %d", products[i].count);
        printf("    seller: %s\n", products[i].seller->name);
        i++;
    }
}
void buy(char** input, struct Product* products, int num_of_products, struct User* loged_in_user, struct User* users, int num_of_users)
{
    loged_in_user->products_num += 1;
    loged_in_user->products = realloc(loged_in_user->products, loged_in_user->products_num * sizeof(struct Product));
    loged_in_user->products[loged_in_user->products_num - 1].name = input[1];
    loged_in_user->products[loged_in_user->products_num - 1].count = atoi(input[2]);

    int i = 0;
    int j = 0;
    int k = 0;
    while (1 == 1)
    {
        if (strcmp(input[3], users[i].name) == 0)
        {
            break;
        }

        i++;
    }
    while (1 == 1)
    {
        if (strcmp(input[1], users[i].products[k].name) == 0)
        {
            break;
        }

        k++;
    }
    while (1 == 1)
    {
        if (strcmp(input[1], products[j].name) == 0)
        {
            break;
        }

        j++;
    }

    loged_in_user->deposit -= atoi(input[2]) * products[j].price;
    loged_in_user->products[loged_in_user->products_num - 1].price = products[j].price;
    users[i].products[k].count -= atoi(input[2]);
    products[j].count -= atoi(input[2]);





}
int check_buy(char** input, struct Product* products, int num_of_products, struct User* users, int num_of_users, struct User loged_in_user)
{

    int i = 0;
    int j = 0;
    int k = 0;


    for (int i = 0;i < 4;i++)
    {
        if (strcmp(input[i], "") == 0)
        {
            printf("invalid input\n");
            return 0;
        }
    }
    while (1 == 1)
    {
        if (strcmp(input[3], users[i].name) == 0)
        {
            break;
        }
        if (i == num_of_users - 1)
        {
            printf("a user with that name is not selling that product!\n");
            return 0;
        }

        i++;
    }
    while (1 == 1)
    {

        if (strcmp(input[1], users[i].products[k].name) == 0)
        {
            break;
        }
        else if (k == users[i].products_num - 1)
        {
            printf("a product with that name does not exist!\n");
            return 0;
        }

        k++;
    }
    while (1 == 1)
    {
        if (strcmp(input[1], products[j].name) == 0)
        {
            break;
        }
        else if (j == num_of_products - 1)
        {
            printf("a product with that name does not exist!\n");
            return 0;
        }

        j++;
    }
    if (products[j].price * atoi(input[2]) > loged_in_user.deposit)
    {
        printf("you do not have enough money in your account to buy %s of %s's %ss\n", input[2], input[3], input[1]);
        return 0;
    }
    if (atoi(input[2]) > users[i].products[k].count)
    {
        printf("%s does not have enough of %ss in storage\n", input[3], input[1]);
        return 0;
    }


    int l = 0;

    while (1 == 1)
    {
        if (input[2][l] == 0 && l != 0)
        {
            break;
        }
        else if (input[2][l] != '1' && input[2][l] != '2' && input[2][l] != '3' && input[2][l] != '4' && input[2][l] != '5' && input[2][l] != '6' && input[2][l] != '7' && input[2][l] != '8' && input[2][l] != '9' && input[2][l] != '0')
        {
            printf("thats an invalid value for count(it must be a number)\n");
            return 0;
        }


        l++;

    }
    if (strcmp(loged_in_user.name, "fil_e_abi") == 0 && strcmp(input[1], "lasagna") == 0 && strcmp(input[3], "arian")==0)
    {
        printf("******************************************\n\n\n\n");
        printf("%s gave %s a march(this is smaller than 3)\n", loged_in_user.name, input[3]);
        printf("\n\n\n\n******************************************\n");
        return 0;

    }
    if (strcmp(loged_in_user.name, "afa_khof") == 0 && strcmp(input[1], "spicy_soup") == 0 && strcmp(input[3], "arian") == 0)
    {
        printf("*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n\n\n\n");
        printf("splendor king\ntnx bruh\n(just debug it!)\n", loged_in_user.name, input[3]);
        printf("\n\n\n\n*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\\n");
        return 0;

    }






    return 1;
}


