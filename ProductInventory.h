// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#include <string>
#include <iostream>

// Use the standard namespace to simplify code
using namespace std;

// The Product class represents a general category of items managed in an inventory system.
 
class Product {
protected:
    string name;          // Name of the product
    string brand;         // Brand of the product
    double price;         // Price of the product
    int quantity;         // Quantity of the product in stock
    string description;   // Brief description of the product
    string category;      // Category of the product (e.g., clothing, electronics)

public:
    // Setter for the product item name
    void setName(const string& name) { this->name = name; }

    // Setter for the product item brand
    void setBrand(const string& brand) { this->brand = brand; }
    
    // Setter for the product item price
    void setPrice(double price) { this->price = price; }
    
    // Setter for the product item quantity
    void setQuantity(int quantity) { this->quantity = quantity; }
    
    // Setter for the product item description
    void setDescription(const string& description) { this->description = description; }
    
    // Setter for the product item category
    void setCategory(const string& category) { this->category = category; }

    // Getter for the product item name
    string getName() const { return name; }
    
    // Getter for the product item brand
    string getBrand() const { return brand; }
    
    // Getter for the product item price
    double getPrice() const { return price; }
    
    // Getter for the product item quantity
    int getQuantity() const { return quantity; }
    
    // Getter for the product item description
    string getDescription() const { return description; }
    
    // Getter for the product item category
    string getCategory() const { return category; }

    // Prints the details of the product.
    virtual void printDetails() const {
        cout << "Name: " << name << "\nBrand: " << brand << "\nPrice: $" << price 
             << "\nQuantity: " << quantity << "\nDescription: " << description 
             << "\nCategory: " << category << endl;
    }
};

/**
 * The Clothing class represents a clothing item in the inventory system.
 * Inherits from Product.
 */
class Clothing : public Product {
private:
    string size;          // Size of the clothing item (e.g., S, M, L)
    string color;         // Color of the clothing item
    string material;      // Material of the clothing item (e.g., cotton, polyester)

public:
    // Setter for the clothing size
    void setSize(const string& size) { this->size = size; }
    
    // Setter for the clothing color
    void setColor(const string& color) { this->color = color; }
    
    // Setter for the clothing material
    void setMaterial(const string& material) { this->material = material; }

    // Getter for the clothing size
    string getSize() const { return size; }
    
    // Getter for the clothing color
    string getColor() const { return color; }
    
    // Getter for the clothing material
    string getMaterial() const { return material; }

    /**
     * Prints the details of the clothing item.
     */
    void printDetails() const override {
        Product::printDetails();
        cout << "Size: " << size << "\nColor: " << color << "\nMaterial: " << material << endl;
    }
};

/**
 * The Electronics class represents an electronic item in the inventory system.
 * Inherits from Product.
 */
class Electronics : public Product {
private:
    string model;                    // Model of the electronic item
    string warranty;                 // Warranty period for the electronic item
    string technicalSpecifications;  // Technical specifications of the electronic item

public:
    // Setter for the electronics model
    void setModel(const string& model) { this->model = model; }
    
    // Setter for the electronics warranty
    void setWarranty(const string& warranty) { this->warranty = warranty; }
    
    // Setter for the electronics technical specifications
    void setTechnicalSpecifications(const string& technicalSpecifications) { this->technicalSpecifications = technicalSpecifications; }

    // Getter for the electronics model
    string getModel() const { return model; }
    
    // Getter for the electronics warranty
    string getWarranty() const { return warranty; }
    
    // Getter for the electronics technical specifications
    string getTechnicalSpecifications() const { return technicalSpecifications; }

    /**
     * Prints the details of the electronic item.
     */
    void printDetails() const override {
        Product::printDetails();
        cout << "Model: " << model << "\nWarranty: " << warranty 
             << "\nTechnical Specifications: " << technicalSpecifications << endl;
    }
};

