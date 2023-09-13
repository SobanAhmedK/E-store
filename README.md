# E_store
An online store having features for both buyer and seller using core DSA concepts.
# Online Shopping System


## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [How to Use](#how-to-use)
- [Data Structures](#data-structures)
- [Cart Functionality](#cart-functionality)
- [Time Management](#time-management)
- [User Authentication](#user-authentication)
- [Contributing](#contributing)


## Introduction
The Online Shopping System is a full-fledged e-commerce platform designed to provide users with a seamless online shopping experience. This project offers a comprehensive set of features for both buyers and sellers, including product management, a shopping cart, order processing, and user authentication.

### Key Highlights
- Efficient data structures for product categorization and management.
- Shopping cart functionality for adding and removing items.
- Time management for estimating delivery times.
- User authentication to ensure secure access.

## Features
- **Product Management:** Sellers can add, update, and delete products in various categories.
- **Shopping Cart:** Buyers can add products to their cart, review items, and place orders.
- **Order Processing:** The system calculates estimated delivery times based on order volume.
- **User Authentication:** Secure login and authentication for users and sellers.
- **Data Export:** Export product data to CSV files for backup and analysis.

## Project Structure
The project is organized into several files, each responsible for different functionalities. Key files include:
- `main.cpp`: The main program that interacts with users and manages the system.
- `crud_functions.cpp`: Contains data structures and CRUD (Create, Read, Update, Delete) operations for products.
- `cart_functions.cpp`: Manages the shopping cart, allowing users to add and remove items.
- `time_functions.cpp`: Handles time calculations and order time management.
- `authentication.cpp`: Provides user authentication functionality.

## How to Use
1. Clone the repository to your local machine.
2. Compile the project using a C++ compiler (e.g., g++).
3. Run the compiled executable (`./your_executable_name`).
4. Follow the on-screen instructions to interact with the system as a buyer or seller.

## Data Structures
The project utilizes custom binary search trees (BSTs) for efficient product categorization and management. Each category (e.g., food, electronics) has its own BST for storing product information.

## Cart Functionality
The shopping cart functionality allows buyers to add and remove items, review their cart contents, and proceed to checkout. The CART_LIST class manages the cart's data structure.

## Time Management
The system estimates delivery times based on order volume. The `time()` function calculates the time required for delivery, while `time_updation()` handles time updates.

## User Authentication
User authentication is implemented to ensure secure access. The `authentication()` function checks provided usernames and PINs against user account records stored in "accounts.csv."

## Contributing
Contributions are welcome! If you have any ideas, feature requests, or bug reports, please open an issue or submit a pull request.


