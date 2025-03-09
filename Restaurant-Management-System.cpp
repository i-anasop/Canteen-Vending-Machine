#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

int stock[25] = {15, 20, 10, 18, 25, 12, 18, 15, 20, 22, 30, 12, 18, 20, 25, 10, 15, 20, 17, 15, 14, 18, 20, 12, 16};
string cart[100];
double cartPrices[100];
int cartQuantities[100];
int cartSize = 0;
double totalPrice = 0.0;

void Exit(); 
void Developed_by();
void displaySectionItems(int sectionChoice);
double selectItem(int choice, string &itemName);
void addItemToCart(int itemChoice, int quantity, double price, string itemName);
void applyDiscount(double &total);
void displayBill(double total);
void handleOrder();
void processTransaction();
void processPayment(double total);
void restockInventory(int *stock); 

int main() 
{
    processTransaction();
    return 0;
}

void processTransaction() 
{
    int sectionChoice;
    cout << "\n\t+============================================+\n";
    cout << "\t|        WELCOME TO HARDEE's RESTAURANT      |\n";
    cout << "\t+============================================+\n";
    cout << "\t|         Select a Section                   |\n";
    cout << "\t+============================================+\n";
    cout << "\t|    1    |  Cold Drinks                     |\n";
    cout << "\t|    2    |  Desserts                        |\n";
    cout << "\t|    3    |  Fast Food                       |\n";
    cout << "\t|    4    |  Chocolates                      |\n";
    cout << "\t|    5    |  Sandwiches                      |\n";
    cout << "\t|    6    |  Exit                            |\n";
    cout << "\t+============================================+\n";
    cout << "\n\t+============================================+\n";
    cout << "\t|           Select a section (1-6):          |\n";
    cout << "\t+============================================+\n";
    cout << "\t              Your choice:  "; 
    cin >> sectionChoice;

    if (sectionChoice != 6) 
	{	
    displaySectionItems(sectionChoice); 
    handleOrder();
	}
    else if (sectionChoice == 6) 
	{
    Exit();
    Developed_by();
    exit(0);
    }
}

void Exit() 
{
    cout << "\n\t+============================================+\n";
    cout << "\t|                                            |\n";
    cout << "\t|          Thank You for Visiting!           |\n";
    cout << "\t|             Have a great day!              |\n";
    cout << "\t|                                            |\n";
    cout << "\t+============================================+\n";	
}


void Developed_by() 
{
    cout << "\n\t+============================================+\n";
    cout << "\t|               DEVELOPED BY                 |\n";
    cout << "\t+--------------------------------------------+\n";
    cout << "\t|     This was made by a First Semester      |\n";
    cout << "\t|     Student with also the help of GPT      |\n";
    cout << "\t+============================================+\n";
    exit(0);
}

void handleOrder() 
{
    int itemChoice, quantity;
    string itemName;
    double total = 0.0;
    char continueChoice;

    do { 
    cout << "\n\t+=========================================+\n";
    cout << "\t|        Enter the item number you        |\n";
    cout << "\t|             want to order               |\n";
    cout << "\t+=========================================+\n";
    cout << "\n\tItem Number: ";
    cin >> itemChoice;
    
    if(itemChoice<1 || itemChoice>25)
    {
    cout << "\n\t*******************************************\n";
    cout << "\t*                                         *\n"; 
    cout << "\t*    InValid Choice, Kindly Try Again     *\n"; 
    cout << "\t*                                         *\n"; 
    cout << "\t*******************************************\n";
    handleOrder();
	}
    cout << "\n\t+=========================================+\n";
    cout << "\t|           Enter the quantity            |\n";
    cout << "\t+=========================================+\n";
    cout << "\n\tQuantity: ";
    cin >> quantity;
    if(quantity>stock[itemChoice-1])
    {
    cout << "\n\t*******************************************\n";
    cout << "\t*                                         *\n"; 
    cout << "\t*    Sorry, Stock only have "<<stock[itemChoice-1]<<" Items      *\n"; 
    cout << "\t*                                         *\n"; 
    cout << "\t*******************************************\n";
    handleOrder();
	}
    double price = selectItem(itemChoice, itemName);
    if (price == -1) 
	{
    cout << "\n\t+-----------------------------------------+\n";
    cout << "\t|       ITEM OUT OF STOCK, TRY AGAIN      |\n"; 
    cout << "\t+-----------------------------------------+\n";
    } 
    else if (price == -2) 
	{
    cout << "\n\t+-----------------------------------------+\n";
    cout << "\t|             INVALID CHOICE              |\n"; 
    cout << "\t+-----------------------------------------+\n";
    } 
	else 
	{
    addItemToCart(itemChoice, quantity, price, itemName);
    total += price * quantity;
    totalPrice += total;
    cout << "\n\t+=========================================+\n";
    cout << "\t|   ITEM ADDED TO CART:      " << itemName << "        |\n"; 
    cout << "\t+-----------------------------------------+\n";
    cout << "\t|        Current total:      $" << totalPrice << "     |\n";
    cout << "\t+=========================================+\n";
    }
    cout << "\n\t+-----------------------------------------+\n";
    cout << "\t|        Do You Want to Order More?       |\n"; 
    cout << "\t+-----------------------------------------+\n";
    cout << "\n\t(Y/N): ";
    cin >> continueChoice;
    continueChoice = toupper(continueChoice);
    
    if(continueChoice=='Y')
	{
	processTransaction();
	}
	else if(continueChoice=='N')
	{
	applyDiscount(totalPrice);
    displayBill(totalPrice);
    processPayment(totalPrice);
	}
    } while (true);

}

void displaySectionItems(int sectionChoice) 
{
    switch (sectionChoice) 
	{
    case 1:
        cout << "\n\t+=========================================+\n";
        cout << "\t|              COLD DRINKS                |\n";
        cout << "\t+=========================================+\n";
        cout << "\t|    1    |  Pepsi       |  $1.50  |  " << stock[0] << "  |\n";
        cout << "\t|    2    |  7up         |  $1.50  |  " << stock[1] << "  |\n";
        cout << "\t|    3    |  Coke        |  $1.75  |  " << stock[2] << "  |\n";
        cout << "\t|    4    |  Mirinda     |  $1.50  |  " << stock[3] << "  |\n";
        cout << "\t|    5    |  Fanta       |  $1.50  |  " << stock[4] << "  |\n";
        cout << "\t+-----------------------------------------+\n";
        break;
        
    case 2:
        cout << "\n\t+=========================================+\n";
        cout << "\t|                DESSERTS                 |\n";
        cout << "\t+=========================================+\n";
        cout << "\t|    6    |  Ice Cream   |  $3.00  |  " << stock[5] << "  |\n";
        cout << "\t|    7    |  Cake        |  $2.50  |  " << stock[6] << "  |\n";
        cout << "\t|    8    |  Brownie     |  $2.00  |  " << stock[7] << "  |\n";
        cout << "\t|    9    |  Cupcake     |  $2.00  |  " << stock[8] << "  |\n";
        cout << "\t|    10   |  Pudding     |  $2.00  |  " << stock[9] << "  |\n";
        cout << "\t+-----------------------------------------+\n";
        break;

    case 3:
        cout << "\n\t+=========================================+\n";
        cout << "\t|               FAST FOOD                 |\n";
        cout << "\t+=========================================+\n";
        cout << "\t|    11   |  Burger      |  $5.00  |  " << stock[10] << "  |\n";
        cout << "\t|    12   |  Pizza       |  $6.00  |  " << stock[11] << "  |\n";
        cout << "\t|    13   |  Fries       |  $2.50  |  " << stock[12] << "  |\n";
        cout << "\t|    14   |  Hot Dog     |  $3.00  |  " << stock[13] << "  |\n";
        cout << "\t|    15   |  Wrap        |  $4.00  |  " << stock[14] << "  |\n";
        cout << "\t+-----------------------------------------+\n";
        break;
        
    case 4:
        cout << "\n\t+=========================================+\n";
        cout << "\t|               CHOCOLATES                |\n";
        cout << "\t+=========================================+\n";
        cout << "\t|    16   |  Snickers    |  $2.00  |  " << stock[15] << "  |\n";
        cout << "\t|    17   |  Kit Kat     |  $2.50  |  " << stock[16] << "  |\n";
        cout << "\t|    18   |  M&Ms        |  $1.75  |  " << stock[17] << "  |\n";
        cout << "\t|    19   |  Mars        |  $2.50  |  " << stock[18] << "  |\n";
        cout << "\t|    20   |  Dairy Milk  |  $2.00  |  " << stock[19] << "  |\n";
        cout << "\t+-----------------------------------------+\n";
        break;

    case 5:
        cout << "\n\t+=========================================+\n";
        cout << "\t|              SANDWICHES                 |\n";
        cout << "\t+=========================================+\n";
        cout << "\t|    21   |  Chicken    |  $4.00  |  " << stock[20] << "   |\n";
        cout << "\t|    22   |  Veggie     |  $3.50  |  " << stock[21] << "   |\n";
        cout << "\t|    23   |  Tuna       |  $4.50  |  " << stock[22] << "   |\n";
        cout << "\t|    24   |  Cheese     |  $3.75  |  " << stock[23] << "   |\n";
        cout << "\t|    25   |  Ham        |  $4.00  |  " << stock[24] << "   |\n";
        cout << "\t+-----------------------------------------+\n";
        break;

    default:
        cout << "\n\t**********************************************\n";
        cout << "\t*                                            *\n"; 
        cout << "\t*      InValid Choice, Kindly Try Again      *\n"; 
        cout << "\t*                                            *\n"; 
        cout << "\t**********************************************\n";
        processTransaction();
    }
}

double selectItem(int choice, string &itemName) 
{
    double price = 0.0;
    switch (choice) 
    {
    case 1:
        if (stock[0] > 0) 
        {
            itemName = "Pepsi"; 
            stock[0]--; 
            price = 1.50;
        } 
        else 
        {
            price = -1; 
        }
        break;
        
    case 2:
        if (stock[1] > 0)
        {
            itemName = "7up"; 
            stock[1]--;
            price = 1.50; 
        } 
        else
        {
            price = -1;
        }
        break;
        
    case 3:
        if (stock[2] > 0)
        {
            itemName = "Coke";
            stock[2]--; 
            price = 1.75; 
        } 
        else 
        {
            price = -1; 
        }
        break;
        
    case 4:
        if (stock[3] > 0) 
        {
            itemName = "Mirinda"; 
            stock[3]--; 
            price = 1.50; 
        } 
        else
        {
            price = -1; 
        }
        break;

    case 5:
        if (stock[4] > 0)
        {
            itemName = "Fanta"; 
            stock[4]--; 
            price = 1.50; 
        } 
        else 
        {
            price = -1;
        }
        break;
        
    case 6:
        if (stock[5] > 0) {
        itemName = "Ice Cream";
        stock[5]--;
        price = 3.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 7:
        if (stock[6] > 0) {
        itemName = "Cake";
        stock[6]--;
        price = 2.50;
        } 
		else {
        price = -1;
        }
        break;
        
    case 8:
        if (stock[7] > 0) {
        itemName = "Brownie";
        stock[7]--;
        price = 2.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 9:
        if (stock[8] > 0) {
        itemName = "Cupcake";
        stock[8]--;
        price = 2.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 10:
        if (stock[9] > 0) {
        itemName = "Pudding";
        stock[9]--;
        price = 2.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 11:
        if (stock[10] > 0) {
        itemName = "Burger";
        stock[10]--;
        price = 5.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 12:
        if (stock[11] > 0) {
        itemName = "Pizza";
        stock[11]--;
        price = 6.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 13:
        if (stock[12] > 0) {
        itemName = "Fries";
        stock[12]--;
        price = 2.50;
        } 
		else {
        price = -1;
        }
        break;
        
    case 14:
        if (stock[13] > 0) {
        itemName = "Hot Dog";
        stock[13]--;
        price = 3.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 15:
        if (stock[14] > 0) {
        itemName = "Wrap";
        stock[14]--;
        price = 4.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 16:
        if (stock[15] > 0) {
        itemName = "Snickers";
        stock[15]--;
        price = 2.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 17:
        if (stock[16] > 0) {
        itemName = "Kit Kat";
        stock[16]--;
        price = 2.50;
        } 
		else {
        price = -1;
        }
        break;
        
    case 18:
        if (stock[17] > 0) {
        itemName = "M&Ms";
        stock[17]--;
        price = 1.75;
        } 
		else {
        price = -1;
        }
        break;
        
    case 19:
        if (stock[18] > 0) {
        itemName = "Mars";
        stock[18]--;
        price = 2.50;
        } 
		else {
        price = -1;
        }
        break;
        
    case 20:
        if (stock[19] > 0) {
        itemName = "Dairy Milk";
        stock[19]--;
        price = 2.00;
        }
		else {
        price = -1;
        }
        break;
        
    case 21:
        if (stock[20] > 0) {
        itemName = "Chicken Sandwich";
        stock[20]--;
        price = 4.00;
        } 
		else {
        price = -1;
        }
        break;
        
    case 22:
        if (stock[21] > 0) {
        itemName = "Veggie Sandwich";
        stock[21]--;
        price = 3.50;
        } 
		else {
        price = -1;
        }
        break;
        
    case 23:
        if (stock[22] > 0) {
        itemName = "Tuna Sandwich";
        stock[22]--;
        price = 4.50;
        } 
		else {
        price = -1;
        }
        break;
        
    case 24:
        if (stock[23] > 0) {
        itemName = "Cheese Sandwich";
        stock[23]--;
        price = 3.75;
        } 
		else {
        price = -1;
        }
        break;
        
    case 25:
        if (stock[24] > 0) {
        itemName = "Ham Sandwich";
        stock[24]--;
        price = 4.00;
        } 
		else {
        price = -1;
        }
        break;
        
     default:
        price = -2;
        itemName = "Invalid Choice"; 
        break;
    }
    return price; 
}
void addItemToCart(int itemChoice, int quantity, double price, string itemName) 
{
    if (cartSize < 100)  // Check if the cart has space for more items
    {  
        cart[cartSize] = itemName;  // Add the item's name to the cart array
        cartPrices[cartSize] = price;  // Store the item's price in the cartPrices array
        cartQuantities[cartSize] = quantity;  // Store the item's quantity in the cartQuantities array
        cartSize++;  // Increment the cart size counter
    } 
    else 
    {
        cout << "\n\t+-----------------------------------------+\n"; 
        cout << "\t|              Cart is Full               |\n";  
        cout << "\t+-----------------------------------------+\n"; 
    }
}

void applyDiscount(double &total) 
{
    cout << "\n\t+============================================+\n"; 
    cout << "\t|            Applying discount ...           |\n"; 
    cout << "\t+============================================+\n"; 
    
    if (total >= 100.0)  // Check if total is $100 or more
    {
        total *= 0.85;  // Apply a 15% discount
        cout << "\t|            15% discount Applied            |\n"; 
    } 
    else if (total >= 50.0)  // Check if total is $50 or more
    {
        total *= 0.90;  // Apply a 10% discount
        cout << "\t|            10% discount Applied            |\n"; 
    }
    else if (total >= 30.0)  // Check if total is $30 or more
    {
        total *= 0.95;  // Apply a 5% discount
        cout << "\t|             5% discount Applied            |\n"; 
    } 
    else 
    {
        cout << "\t|    Unfortunately, No discount Applied      |\n";  
    }
    cout << "\t+============================================+\n"; 
}

void displayBill(double total) 
{
    cout << "\n\t+============================================+\n"; 
    cout << "\t|                    BILL                    |\n"; 
    cout << "\t+============================================+\n";
    for (int i = 0; i < cartSize; i++)  
    {
        cout << "\t|        " << cartQuantities[i] << " x " << cart[i] 
             << "    |    $ " << cartPrices[i] * cartQuantities[i] << "             |\n"; 
    }
    cout << "\t+============================================+\n"; 
    cout << "\t|       TOTAL         :    $" << fixed << setprecision(2) << total 
         << "             |\n"; 
    cout << "\t+============================================+\n"; 
}

void processPayment(double total) 
{
    double payment; 
    cout << "\n\tEnter payment amount: $";  
    cin >> payment;  

    if (payment >= total)  
    {
        double change = payment - total;  // Calculate the change
        cout << "\n\t==========================================\n"; 
        cout << "\t|            PAYMENT COMPLETE            |\n"; 
        cout << "\t|         Your change: $" << change << "             |\n"; 
        cout << "\t==========================================\n"; 
        restockInventory(stock); 
        Exit();  
        Developed_by();  
    } 
    else 
    {
        cout << "\n\t==========================================\n"; 
        cout << "\t|          INSUFFICIENT PAYMENT!         |\n";
        cout << "\t|       Please pay the full amount       |\n"; 
        cout << "\t==========================================\n"; 
        processPayment(total);  
    }
}

void restockInventory(int *stock) 
{
    for (int i = 0; i < 25; i++) 
    {
        stock[i] = 20; 
    }
}

