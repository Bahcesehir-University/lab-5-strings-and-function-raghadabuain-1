
// ============================================================
// Lab: Strings and String Operations with Function & Operator
//  Overloading in C++
// Course: Object-Oriented Programming for Engineers
// Level: 2nd Year Engineering
// Duration: 70 minutes
// ============================================================
// SINGLE FILE IMPLEMENTATION - No header files allowed
// ============================================================
// STUDENT VERSION - Implement all TODO sections
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

class MyString {
private:
string data;

public:
// ---- Constructors ----
MyString();
MyString(const string& str);
MyString(const char* str);

// ---- Getter ----
string getData() const;

// ---- Basic String Operations ----
int length() const;
char charAt(int index) const;
MyString substring(int start, int len) const;

// ---- String Manipulation ----
MyString toUpperCase() const;
MyString toLowerCase() const;
MyString trim() const;
MyString reverse() const;

// ---- Search Operations ----
int find(const MyString& target) const;
int count(char ch) const;

// ---- Function Overloading: append ----
MyString append(const MyString& other) const;
MyString append(const char* cstr) const;
MyString append(char ch) const;
MyString append(int number) const;

// ---- Function Overloading: replace ----
MyString replace(char oldCh, char newCh) const;
MyString replace(const string& oldStr, const string& newStr) const;

// ---- Operator Overloading ----
MyString operator+(const MyString& other) const;  // Concatenation
bool operator==(const MyString& other) const; // Equality
bool operator!=(const MyString& other) const;  // Inequality
bool operator<(const MyString& other) const; // Less than
bool operator>(const MyString& other) const; // Greater than
char operator[](int index) const; // Indexing
MyString operator*(int times) const;  // Repeat

// ---- Stream Overloading ----
friend ostream& operator<<(ostream& os, const MyString& s);
friend istream& operator>>(istream& is, MyString& s);
};

// ================================
// FUNCTION IMPLEMENTATIONS
// ================================

// ---- Constructors ----

MyString::MyString() {
// TODO: Initialize with empty string
data = "";
}

MyString::MyString(const string& str) {
// TODO: Initialize data with the given std::string
data = str;
}

MyString::MyString(const char* str) {
// TODO: Initialize data with the given C-string
data = str;
}

// ---- Getter ----

string MyString::getData() const {
// TODO: Return the internal string data
return data;
}

// ---- Basic String Operations ----

int MyString::length() const {
// TODO: Return the length of the string
return data.length();
}

char MyString::charAt(int index) const {
// TODO: Return character at given index
// Throw std::out_of_range if index is invalid (negative or >= length)
if (index < 0 || index >= data.length())
throw out_of_range("Index out of range");
return data[index];
}

MyString MyString::substring(int start, int len) const {
// TODO: Return a substring starting at 'start' with length 'len'
// Throw std::out_of_range if start is invalid (negative or >= length)
// Hint: Use std::string::substr()
if (start < 0 || start >= data.length())
throw out_of_range("Start index out of range");
return MyString(data.substr(start, len));
}

// ---- String Manipulation ----

MyString MyString::toUpperCase() const {
// TODO: Return a NEW MyString with all characters converted to upper case
// Hint: Use std::transform with ::toupper
// Do NOT modify the original object
string temp = data;
transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
return MyString(temp);
}

MyString MyString::toLowerCase() const {
// TODO: Return a NEW MyString with all characters converted to lower case
// Hint: Use std::transform with ::tolower
// Do NOT modify the original object
string temp = data;
transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
return MyString(temp);
}

MyString MyString::trim() const {
// TODO: Return a NEW MyString with leading and trailing whitespace removed
// Whitespace includes: space, tab (\t), newline (\n), carriage return (\r)
// Hint: Use find_first_not_of and find_last_not_of
size_t start = data.find_first_not_of(" \t\n\r");
size_t end = data.find_last_not_of(" \t\n\r");

if (start == string::npos) return MyString("");

return MyString(data.substr(start, end - start + 1));
}

MyString MyString::reverse() const {
// TODO: Return a NEW MyString with characters in reverse order
// Hint: Use std::reverse on a copy
string temp = data;
std::reverse(temp.begin(), temp.end());
return MyString(temp);
}

// ---- Search Operations ----

int MyString::find(const MyString& target) const {
// TODO: Return index of first occurrence of target, or -1 if not found
// Hint: Use std::string::find, check against string::npos
size_t pos = data.find(target.data);
if (pos == string::npos) return -1;
return pos;
}

int MyString::count(char ch) const {
// TODO: Return the number of occurrences of character ch in the string
return std::count(data.begin(), data.end(), ch);
}

// ---- Function Overloading: append ----
// These four functions demonstrate FUNCTION OVERLOADING:
// Same name "append", different parameter types.

MyString MyString::append(const MyString& other) const {
// TODO: Append another MyString to this one and return the result
return MyString(data + other.data);
}

MyString MyString::append(const char* cstr) const {
// TODO: Append a C-string to this one and return the result
return MyString(data + string(cstr));
}

MyString MyString::append(char ch) const {
// TODO: Append a single character and return the result
return MyString(data + ch);
}

MyString MyString::append(int number) const {
// TODO: Append the string representation of an integer and return the result
// Hint: Use std::to_string()
return MyString(data + to_string(number));
}

// ---- Function Overloading: replace ----
// These two functions demonstrate FUNCTION OVERLOADING:
// Same name "replace", different parameter types.

MyString MyString::replace(char oldCh, char newCh) const {
// TODO: Replace ALL occurrences of oldCh with newCh, return new MyString
string temp = data;
for (char &c : temp) {
if (c == oldCh) c = newCh;
}
return MyString(temp);
}

MyString MyString::replace(const string& oldStr, const string& newStr) const {
// TODO: Replace ALL occurrences of oldStr with newStr, return new MyString
// WARNING: Be careful not to create an infinite loop!
// After each replacement, advance position past the new string.
string temp = data;
size_t pos = 0;

while ((pos = temp.find(oldStr, pos)) != string::npos) {
temp.replace(pos, oldStr.length(), newStr);
pos += newStr.length();
}

return MyString(temp);
}

// ---- Operator Overloading ----

MyString MyString::operator+(const MyString& other) const {
// TODO: Concatenate two MyString objects and return the result
return MyString(data + other.data);
}

bool MyString::operator==(const MyString& other) const {
// TODO: Return true if both MyString objects hold the same string
return data == other.data;
}

bool MyString::operator!=(const MyString& other) const {
// TODO: Return true if the two MyString objects hold different strings
return data != other.data;
}

bool MyString::operator<(const MyString& other) const {
// TODO: Lexicographic less-than comparison
return data < other.data;
}

bool MyString::operator>(const MyString& other) const {
// TODO: Lexicographic greater-than comparison
return data > other.data;
}

char MyString::operator[](int index) const {
// TODO: Return character at index
// Throw std::out_of_range if index is invalid (negative or >= length)
if (index < 0 || index >= data.length())
throw out_of_range("Index out of range");
return data[index];
}

MyString MyString::operator*(int times) const {
// TODO: Repeat the string 'times' times and return the result
// If times <= 0, return empty string
if (times <= 0) return MyString("");

string result;
for (int i = 0; i < times; i++) {
result += data;
}
return MyString(result);
}

// ---- Stream Overloading ----
