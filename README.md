# ut_kala_phase1
a shoping program that runs on the command line (phase1: does not save information after closing the program)

## the commands and what the do and how they work

**signup username password role**\
**Example: signup person 123 seller**\
this command is for signup in the program(obviously) \
there can only be one person with the same username and role in this program \
the role can be a buyer or a seller 

**login username password role**\
**Example: login otherPerson 231 buyer**\
this command logs a user in to the program 

**logout**\
**Example: logout**\
this command logs the loged in user out of this program \
it is mandatory to logout of the program to switch between users(two users cannot login at once) \

**view**\
**Example: view**\
any loged in uder can use this command to see there information(name amount of money they have and the products they are selling or buying) \

**deposit amount_of_money**\
**Example: deposit 1000**\
this command is for users with the role of buyer only \
a buyer can add to there accounts amount of money using this command \

**add_goods goods_name goods_price goods_count**\
**Example: add_goods watch 10000 3**\
this command is for users with the role of seller only \
a seller can use this command to add a prduct to sell specifying the name price and count \

**show_goods**\
**Example: show_goods**\
this command can be used at anytime it shows all of the products being sold \
it shows there name, seller, count, and  price. \

**buy goods_name goods_count seller_username**\
**Example: buy watch 1 thirdPerson**\

