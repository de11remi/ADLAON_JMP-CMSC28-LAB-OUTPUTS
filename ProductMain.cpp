// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#include <iostream>
#include "ProductInventory.h"

// Use the standard namespace to simplify code
using namespace std;

int main() {
    // Create an instance of Clothing
    Clothing shirt;
    shirt.setName("Half-zip Sweatshirt");
    shirt.setBrand("Uniqlo");
    shirt.setPrice(11.99);
    shirt.setQuantity(10);
    shirt.setDescription("Airy cotton sweatshirt with fine texture.");
    shirt.setCategory("Clothing");
    shirt.setSize("M");
    shirt.setColor("Cream");
    shirt.setMaterial("100% Cotton");

    // Create an instance of Electronics
    Electronics phone;
    phone.setName("Smartphone");
    phone.setBrand("Xiaomi");
    phone.setPrice(374.50);
    phone.setQuantity(15);
    phone.setDescription("5G Phone and lightweight for sleek feature.");
    phone.setCategory("Electronics");
    phone.setModel("2109119DG");
    phone.setWarranty("2 years");
    phone.setTechnicalSpecifications("128GB Storage, 8GB RAM, 64MP Wide Camera");

    // Print inventory system name
    cout << "J_DVO STORE INVENTORY SYSTEM\n" << endl;

    // Print details of each product
    cout << "CLOTHING ITEM DETAILS:" << endl;
    shirt.printDetails();
    cout << endl;

    cout << "ELECTRONICS ITEM DETAILS:" << endl;
    phone.printDetails();

    return 0;
}
