char** getinput();

struct User* signup(char** input);

int command_check(char** input);


int check_signup(char** input, struct User* users, int num_of_users);
int login(char** input, struct User* users, int num_of_users, int* user_num);
void logout(int* loged_in);
int seller_command_check(char** input);
int buyer_command_check(char** input);

void view_user(struct User loged_in_user);
void deposit(struct User* loged_in_user, char** input);
struct Product* add_goods(char** input, struct User* loged_in_user);
int check_add_goods(char** input, struct Product* products, int num_of_products, struct User* loged_in_user);
void show_goods(struct Product* products, int num_of_goods);
void buy(char** input, struct Product* products, int num_of_products, struct User* loged_in_user, struct User* users, int num_of_users);
int check_buy(char** input, struct Product* products, int num_of_products, struct User* users, int num_of_users, struct User loged_in_user);




