#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
    int choice, quantity, categoryChoice;
    float total = 0;
    string orderSummary = ""; 
    float deliveryFee = 50.0;
    char deliveryOption;

    
    cout << "*** Welcome to KFC ****\n";
    cout << "***********************\n";

    while (true) 
    {
        // Display categories
        cout << "\nChoose a category:\n";
        cout << "1. Burgers\n";
        cout << "2. Snacks\n";
        cout << "3. Drinks\n";
        cout << "4. Combos\n";
        cout << "5. Exit\n";

        cout << "Enter your choice (1-5): ";
        cin >> categoryChoice;

        if (categoryChoice == 5) 
        { 
            break;
        }

        // Display the selected category menu
        switch (categoryChoice)
        {
        case 1:
            cout << "\nBurgers Menu:\n";
            cout << "1. Zinger Burger - Rs. 350\n";
            cout << "2. Double Zinger - Rs. 500\n";
            cout << "3. Crispy Burger - Rs. 400\n";
            cout << "4 Chicken Burger - Rs. 450\n";
            cout << "5. Cheese Burger - Rs. 380\n";
            break;

        case 2:
            cout << "\nSnacks Menu:\n";
            cout << "1. Chicken Wings (6 pcs) - Rs. 250\n";
            cout << "2. Chicken Nuggets (8 pcs) - Rs. 300\n";
            cout << "3. Fries (Regular) - Rs. 150\n";
            cout << "4. Fries (Large) - Rs. 250\n";
            cout << "5. Popcorn Chicken - Rs. 200\n";
            break;

        case 3:
            cout << "\nDrinks Menu:\n";
            cout << "1. Soft Drink - Rs. 100\n";
            cout << "2. Juice - Rs. 120\n";
            cout << "3. Water Bottle - Rs. 80\n";
            cout << "4. Cold Coffee - Rs. 180\n";
            cout << "5. Milkshake - Rs. 250\n";
            break;

        case 4:
            cout << "\nCombos Menu:\n";
            cout << "1. Zinger Combo - Rs. 600\n";
            cout << "2. Crispy Combo - Rs. 750\n";
            cout << "3. Family Combo - Rs. 1500\n";
            cout << "4. Snack Combo - Rs. 500\n";
            cout << "5. Kid's Combo - Rs. 450\n";
            break;

        default:
            cout << "Invalid choice. Please select a valid category.\n";
            continue;
        }

        // Asking user to select an item from the chosen category
        cout << "\nEnter the item number from the menu: ";
        cin >> choice;

        cout << "Enter quantity: ";
        cin >> quantity;

        // Variable to store item price and name
        string itemName;
        float itemPrice = 0;

        // Determine the price and name based on choice
        if (categoryChoice == 1) 
        {
            if (choice == 1)
            { 
                itemName = "Zinger Burger"; itemPrice = 350; 
            }

            else if(choice == 2)
            {
                itemName = "Double Zinger"; itemPrice = 500; 
            }

            else if (choice == 3) 
            { 
                itemName = "Crispy Burger"; itemPrice = 400;
            }

            else if (choice == 4) 
            {
                itemName = "Grilled Chicken Burger"; itemPrice = 450;
            }

            else if (choice == 5) 
            {
                itemName = "Cheese Burger"; itemPrice = 380;
            }

            else 
            {
                cout << "Invalid burger choice.\n"; 
                continue; 
            }
        }
        else if (categoryChoice == 2)
        {
            if (choice == 1) 
            { 
                itemName = "Chicken Wings (6 pcs)"; itemPrice = 250;
            }

            else if (choice == 2)
            {
                itemName = "Chicken Nuggets (8 pcs)"; itemPrice = 300;
            }

            else if (choice == 3)
            {
                itemName = "Fries (Regular)"; itemPrice = 150;
            }

            else if (choice == 4)
            { 
                itemName = "Fries (Large)"; itemPrice = 250;
            }

            else if (choice == 5)
            {
                itemName = "Popcorn Chicken"; itemPrice = 200;
            }

            else
            {
                cout << "Invalid snack choice.\n";
                continue; 
            }
        }

        else if (categoryChoice == 3)
        {
            if (choice == 1) 
            { 
                itemName = "Soft Drink"; itemPrice = 100;
            }

            else if (choice == 2)
            { 
                itemName = "Juice"; itemPrice = 120; 
            }

            else if (choice == 3) 
            {
                itemName = "Water Bottle"; itemPrice = 80;
            }

            else if
                (choice == 4) 
            {
                itemName = "Cold Coffee"; itemPrice = 180;
            }

            else if (choice == 5) 
            { 
                itemName = "Milkshake"; itemPrice = 250;
            }

            else
            {
                cout << "Invalid drink choice.\n"; 
                continue;
            }
        }

        else if (categoryChoice == 4)
        {
            if (choice == 1)
            {
                itemName = "Zinger Combo"; itemPrice = 600;
            }

            else if (choice == 2)
            {
                itemName = "Crispy Combo"; itemPrice = 750;
            }

            else if (choice == 3)
            {
                itemName = "Family Combo"; itemPrice = 1500;
            }

            else if (choice == 4) 
            {
                itemName = "Snack Combo"; itemPrice = 500;
            }

            else if (choice == 5)
            {
                itemName = "Kid's Combo"; itemPrice = 450;
            }

            else 
            { 
                cout << "Invalid combo choice.\n"; 
                continue; 
            }
        }

        // Calculate total for current item and add to grand total
        float orderTotal = itemPrice * quantity;
        total += orderTotal;

        // Store order details in the summary string
        orderSummary += to_string(quantity) + " x " + itemName + " Rs. "
            + to_string(static_cast<int>(itemPrice)) + " each = Rs. "
            + to_string(static_cast<int>(orderTotal)) + "\n";
    }

    // Ask for delivery option
    cout << "\nWould you like delivery (Rs. 50 extra)? (y/n): ";
    cin >> deliveryOption;

    if (deliveryOption == 'y' || deliveryOption == 'Y') 
{
        total += deliveryFee;
        orderSummary += "Delivery Fee = Rs. 50\n";
    }

    // Print the final total bill with order details
    cout << "\n**********************************\n";
    cout << "Order Summary:\n" << orderSummary;
    cout << "Total Bill:" << total << "\n";
    cout << "*** Thank you for dining at KFC ***\n";

    return 0;
}