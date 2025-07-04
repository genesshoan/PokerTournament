/**
 * @file string.h
 * @author Shoan Genes (shoangenes42@gmail.com)
 * @brief Alternative library for working with strings.
 * @version 1.0
 * @date 2024-10-14
 * 
 * This header provides a set of functions to manage dynamic strings, including creation, destruction, 
 * copying, concatenation, comparison, and more.
 */
#ifndef string_H
#define string_H

#include "boolean.h"

/**
 * @brief Maximum number of characters a string can contain.
 */
const int MAX = 80; 
/**
 * @typedef string
 * @brief Dynamic array of characters.
 */
typedef char * string;

/**
 * @fn strcrear
 * @brief Create an empty string with a NULL character.
 * 
 * This function initializes a single-character string by placing a NULL ('0') character at the beginning.
 * 
 * @param str The string to be initialized. It must be an array of characters (char*).
 */
void strcrear (string &str);

/**
 * @fn strdestruir
 * @brief Destroy a string and set the pointer to NULL.
 * 
 * This function frees up memory from the string and sets the pointer to NULL to prevent memory leaks or 
 * invalid access to an address.
 * 
 * @param str The string to be destroyed. It must be an array of characters (char*).
 */
void strdestruir (string &str);

/**
 * @fn strlar
 * @brief Returns the length of a string.
 * 
 * This function returns the length of a null-terminated character array (string).
 * 
 * @param str The string whose length is to be determined.
 * 
 * @pre \p str must be initialized before calling this function. If the string is not initialized, 
 * the function may access invalid memory addresses and return an incorrect result.
 */

int strlar (string str);

/**
 * @fn strcop
 * @brief Copies a string to another string.
 * 
 * This function copies the second string into the first string.
 * 
 * @param str1 The destination string where the second string will be copied.
 * @param str2 The source string to be copied into the first string.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and copy garbage characters.
 */
void strcop (string &str1, string str2);

/**
 * @fn scan
 * @brief Captures a string from the keyboard.
 * 
 * This function allows the user to input a string and places a NULL character ('\0') at the beginning.
 * 
 * @param str The string where the input will be stored.
 */
void scan (string &str);

/**
 * @fn strcon
 * @brief Concatenates the second string at the end of the first.
 * 
 * This function appends the content of \p str2 to \p str1.
 * 
 * @param str1 The target string where \p str2 will be concatenated at the end.
 * @param str2 The string to be concatenated at the end of \p str1.
 * 
 * @pre Both \p str1 and \p str2 must be initialized to avoid undefined behavior.
 */
void strcon (string &str1, string str2);

/**
 * @brief Swaps the content of two strings.
 * 
 * This function exchanges the content of \p str1 and \p str2.
 * 
 * @param str1 The first string to be swapped.
 * @param str2 The second string to be swapped.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and swap garbage characters.
 */
void strswp (string &str1, string &str2);


/**
 * @fn print
 * @brief Prints a string.
 * 
 * This function outputs the content of the given string to the console.
 * 
 * @param str The string to be printed.
 * 
 * @pre Both @p str must be initialized before calling this function. 
 * If this string are not initialized, the function may access invalid memory addresses 
 * and print garbage characters.
 */
void print (string str);

/**
 * @fn strmen
 * @brief Compares two strings to determine if the first is lexicographically smaller.
 * 
 * This function returns true if \p str1 is lexicographically smaller than \p str2, and false otherwise.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and compare garbage characters.
 * 
 * @return \p true if \p str1 is smaller than \p str2, \p false otherwise.
 */
boolean strmen (string str1, string str2);

/**
 * @fn streq
 * @brief Compares two strings for equality.
 * 
 * This function returns true if \p str1 and \p str2 are equal, and false otherwise.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and compare garbage characters.
 * 
 * @return \p true if \p str1 is equal to \p str2, \p false otherwise.
 */
boolean streq (string str1, string str2);

void Bajar_String (string s, FILE * f);
// Escribe en el archivo los caracteres del string s (incluido '\0') 
// Precondición: El archivo viene abierto para escritura. 

void Levantar_String (string &s, FILE * f); 
// Lee desde el archivo los caracteres del string s. 
// Precondición: El archivo viene abierto para lectura.

void ClearBuffer();
// Limpia el Buffer 

#endif